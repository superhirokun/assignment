#include <iostream>
#include <cstdlib>
using namespace std;


void increase_hp()
{
    //if(//map[x][y] == 'H')
    {
        // alien_hp = alien_hp + heal
    }
}

void Health_location()
{
    //srand(time(NULL));
    // int x = rand() % totalrow;
    // int y = rand() % totalcolum;
    // map[x][y] = 'H' ;
    increase_hp ();
}

int main()
{
    srand(time(NULL));
    int healthpack;
    int heal = 30 ;
    healthpack = 3 + (rand() % 6);
    cout << healthpack;
    Health_location();
}
