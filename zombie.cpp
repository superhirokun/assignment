#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include"board.h"

class zombies:public game
{
    public:
    int hp, attack, range, X, Y;
    void Stats();
    void zombies_spawns(int number, int postion);
    zombies(){};
};

void zombies::zombies_spawns(int number, int position)
{
    for (int i = 0; i < number; i++)
    {
        game init(x,y);
        x = rand() % position;
        y = rand() % position;
        
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

int main()
{
    srand(time(NULL));
    int x, y, number, position;
    cout << "PLease entre the row of your selection = " ;
    cin >> x;
    cout << "Please entre the number of colums = ";
    cin >> y;
    cout << "Please entre the number of zombies = ";
    cin >> number;
    if (x % 2 == 0 || y % 2 == 0)
    {
        cout << "Please enter a odd number" << endl;
    }
    else 
    {
        game mygame(x, y);
        mygame.display();
    }
}