#include "mastermind.h"         //include mastermind header
#include "response.h"
#include "code.h"
#include <iostream>
using namespace std;

int main()
{
    mastermind game;            //initalize game

    cout<<"Would you like to play as:"<<endl;
    cout<<"1. the Code Breaker"<<endl;
    cout<<"2. the Code Maker"<<endl;
    cout<<"(please input the corresponding number)"<<endl;
    int a;
    cin>>a;

    if (a == 1)
        game.playGame();
    else if (a == 2)
        game.playGame2();
    else
        cout<<"Oh no! That's not an option!"<<endl;
    
    return 0;
}
