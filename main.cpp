#include "board.h"
using namespace std;

// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TT7L
// Names: Yap Choo Kath Moon 
// IDs: 1211102270 
// Emails: 1211102270@student.mmu.edu.my
// Phones: 017-2643416
// *********************************************************
int main()
{
    srand(time(NULL));
    int x, y, number, options;
    char in;

    cout << "  ALIEN VS ZOMBIES" << endl;
    cout << "-------------------\n";
    cout << "|(1)Start Game     |\n";
    cout << "|(2)User Manual    |\n";
    cout << "-------------------\n";
    cout << "Insert Input -> ";
    cin >> options;

    if(options == 1){
    cout << "PLease entre the row of your selection = ";
    cin >> x;
    cout << "Please entre the number of colums = ";
    cin >> y;
    cout << "Please entre the number of zombies = ";
    cin >> number;
    if(x > 20 || y > 20)
    {
        cout << "The board was too big\n";
    }
    else if (number > 9) {
        cout << "The number of zombies is too much\n";
    }
    else
    {
        if (x % 2 == 0 || y % 2 == 0)
        {
            cout << "Please enter a odd number\n";
        }
        else 
        {
            game mygame(x, y, number);
            mygame.init(x,y);
            zombies zomb(number, x,y);
            alien a(x, y, number);
            zomb.zombie_list(number , x, y);
            a.zombie(x, y ,number);
            mygame.display();
            do
            {
            int turn = 0;
            switch(turn){
                case 0:
                a.move(mygame);
                turn = turn + 1;
                break;
            }while (turn <= number)
            {
                mygame.Zcheck(turn);
                mygame.InRange();
                turn = turn +1;

            }
            
            } while (mygame.alien_hp > 0);
            if(mygame.alien_hp <= 0){
                cout << "Game Over\n";
            }
            

        }
    }
    }
    else if(options == 2){
        cout << "////////////////" << endl;
        cout << "User Manual " << endl;
        cout << "////////////////\n\n"
            << endl;
        cout << "1) Game movement \n";
        cout << "    move up (U)\n";
        cout << "    move down (D)\n";
        cout << "    move left (L)\n";
        cout << "    move right (R)\n\n";
        cout << "2) Game object \n";
        cout << "    A = alien (the main character the player can control) \n";
        cout << "    1,2,3,4,5,6,7,8,9 = zombie (will try to kill you when you get near to him)\n";
        cout << "    P = pod (will attack the nearest zombie if you get one)\n";
        cout << "    R = rock (it might hide something random beneath it)\n";
        cout << "    H = health (increase your health when you get it)\n";
        cout << "    arrow(<,>,^,v) = fire you toward the direction that the arrow are aiming\n\n";
        cout << "3) How to play \n";
        cout << "    -You have to move around the board in order to collect the pod to kill zombie\n";
        cout << "    -by using arrow you can take more advantage against zombie\n";
        cout << "    -After killing every zombie you win the game\n";
        }
    }