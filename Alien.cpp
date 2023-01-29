#include <iostream>
using namespace std;
#include <vector>
#include "board.h"

class alien: public game{
    private:
    vector< vector <char> > map;
    int x, y;
    public:
    alien(int x, int y, char c) : game(x, y , c) {}
    void move(char direction);
    int getX(){ return x;}
    int getY(){ return y;}
};

void alien::move(char direction)
{
    // Find the current position of the alien
    int x, y;
    bool found = false;
    for (int i = 0; i < y && !found; ++i)
    {
        for (int k = 0; k < x && !found; ++k)
        {
            if (map[i][k] == 'A')
            {
                x = i;
                y = k;
                found = true;
            }
        }
    }
    // Update the position of the alien based on the direction
    switch(direction){
        case 'up':
        case 'Up':
            map[x][y] = '.';
            map[x][y+1] = "A";
            break;

        case 'down':
        case 'Down':
            map[x][y] = '.';
            map[x][y-1] = 'A';
            break;

        case 'right':
            map[x][y] = '.';
            map[x+1][y] = 'A';
            break;

        case 'left':
        case 'Left':
            map[x][y] = '.';
            map[x-1][y] = 'A';
            break;

    }
}

