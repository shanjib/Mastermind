/*response implementation
 member functions for response class
 Istiaque Shanjib*/

#include "response.h"           //include necessary headers
#include <iostream>
using namespace std;

void response::clear()          //function to clear response digits
{
    r1=0;
    r2=0;
}

void response::addcorrect()     //function to increment first digit
{
    r1++;
};

void response::addincorrect()   //function to increment second digit
{
    r2++;
};

void response::printres()       //function to print response
{
    cout<<"Response: ("<<r1<<","<<r2<<")"<<endl;
};

int response::res()             //function to return first digit to check if won
{
    return r1;
}

int response::res2()
{
    return r2;
}

bool response::operator==(response& other)          //overload comparator operator for responses
{
    if (r1 == other.res() && r2 == other.res2())
        return true;
    else
        return false;
}

response response::operator=(response &other)       //overloaded assignment operator for responses
{
    r1 = other.r1;
    r2 = other.r2;
    return *this;
}

