#include "board.h"
using namespace std;
int main()
{
    srand(time(NULL));
    int x, y;
    char in;

    cout << "PLease entre the row of your selection = " ;
    cin >> x;
    cout << "Please entre the number of colums = ";
    cin >> y;
    if(x > 30 || y > 30)
    {
        cout << "The board was too big" << endl;
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
            alien a;
            a.move(mygame);

        }
    }
}