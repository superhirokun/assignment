// print the content of a text file.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{

    char saveload;
    fstream gamefile;

    cout << "---------------------------" << endl;
    cout << "| save - Save your game to a file   |" << endl;
    cout << "| load - Load your game from a file |" << endl;
    cout << "---------------------------\n"
         << endl;

    cout << "Please enter (S)save or (L)load: ";
    cin >> saveload;
    if (saveload == 'S')
    {
        gamefile.open("Gamingfile1", ios::out);
        if (gamefile.is_open())
        {
            // gamefile << "gameprogress"
            gamefile.close();
        }
    }
    else if (saveload == 'L')
    {
        gamefile.open("Gamingfile1", ios::in);
        if (gamefile.is_open())
        {
            string line;
            while (getline(gamefile, line))
            {
                cout << line << endl;
                gamefile.close();
            }
        }
    }
    else
    {
        cout << "Please enter either S or L ";
    }

    return 0;
}