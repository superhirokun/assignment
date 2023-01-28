#include <iostream>
using namespace std;
#include <vector>


class alien:
{
    private:
    vector < vector <char> > map_;
    public:
    int dx, dy, px, py;
    alien(int dx, int dy);
    void pos(int dx, int dy)const;
    void move(int dx, int dy);
    
};

alien::alien(int dx, int dy)
{
    pos(px, py);
}

void pos(int dx, int dy)const
{
    game[]
}
// class alien
// {
//     private:
//     vector < vector <char> > map_;
//     public:
//     int dx,dy;
//     alien(int dx, int dy);
//     void centre(int dx, int dy);
//     void move(int x, int y);
// };

// class alien: public game{
//     private:
//     vector< vector <char> > map;
//     int x, y;
//     public:
//     alien(int x, int y) : game(x, y), x(x), y(y) {}
//     void move(int dx, int dy);
//     int getX(){ return x;}
//     int getY(){ return y;}
// };

// void alien::move(char direction)
// {
//     // Find the current position of the alien
//     int x, y;
//     bool found = false;
//     for (int i = 0; i < y && !found; ++i)
//     {
//         for (int k = 0; k < x && !found; ++k)
//         {
//             if (map[i][k] == 'A')
//             {
//                 x = i;
//                 y = k;
//                 found = true;
//             }
//         }
//     }
//     // Update the position of the alien based on the direction
//     if (direction == 'U')
//     {
//         map[x][y] = '.';
//         map[x-1][y] = 'A';
//     }
//     else if (direction == 'D')
//     {
//         map[x][y] = '.';
//         map[x+1][y] = 'A';
//     }
//     else if (direction == 'L')
//     {
//         map[x][y] = '.';
//         map[x][y-1] = 'A';
//     }
//     else if (direction == 'R')
//     {
//         map[x][y] = '.';
//         map[x][y+1] = 'A';
//     }
// }

