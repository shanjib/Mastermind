/*mastermind header file
 declaration of mastermind class
 Istiaque Shanjib*/
#pragma once

#ifndef MASTERMIND_H
#define MASTERMIND_H

#include "response.h"       //include necessary headers
#include "code.h"

class mastermind
{
private:                    //member data
    code secret, guess;     //code objects
    vector<code> guesses, prevguess;
    vector<response> prevres;
    response digits;
public:
    void humanGuess(code &guess);
    void humanGuess2(code &guess);
    void agentGuess(code &guess);
    void getResponse(code &guess, code &secret, response &digits);
    void getResponse2(code &guess, code &secret);
    void isSolved(response &digits, int &z);
    void isSolved2(response &digits, int &z);
    void playGame();
    void playGame2();
    bool consistent(code &guess);
};

#endif //MASTERMIND_H
