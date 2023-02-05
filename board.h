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
        game(int x=1, int y=1);

        int getdimX() const;
        int getdimY() const;
        int get_x()const;
        int get_y()const;

        char trail() ;
        char moveup();
        char movedown();
        char moveright();
        char moveleft();

        void init(int x, int y);
        void display()const;
        void update_cell(int x, int y, char val);
        void position(int &x, int &y);
};

class alien: public game
{
    public:
        int x, y;
        alien();
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

int game::get_x() const
{
    return x;
}
int game::get_y() const
{
    return y;
}

void game::position(int &x, int &y)
{
    x = dimX;
    y = dimY;
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
}
// char game::trail()
// {
//     position(x,y);
//     update_cell(x, y, '.');
//     return 0;
// }

char game::moveup(){
    position(x,y);
    update_cell(x, y, '.');
    update_cell(--x, y, 'A');
    return 0;
}
char game::movedown(){
    position(x,y);
    update_cell(x, y, '.');
    update_cell(++x, y, 'A');
    return 0;
}
char game::moveright(){
    position(x,y);
    update_cell(x, y, '.');
    update_cell(x, y+1, 'A');
    return 0;
}
char game::moveleft(){
    position(x,y);
    update_cell(x, y, '.');
    update_cell(x, y-1, 'A');
    return 0;
}

game::game(int x, int y)
{
    init(x, y);
}

alien::alien()
{
    x = game::get_x();
    y = game::get_y();
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
    update_cell(centreX, centreY, 'A');
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

int alien::getX()const{
    return x;
}

int alien::getY()const{
    return y;
}


void alien::move(game &game) {
    char move;
    cout << "Enter move (U/D/L/R): ";
    cin >> move;
    switch (move) {
        case 'u':
        case 'U':
            game.moveup();
            //game.trail();
            game.display();
            break;
        case 'd':
        case 'D':
            game.movedown();
            //game.trail();
            game.display();
            break;
        case 'l':
        case 'L':
            game.moveleft();
            //game.trail();
            game.display();
            break;
        case 'r':
        case 'R':
            game.moveright();
            //game.trail();
            game.display();
            break;
        default:
            cout << "Invalid move." << endl;
            break;
    }
}