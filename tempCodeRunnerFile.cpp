void menu(int &menu){
    int game_instruction;
    menu =game_instruction;
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
}