#include"board.h"
using namespace std;

int main()
{
    srand(time(NULL));
    int x, y; char c;
    cout << "PLease entre the row of your selection = " ;
    cin >> x;
    cout << "Please entre the number of colums = ";
    cin >> y;
    if (x % 2 == 0 || y % 2 == 0)
    {
        cout << "Please enter a odd number" << endl;
    }
    else 
    {
        game mygame(x, y);
        mygame.display();

    }
}