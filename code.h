/*Code header file
 declaration of code class
 Istiaque Shanjib*/

#pragma once
#ifndef CODE_H
#define CODE_H
#include "response.h"           //include necessary headers
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

class code
{
private:                        //member data
    vector<int> cod;            //code vector
    vector<bool> checked;       //checked vector
public:
    bool checkstat() {return checked[0];};          //returns first checked variable (for consistent check)
    void initSecret();
    void initCheck();
    void changeCheck(int i);
    void checkCorrect(code &guess, response &digits);
    void checkIncorrect(code &guess, response &digits);
    void readCode();
    void writeCode(int x);
    void clear();
    void increment();
    void initprev();
    bool max();
    code &operator=(const code &other);
    friend ostream &operator<<(ostream &output, const code &c)
    {
        output<<"Code: "<<c.cod[0]<<" "<<c.cod[1]<<" "<<c.cod[2]<<" "<<c.cod[3];
        return output;
    };
};

#endif //CODE_H
