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
            mygame.init(x,y);
            zombies zomb(number, x,y);
            alien a(x, y);
            zomb.zombie_list(number , x, y);
            a.move(mygame);

        }
    }
}