#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include"board.h"

class zombies:public game       //don't touch this unless you know what you doing
{
    private:
    vector < vector < vector < int > > > zomb;
    public:
    int hp, attack, range, X, Y, number;
    zombies(){};
    void Stats();
    void zombie_list();
};

zombies::zombies(){};

void zombies::zombie_list()
{
    int num_zombie[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 0; i > number;){

    }
}


void zombies::Stats()
{
    int hp_list[] = {50, 100, 150, 200, 250};
    int attack_list[] = {2, 4, 6, 8};
    int range_list[] = {1, 2, 3, 4};

    int ran_hp = hp_list[rand() % sizeof(hp_list)/sizeof(hp_list[0])];
    int ran_attack = attack_list[rand() % sizeof(attack_list)/sizeof(attack_list[0])];
    int ran_range = range_list[rand() % sizeof(range_list)/sizeof(range_list[0])];

    hp = ran_hp;
    attack = ran_attack;
    range = ran_range;
}