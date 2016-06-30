/*response header file
 declaration of response class
 Istiaque Shanjib*/

#pragma once
#ifndef RESPONSE_H
#define RESPONSE_H
#include <iostream>
using namespace std;

class response
{
private:            //member data
    int r1, r2;     //response digits
public:
    void clear();
    void addcorrect();
    void addincorrect();
    void printres();
    int res();
    int res2();
    bool operator==(response& other);
    response operator=(response& other);
    friend ostream &operator<<(ostream &output, const response &r)
    {
        output<<"Response: ("<<r.r1<<","<<r.r2<<") \n";
        return output;
    };
};

#endif // RESPONSE_H
