#include <vector>
#include <iostream>
using namespace std;

class alien:public game{
    private:
    vector < vector < char > > map;
    int dx ,dy;
    public:
    int x;
    int y;
    alien(int x, int y);
    void direction(char direction);
    void centre(int x, int y);
};

alien::alien(int x, int y): game(x,y){
    
}

void alien::centre(int x, int y)
{
    dx = x; dy = y; 
    int centreX = x/2;
    int centreY = y/2;
    map[centreX][centreY] = 'A';
}

void alien::direction(char direction)
{
    int x,y;
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
    switch(direction){
        case 'U':
            map[x][y] = '.';
            map[x][y+1] = 'A';
            break;

        case 'D':
            map[x][y] = '.';
            map[x][y-1] = 'A';
            break;

        case 'R':
            map[x][y] = '.';
            map[x+1][y] = 'A';
            break;

        case 'L':
            map[x][y] = '.';
            map[x-1][y] = 'A';
            break;

    }
}