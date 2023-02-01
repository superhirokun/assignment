#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main ()
{
    int turn = 0;
    char instruction ;
    int z_h = 100;
    int z_d = 10;
    int a_h = 200;
    int a_d = 20 ;
    cout << "Alien health = " << a_h << endl << "Alien damage = " << a_d << endl ;
    cout << "Zombie health = "<< z_h << endl << "Zombie damage = "<< z_d << endl ;

    do
    {
        if (turn == 0)  //player turn
        {
            cout <<"Instruction(u,d,l,r)= "<< instruction ;
            cin >> instruction ;
            if (instruction == 'u')
            {
                cout<<"move up"<<endl;

            }
            else if (instruction == 'd')
            {
                cout<<"move down"<<endl ;
                
            }
            else if (instruction == 'l')
            {
                cout<<"move left"<<endl ;
              
            }
            else if (instruction == 'r')
            {
                cout<<"move right"<<endl ;
              
            }
            else 
            {
                cout<<"Please enter either u,d,l or r"<<endl ;

            }
            z_h = z_h - a_d ;
            cout <<"Attack zombie"<<endl ;
            cout <<"Zombie health is "<<z_h << endl;
            turn = turn + 1 ;
        }

        if (turn == 1) //zombie turn
        {
            cout<<"Zombie move closer and attack "<<endl;
            a_h = a_h - z_d ;
            cout <<"your health is "<<a_h <<endl;
            turn = turn - 1 ;
        }
    } while (a_h >= 0 && z_h >= 0);

    if (a_h <= 0)
    {
        cout <<"you lose !!!"<< endl ;
    }
    if (z_h <= 0)
    {
        cout <<"you win !!!"<< endl ;
    }
return 0 ;
    
}