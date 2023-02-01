using namespace std;

class alien: public game{
    private:
    vector< vector <char> > amap;
    int dx, dy;
    public:
    int x , y;
    alien(int x, int y) : game(x, y) {}
    void move(int direction);
    void centre(int x, int y);
};

alien::alien(int x, int y):game(x , y){}

void alien::centre(int x, int y)
{
    dx =x ; dy = y;
    int centreX = x/2;
    int centreY = y/2;
    amap[centreX][centreY] = 'A';
}

void alien::move(int direction)
{
    // Find the current position of the alien
    int x, y;
    bool found = false;
    for (int i = 0; i < y && !found; ++i)
    {
        for (int k = 0; k < x && !found; ++k)
        {
            if (amap[i][k] == 'A')
            {
                x = i;
                y = k;
                found = true;
            }
        }
    }
    //Update the position of the alien based on the direction
    switch(direction){
        case 'U':
            amap[x][y] = '.';
            amap[x][y+1] = 'A';
            break;

        case 'D':
            amap[x][y] = '.';
            amap[x][y-1] = 'A';
            break;

        case 'R':
            amap[x][y] = '.';
            amap[x+1][y] = 'A';
            break;

        case 'L':
            amap[x][y] = '.';
            amap[x-1][y] = 'A';
            break;

    }
}
