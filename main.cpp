#include "board.h"
using namespace std;


int main()
{
    srand(time(NULL));
    int x, y, number;
    char in;

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
            
            } while (mygame.alien_hp >= 0);
            

        }
    }
}