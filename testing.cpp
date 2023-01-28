#include<iostream>
#include <string>
#include <vector>
#include <cstdlib> 
#include <ctime> 
#include <iomanip> 
using namespace std;


void Stats()
{
    int hp, attack, range, move_tile;
    int hp_list[] = {50, 100, 150, 200, 250};
    int attack_list[] = {2, 4, 6, 8};
    int range_list[] = {1, 2, 3, 4};
    int move_tile_list[] = {1, 2, 3, 4};

    int ran_hp = hp_list[rand() % sizeof(hp_list)/sizeof(int)];
    int ran_attack = attack_list[rand() % sizeof(attack_list)/sizeof(int)];
    int ran_range = range_list[rand() % sizeof(range_list)/sizeof(int)];
    int ran_move_tile = move_tile_list[rand() % sizeof(move_tile_list)/sizeof(int)];

    hp = ran_hp;
    attack = ran_attack;
    range = ran_range;
    move_tile = ran_move_tile;

    cout << "hp : " << hp << " |" << "attack : " << attack << " |" << "range : " << range << " |" << "move_tile : " << move_tile << endl;
}

// void zombies_spawns()
// {
//     int hp, attack, range, move_tile;
//     Stats();
//     int numZ;
//     cout << "How many zombies do you want?: ";
//     cin >> numZ;
//     for(int i=0; i< numZ; i++)
//     {
//         cout << "Z" << " " <<i+1;
//         cout << "hp : " << hp << " |" << "attack : " << attack << " |" << "range : " << range << " |" << "move_tile : " << move_tile << endl;
//     }
// }
// int main()
// {
//     srand(time(NULL));
//     Stats();
//     zombies_spawns();

// }
// void spawnz(int zv)
// {
// int z = zv;
// int totalrow; // these is the number of colum and nunber of row in the board
// int totalcolum;

// while (z > 0)
// {
//     int x = rand() % totalrow;
//     int y = rand() % totalcolum;
//     // map[x][y] = 'z' ;
//     z = z - 1;
// }
// }

// int main()
// {
// int zombie_value;
// cout << "Please enter the zombie value = ";
// cin >> zombie_value;
// spawnz(zombie_value);
// }

class zombie {
    public:
    int x,y;
};

int main(){
    vector<zombie> zombielist;
    int X =5 , Y = 5;
    zombie z1, z2;
    zombielist.push_back(z1);
    zombielist.push_back(z2);
    zombielist[0].x = '1';
    cout << zombielist[0].x ;
}