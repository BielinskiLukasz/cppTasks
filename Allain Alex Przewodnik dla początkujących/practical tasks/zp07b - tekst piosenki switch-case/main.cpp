#include <iostream>

using namespace std;

int main ()
{
    for (int i = 1; i <= 3; i++)
    {
        cout << "On the " << i << " day of Christmas" << endl << "my true love sent to me:" << endl;
        switch (i)
            {
                case 3: cout << "Three French Hens" << endl;
                case 2: cout << "Two Turtle Doves" << endl << "and ";
                case 1: cout << "A Partridge in a Pear Tree" << endl << endl;
            }
    }
    return 0;
}
