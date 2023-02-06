#include "board.h"
#include "zombie.h"
using namespace std;
int main()
{
    srand(time(NULL));
    int x, y, number;
    char in;

    cout << "PLease entre the row of your selection = " << endl;
    cin >> x;
    cout << "Please entre the number of colums = " << endl;
    cin >> y;
    cout << "Please entre the number of zombies = "<< endl;
    cin >> number;
    if(x > 30 || y > 30)
    {
        cout << "The board was too big" << endl;
    }
    else if (number > 9) {
        cout << "The number of zombies is too much" << endl;
    }
    else
    {
        if (x % 2 == 0 || y % 2 == 0)
        {
            cout << "Please enter a odd number" << endl;
        }
        else 
        {
            game mygame(x, y);
            mygame.display();
            zombies myzom;
            myzom.zombie_list();
            alien a;
            a.move(mygame);

        }
    }
}