
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

class Mars 
{
private:
    vector< vector<char> > map_;
    int dimX_, dimY_;

public:
    Mars(int dimX=15, int dimY=5);
    void init(int dimX, int dimY);
    void display() const;

    int getDimX() const;
    int getDimY() const;

    char getObject(int x, int y) const;
    char setObject(int x, int y, char ch);

    bool isEmpty(int x, int y);
    bool isMoney(int x, int y);
    bool isInsideMap(int x, int y);
};

class Rover: public Mars
{
    private:
        int x_, y_;
        char heading_; // either '^', '>', '<' or 'v'
    public:
        Rover(){};
        void land(Mars &mars);
        int getX() const;
        int getY() const;
        char getHeading() const;
        void turnLeft(Mars &mars);
        void turnRight(Mars &mars);
        void move(Mars &mars);
        void autoMove(Mars &mars, Rover &curiosity);
        int getMoney(Mars &mars);
};


int Mars::getDimX() const
{
    return dimX_;
}
int Mars::getDimY() const
{
    return dimY_;
}

Mars::Mars(int dimX, int dimY)
{
    init(dimX, dimY);
}
void Mars::init(int dimX, int dimY)
{
    dimX_ = dimX;
    dimY_ = dimY;
    char objects[] = {' ', ' ', ' ', ' ', ' ', ' ', 'X', '#', '@', '$'};
    int noOfObjects = 10;

    map_.resize(dimY_);
    for (int i = 0; i < dimY_; ++i)
    {
        map_[i].resize(dimX_);
    }

    for (int i = 0; i < dimY_; ++i)
    {
        for (int j = 0; j < dimX_; ++j)
        {
            int objNo = rand() % noOfObjects;
            map_[i][j] = objects[objNo];
        }
    }
}
void Mars::display() const
{
    // comment this out during testing
    // system("clear"); system("cls");
    cout << endl;
    cout << " --__--__--__--__--__--__--__--_" << endl;
    cout << " = Curiosity, Welcome to Mars! =" << endl;
    cout << " __--__--__--__--__--__--__--__-" << endl;
    // for each row
    for (int i = 0; i < dimY_; ++i)
    {
        // display upper border of the row
        cout << " ";
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        // display row number
        cout << setw(2) << (dimY_ - i);
        // display cell content and border of each column
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "|" << map_[i][j];
        }
        cout << "|" << endl;
    }
    // display lower border of the last row
    cout << " ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;
    // display column number
    cout << " ";
    for (int j = 0; j < dimX_; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;
    cout << " ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl
         << endl;
}

char Mars::getObject(int x, int y) const
{
    return map_[dimY_-y][x-1];
}
char Mars::setObject(int x, int y, char ch)
{
    return map_[dimY_-y][x-1] = ch;
}

bool Mars::isEmpty(int x, int y){
    return map_[dimY_-y][x-1] == ' ';
}
bool Mars::isMoney(int x, int y){
    return map_[dimY_-y][x-1] == '$';
}
bool Mars::isInsideMap(int x, int y){
    return x >= 1 && x <= dimX_ && y >= 1 && y <= dimY_;
}

void Rover::land(Mars &mars)
{
    char possibleHeading[] = {'^', '>', '<', 'v'};
    x_ = rand() % mars.getDimX() + 1;
    y_ = rand() % mars.getDimY() + 1;
    heading_ = possibleHeading[rand() % 4];
    mars.setObject(x_, y_, heading_);
}

void Rover::turnLeft(Mars &mars){
    // char possibleHeading[] = {'^', '>', '<', 'v'};
    mars.setObject(x_, y_, heading_);
    if (heading_ == '^'){
        heading_ = '<';
        mars.setObject(x_, y_, heading_);
    }
    else if (heading_ == '<'){
        heading_ = 'v';
        mars.setObject(x_, y_, heading_);
    }
    else if (heading_ == '>'){
        heading_ = '^';
        mars.setObject(x_, y_, heading_);
    }
    else if (heading_ == 'v'){
        heading_ = '>';
        mars.setObject(x_, y_, heading_);
    }
}

void Rover::turnRight(Mars &mars){
    if (heading_ == '^'){
        heading_ = '>';
        mars.setObject(x_, y_, heading_);
    }
    else if (heading_ == '<'){
        heading_ = '^';
        mars.setObject(x_, y_, heading_);
    }
    else if (heading_ == 'v'){
        heading_ = '<';
        mars.setObject(x_, y_, heading_);
    }
    else if (heading_ == '>'){
        heading_ = 'v';
        mars.setObject(x_, y_, heading_);
    }
}

void Rover::move(Mars &mars){
    
    if (heading_ == '^'){
        if (y_ != 5){
            if (mars.isEmpty(x_, y_+1) || mars.isMoney(x_, y_+1)){
                y_++;
                mars.setObject(x_, y_, heading_);
                mars.setObject(x_, y_-1, ' ');
            }
        }
    }
    if (heading_ == 'v'){
        if (y_ != 1){
            if (mars.isEmpty(x_, y_-1) || mars.isMoney(x_, y_-1)){
                y_--;
                mars.setObject(x_, y_, heading_);
                mars.setObject(x_, y_+1, ' ');
            }
        } 
    }
    if (heading_ == '<'){
        if ((mars.isEmpty(x_-1, y_) || mars.isMoney(x_-1, y_)) && mars.isInsideMap(x_-1, y_)){
            x_--;
            mars.setObject(x_, y_, heading_);
            mars.setObject(x_+1, y_, ' ');
        }
    }
    if (heading_ == '>'){
        if ((mars.isEmpty(x_+1, y_) || mars.isMoney(x_+1, y_)) && mars.isInsideMap(x_+1, y_)){
            x_++;
            mars.setObject(x_, y_, heading_);
            mars.setObject(x_-1, y_, ' ');
        }
    }
}

int Rover::getMoney(Mars &mars){

    int money=0;

    if (heading_ == '^'){
        if (y_ != 5){
            if (mars.isEmpty(x_, y_+1) || mars.isMoney(x_, y_+1)){
                if (mars.isMoney(x_, y_+1)){
                    money++;
                }
            }
        }
    }
    else if (heading_ == 'v'){
        if (y_ != 1){
            if (mars.isEmpty(x_, y_-1) || mars.isMoney(x_, y_-1)){
                if (mars.isMoney(x_, y_-1)){
                    money++;
                }
            }
        } 
    }
    else if (heading_ == '<'){
        if ((mars.isEmpty(x_-1, y_) || mars.isMoney(x_-1, y_)) && mars.isInsideMap(x_-1, y_)){
            if (mars.isMoney(x_-1, y_)){
                    money++;
                }
        }
    }
    else if (heading_ == '>'){
        if ((mars.isEmpty(x_+1, y_) || mars.isMoney(x_+1, y_)) && mars.isInsideMap(x_+1, y_)){
            if (mars.isMoney(x_+1, y_)){
                    money++;
                }
        }
    }
    return money;
}

int Rover::getX() const
{
    return x_;
}

int Rover::getY() const
{
    return y_;
}
char Rover::getHeading() const
{
    return heading_;
}


//}


void test1_1()
{
    Mars mars;
    mars.display();
}

void test1_3()
{
    Mars mars;
    mars.display();
    cout << "Dim X = " << mars.getDimX() << endl;
    cout << "Dim Y = " << mars.getDimY() << endl;
}

void test1_4()
{
    Mars mars;
    mars.display();
    int x, y;
    char obj;
    x = 1; y = 1;
    obj = mars.getObject(x, y);
    cout << "Object at column " << x << " and row " << y << " is [" << obj << "]" << endl;
    x = 15; y = 2;
    obj = mars.getObject(x, y);
    cout << "Object at column " << x << " and row " << y << " is [" << obj << "]" << endl;
    x = 5; y = 5;
    obj = mars.getObject(x, y);
    cout << "Object at column " << x << " and row " << y << " is [" << obj << "]" << endl;
    x = 10; y = 2;
    obj = mars.getObject(x, y);
    cout << "Object at column " << x << " and row " << y << " is [" << obj << "]" << endl;
}

void test1_5()
{
    Mars mars;
    int x1 = 1, y1 = 1; char ch1 = 'A';
    int x2 = 15, y2 = 1; char ch2 = 'B';
    int x3 = 15, y3 = 5; char ch3 = 'C';
    int x4 = 1, y4 = 5; char ch4 = 'D';
    int x5 = 7, y5 = 3; char ch5 = 'E';
    mars.setObject(x1, y1, ch1);
    mars.setObject(x2, y2, ch2);
    mars.setObject(x3, y3, ch3);
    mars.setObject(x4, y4, ch4);
    mars.setObject(x5, y5, ch5);
    mars.display();
    cout << "The object " << ch1 << " should be at column "
    << x1 << " and row " << y1 << endl;
    cout << "The object " << ch2 << " should be at column "
    << x2 << " and row " << y2 << endl;
    cout << "The object " << ch3 << " should be at column "
    << x3 << " and row " << y3 << endl;
    cout << "The object " << ch4 << " should be at column "
    << x4 << " and row " << y4 << endl;
    cout << "The object " << ch5 << " should be at column "
    << x5 << " and row " << y5 << endl;
}

void test1_6()
{
    Mars mars;
    int x1 = 2, y1 = 4;
    int x2 = 10, y2 = 3;
    mars.display();
    cout << boolalpha;
    cout << "Is (" << x1 << ", " << y1 << ") empty? Answer = " << mars.isEmpty(x1, y1) << endl;
    cout << "Is (" << x2 << ", " << y2 << ") empty? Answer = " << mars.isEmpty(x2, y2) << endl;
    int x3 = 15, y3 = 5;
    int x4 = 10, y4 = 1;
    cout << "Is (" << x3 << ", " << y3 << ") inside map? Answer = " << mars.isInsideMap(x3, 0) << endl;
    cout << "Is (" << x4 << ", " << y4 << ") inside map? Answer = " << mars.isInsideMap(x4, 0) << endl;
}

void test2_1()
{
    Mars mars;
    Rover curiosity;
    curiosity.land(mars);
    mars.display();
    cout << "Status of the rover:" << endl
    << " Location: (" << curiosity.getX() << ", " << curiosity.getY() << ")" << endl << " Heading: " << curiosity.getHeading() << endl;
}

void test2_2()
{
    Mars mars;
    Rover curiosity;

    curiosity.land(mars);
    mars.display();
    system("read -n 1 -s -p \"Press any key to continue...\"");

    curiosity.turnRight(mars);
    mars.display();
    system("read -n 1 -s -p \"Press any key to continue...\"");

    curiosity.move(mars);
    mars.display();
    system("read -n 1 -s -p \"Press any key to continue...\"");

    curiosity.move(mars);
    mars.display();
    system("read -n 1 -s -p \"Press any key to continue...\"");
    
    curiosity.move(mars);
    mars.display();
    system("read -n 1 -s -p \"Press any key to continue...\"");

    curiosity.move(mars);
    mars.display();
    system("read -n 1 -s -p \"Press any key to continue...\"");

    curiosity.move(mars);
    mars.display();
    system("read -n 1 -s -p \"Press any key to continue...\"");

    curiosity.move(mars);
    mars.display();
    system("read -n 1 -s -p \"Press any key to continue...\"");

}

void test2_3(){

    Mars mars;
    Rover curiosity;

    curiosity.autoMove(mars, curiosity);
    mars.display();
}

void test2_4(){

    Mars mars;
    Rover curiosity;

    int collected = 0;

    curiosity.land(mars);
    mars.display();

    string command;
    cout << "Enter moves: ";
    cin >> command;

    for (int i=0; i<command.length(); i++){
        mars.display();
        // system("read -n 1 -s -p \"Press any key to continue...\""); system("pause");
        if (command.at(i) == 'M'){
            curiosity.move(mars);
            cout << curiosity.getX() << "  " << curiosity.getY() << endl;
        }
        if (command.at(i) == 'L'){
            curiosity.turnLeft(mars);
        }
        if (command.at(i) == 'R'){
            curiosity.turnRight(mars);
        }
       // if (command.at(i) == 'A'){
       //     curiosity.autoMove(mars, curiosity);
      //  }
        collected += curiosity.getMoney(mars);
    }
    mars.display();
    cout << endl << "$ Collected: " << collected << endl;
}
int main()
{
    srand(time(NULL));
    test2_4();
    cout << endl;
}