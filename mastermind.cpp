/*mastermind implementation
 member functions for mastermind class
 Istiaque Shanjib*/

#include "mastermind.h"                     //include mastermind header
using namespace std;

void mastermind::playGame()                 //function to play game
{
    code secret, guess;                     //initalize necessary objects
    response digits;
    int z;
    
    cout<<"Welcome to Mastermind!"<<endl;
    secret.initSecret();                    //initialize secret code
    //cout<<"The secret code is:";
    //secret.readCode();                      //print out secret code for testing purposes
    
    for(z=0; z<10; z++)                     //loop for 10 turns
    {
        humanGuess(guess);                  //input human guess
        guess.initCheck();                  //initialize checked variable for guess
        secret.initCheck();                 //initialize checked variable for secret
        guess.readCode();                   //print out guess code
        getResponse(guess, secret, digits);  //get response
        isSolved(digits, z);                //check if code is solved
    }
    if (z < 20)                             //if turns are over print out loss
    {
        cout<<"You lose!"<<endl;
        cout<<"The correct answer was:"<<endl;
        secret.readCode();
    }
}

void mastermind::isSolved(response &digits, int &z)     //function to check if solved
{
    if (digits.res() == 4)                  //if first response is 4
    {
        cout<<"You've won!"<<endl;          //print win
        z = 20;                             //end loop
    }
}

void mastermind::isSolved2(response &digits, int &z)     //function to check if solved
{
    if (digits.res() == 4)                  //if first response is 4
    {
        cout<<"The computer has won!"<<endl;          //print win
        z = 20;                             //end loop
    }
}


void mastermind::humanGuess(code &guess)    //function to input human guess
{
    guess.clear();                          //clear guess code
    cout<<"Please input your guess! (Press enter after each number)"<<endl;
    cout<<"Please only numbers between 0 and 5"<<endl;
    int x; 
    for(int y=0; y<4; y++)
    {
	while (true)
	{
	    cin>>x;
	    if ( x > 5 || x < 0)
	        cout<<"Sorry, invalid number! Try again!"<<endl;
	    else
	        break;
	}
        guess.writeCode(x);                 //push guess onto code
    }
}

void mastermind::humanGuess2(code &guess)    //function to input human guess
{
    guess.clear();                          //clear guess code
    cout<<"Please input your secret code! (Press enter after each number)"<<endl;
    cout<<"Please only numbers between 0 and 5"<<endl;
    int x; 
    for(int y=0; y<4; y++)
    {
	while (true)
	{
	    cin>>x;
	    if ( x > 5 || x < 0)
	        cout<<"Sorry, invalid number! Try again!"<<endl;
	    else
	        break;
	}
        guess.writeCode(x);                 //push guess onto code
    }
    cout<<"Your secret code is !";
    guess.readCode();
}

void mastermind::getResponse(code &guess, code &secret, response &digits)   //function to get response
{
    digits.clear();                         //clear digits
    secret.checkCorrect(guess, digits);     //check for guesses in the correct location
    secret.checkIncorrect(guess, digits);   //check for guesses in the incorrect location
    digits.printres();                      //print response
}

void mastermind::getResponse2(code &guess, code &secret)   //function to get response
{
    digits.clear();                         //clear digits
    guess.initCheck();
    secret.initCheck();
    secret.checkCorrect(guess, digits);     //check for guesses in the correct location
    secret.checkIncorrect(guess, digits);   //check for guesses in the incorrect location
}

bool mastermind::consistent(code &guess)                  //function to check if consistent
{
    bool r = true;                          //declare and initialize boolean
    int x;                                  //declare and initialize int for loop
    x = (int)prevguess.size();
    for (int i=0; i<x; i++)                 //loop through all previous guesses
    {
        getResponse2(prevguess[i], guess);   //get response of prev guesses with guess as secret code
        r = r && (digits == prevres[i]);
    }
    return r;
}

void mastermind::agentGuess(code &guess)                //function to make computer guess
{
    bool t;                                             //declare necessary variables
    int x;
    x = (int)guesses.size();                            //initialize variable for loop to size of vector
    
    for (int i=0; i<x; i++)                             //loop
    {
        t = consistent(guesses[i]);                     //check if potential guess is consistent
        if (!t && guesses[i].checkstat() == false)      //if not consistent and hasn't been checked before
            guesses[i].changeCheck(0);                  //change checked variable
    }
    
    for (int i=0; i<x; i++)                             //loop through after inconsistent has been checked
    {
        if (guesses[i].checkstat() == false)            //assign first consistent to guess
        {
            guess = guesses[i];
            i = 9001;
        }
    }
}

void mastermind::playGame2()                //function to play game in version 2
{
    guess.clear();                          //initialize code objects
    secret.clear();
    
    humanGuess2(secret);                     //use humanguess to input secret code
    cout<<"Secret "<<secret<<endl;
    
    code temp;                              //temp code object for incrementing
    temp.initprev();
    temp.initCheck();
    for (int i=1; i<1296; i++)              //creating data structure of all possible guesses
    {
        guesses.push_back(temp);
        temp.increment();
    }
    
    for (int i=0; i<10; i++)                //loop for 10 turns
    {
        guess.clear();                      //clear guess
        guess.initprev();                   //initalize guess
        agentGuess(guess);                  //get a guess from computer
        cout<<i+1<<". Guess "<<guess<<endl;
        
        getResponse2(guess, secret);         //get a response
        cout<<digits<<endl;
        
        prevres.push_back(digits);          //add response and guess to list of previous
        prevguess.push_back(guess);
        
        isSolved2(digits, i);
    }
}
