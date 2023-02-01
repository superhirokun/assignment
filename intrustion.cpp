#include <iostream>
using namespace std;

void setting()
{
    int zombie_value;
    int total_colums;
    int total_rows;
    cout << "Please enter the zombie value = ";
    cin >> zombie_value;
    cout << "Please enter the colums you want in board (Must be in odd number) = ";
    cin >> total_colums;
    cout << "Please enter the rows in the board (Must be in odd number)= ";
    cin >> total_rows;
    if (total_colums % 2 == 0 || total_rows % 2 == 0)
    {
        cout << "Please enter a odd number" << endl;
    }
}

void start_game()
{
    // game mygame(x, y);
    // mygame.display();
}

void guide()
{
    cout << "////////////////" << endl;
    cout << "The instruction " << endl;
    cout << "////////////////\n\n"
         << endl;
    cout << "1) Game movement \n";
    cout << "    move up (U)\n";
    cout << "    move down (D)\n";
    cout << "    move left (L)\n";
    cout << "    move right (R)\n\n";
    cout << "2) Game object \n";
    cout << "    a = alien (the main character the player can control) \n";
    cout << "    z = zombie (will try to kill you when you get near to him)\n";
    cout << "    p = pod (will attack the nearest zombie if you get one)\n";
    cout << "    r = rock (it might hide something random beneath it)\n";
    cout << "    h = health (increase your health when you get it)\n";
    cout << "    arrow(<,>,^,v) = fire you toward the direction that the arrow are aiming\n\n";
    cout << "3) How to play \n";
    cout << "    -You have to move around the board in order to collect the pod to kill zombie\n";
    cout << "    -by using arrow you can take more advantage against zombie\n";
    cout << "    -After killing every zombie you win the game\n";
}

int main()
{
    int game_instruction;
    cout << "Press(1) :"<< endl << "to start the game "<< endl << "Press(2) :" << endl << "to set the game settings"<< endl << "Press(3):" << "to view the guide for the game";
    cin >> game_instruction;

    if (game_instruction == 1)
    {
        start_game();
    }
    else if (game_instruction == 2)
    {
        setting();
    }
    else if (game_instruction == 3)
    {
        guide();
    }
    else
    {
        cout << "Please enter a 1,2 and 3" << endl;
    }
    return 0;
}


