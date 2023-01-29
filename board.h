#include <iostream>
#include <iomanip>
using namespace std;
class game
{
    private:
    int dimX , dimY ;
    vector< vector <char> > map; 
    public:
    int x, y;
    game(int x, int y, char c);
    void init(int x, int y);
    void display()const;
    void update_cell(int x, int y, char c);
};


game::game(int x, int y, char c)
{
    init(x, y);
    //update_cell(x , y , c);
}

//update the board from another header files
void game::update_cell(int x, int y, char c) 
{
    map[y][x] = c;
    c = 'A';
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
    int centerX = dimX / 2;
    int centerY = dimY / 2;
    map[centerX][centerY] = 'A';
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