/*code implementation
 member functions for code class
 Istiaque Shanjib*/

#include "code.h"               //include code header
using namespace std;

void code::clear()              //function to clear the vector for a new guess
{
    cod.clear();
}

void code::initprev()           //function to init a code to zeros
{
    for(int i=0; i<4; i++)
        cod.push_back(0);
}

void code::checkCorrect(code &guess, response &digits)      //function to check for correct guesses
{
    for (int i=0; i<4; i++)                 //for loop to check
    {
        if (cod[i] == guess.cod[i])         //if number and location are the same
        {
            guess.changeCheck(i);           //change the checked variable for guess
            changeCheck(i);                 //change the checked variable for secret
            digits.addcorrect();            //increment first response digit
        }
    }
}

void code::checkIncorrect(code &guess, response &digits)    //function to check for guess in wrong location
{
    for (int i=0; i<4; i++)                 //for loop to check
    {
        for (int j=0; j<4; j++)             //nested loop to compare all of guess to one part of secret
        {
            //if guess == secret and both haven't been checked yet
            if (cod[i] == guess.cod[j] && guess.checked[j] == false && checked[i] == false)
            {
                digits.addincorrect();      //increment second response digit
                guess.changeCheck(j);       //change checked variable for guess
                changeCheck(i);             //change checked variable for secret
            }
        }
    }
}


void code::changeCheck(int i)               //function to change checked variable
{
    checked[i].flip();
}

void code::readCode()                       //function to print out code
{
    cout<<"\n";
    for (int y=0; y<4; y++)                 //for loop to print all numbers
    {
        cout<<cod[y]<<" ";
    }
    cout<<"\n";
}

void code::initCheck()                      //function to initialize the checked variable
{
    bool x = false;                         //set initializtion variable
    checked.clear();                        //clear checked variable
    checked.resize(4);                      //resize it
    for(int y=0; y<4; y++)
    {
        checked.push_back(x);               //push false onto the checked variable
    }
}


void code::initSecret()                     //functin to initialize the secret code
{
    int x;                                  //initialize random variable
    srand((int)time(NULL));                 //randomize
    for(int i=0;i<4;i++)
    {
        x = rand() % 6;                     //create random variable
        cod.push_back(x);                   //push random variable onto code
    }
}


void code::writeCode(int x)                 //function to write a variable onto the code
{
    cod.push_back(x);
}

code &code::operator=(const code &other)    //assignment operator overloaded for code
{
    for(int i=0; i<4; i++)
        cod[i] = other.cod[i];
    return *this;
}

void code::increment()                      //function to increment through the code
{
    if (max() == true)                      //if the code is at max, reset it
    {
        cod.clear();
        initprev();
    }
    else                                    //code not at max, increment
    {
        cod[3]++;                           //increment
        if (cod[3] == 6)                    //if goes past max
        {
            cod[3] = 0;                     //reset digit
            cod[2]++;                       //increment next
            if (cod[2] == 6)                //repeat for rest of code
            {
                cod[2] = 0;
                cod[1]++;
                if (cod[1] == 6)
                {
                    cod[1] = 0;
                    cod[0]++;
                }
            }
        }
    }
}

bool code::max()                            //function to check if code is at max
{
    if (cod[0] == 5 && cod[1] == 5 && cod[2] == 5 && cod[3] == 5)
        return true;
    else
        return false;
}