#include<iostream>
#include <string>
#include <vector>
#include <cstdlib> 
#include <ctime> 
#include <iomanip>
using namespace std;

class game
{
    private:
        int dimX , dimY ;
        vector< vector <char> > map; 
    public:
        int x, y;
        game(int x, int y);

        int getdimX() const;
        int getdimY() const;

        char trail(int x, int y) const;
        char moveup(int x, int y)const;
        char movedown(int x, int y)const;
        char moveright(int x, int y)const;
        char moveleft(int x, int y)const;

        void init(int x, int y);
        void display()const;
        void update_cell(int x, int y, char val);
};

class alien: public game
{
    private:
        int X, Y;
        char in;
    public:
        alien(): game(x,y){};
        int getX() const;
        int getY() const;
        void move(game &game);
};

int game::getdimX() const
{
    return dimX;
}
int game::getdimY() const
{
    return dimY;
}

char game::trail(int x, int y)const{
    return map[x][y] == '.';
}

char game::moveup(int x, int y)const{
    return map[x+1][y] == 'A';
}
char game::movedown(int x, int y)const{
    return map[x-1][y] == 'A';
}
char game::moveright(int x, int y)const{
    return map[x][y+1] == 'A';
}
char game::moveleft(int x, int y)const{
    return map[x][y-1] == 'A';
}

game::game(int x, int y)
{
    init(x, y);
}

void game::init(int x, int y)
{
    dimX = x; dimY = y;
    vector <char> obj= {' ', ' ', ' ', ' ', ' ', ' ', 'R', 'P', '<', '>', '^', 'v', 'H'}; //non-interative object
    int num_obj = 13;
    map.resize(dimY);
    for (int i = 0; i < dimY; ++i)
    {
        map[i].resize(dimX);
    }
    for (int i = 0; i < dimY; ++i)
    {
        for (int k = 0; k < dimX; ++k)  //randomize purpose
        {
            int obj_no = rand() % num_obj;
            map[i][k] = obj[obj_no];
        }
    }
    int centreX = dimX/2;
    int centreY = dimY/2;
    map[centreX][centreY] = 'A';
}

void game::update_cell(int x, int y, char val){
    map[x][y] = val;
}


void game::display()const
{
    
    for (int i= 0; i < dimY; ++i)
    { 
        cout << " ";   
        for (int k = 0; k < dimX ; ++k)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        cout << setw(2) << (dimY - i);
        for (int k = 0; k < dimX; ++k)
        {
            cout << "|" << map[i][k];
        }
        cout << "|" << endl;
    }
    cout << "  ";
    for (int k = 0; k < dimX; ++k)
    {
        cout << "+-";
    }
    cout << "+" << endl;
    cout << " ";
    for(int k = 0; k < dimX; ++k) //number on the gameboard
    {
        int num = (k + 1) / 10;
        cout << " ";
        if (num == 0)
            cout << " ";
        else
            cout << num;
    }
    cout << endl;
    cout << " ";
    for (int k = 0; k < dimX; ++k)
    {
        cout << " " << (k + 1) % 10;
    }
    cout << endl << endl;
}

void alien::move(game &game)
{
    if (in == 'U' || in == 'u'){
        trail(x,y);
        moveup(x,y);
    }
    else if (in == 'D' || in =='d')
    {
        trail(x,y);
        movedown(x,y);
    }
    else if (in == 'R' || in == 'r')
    {
        trail(x,y);
        moveright(x,y);
    }
    else if (in == 'L' || in == 'l')
    {
        trail(x,y);
        moveleft(x,y);
    }
    
}