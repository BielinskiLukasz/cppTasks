#include <iostream>
using namespace std;
int f ()
{
    for (int i=99; i>1 ; i--)
    {
        cout << i << " bottles of beer on the wall, " << i << " bottles fo beer. Take one down and pass it around - " << i-1 << " bottles of beer on the wall." << endl;
    }
    cout << "1 bottle of beer on the wall, 1 bottle of beer. Take it down and pass it around - no more bottles of beer on the wall." << endl;
    return 0;
}

int w ()
{
    int i=100;
    while (i>1)
    {
        cout << i << " bottles of beer on the wall, " << i << " bottles fo beer. Take one down and pass it around - " << i-1 << " bottles of beer on the wall." << endl;
        i--;
    }
    cout << "1 bottle of beer on the wall, 1 bottle of beer. Take it down and pass it around - no more bottles of beer on the wall." << endl;
    return 0;
}

int main ()
{
    int i=100;
    do
    {
        cout << i << " bottles of beer on the wall, " << i << " bottles fo beer. Take one down and pass it around - " << i-1 << " bottles of beer on the wall." << endl;
        i--;
    } while (i>1);
    cout << "1 bottle of beer on the wall, 1 bottle of beer. Take it down and pass it around - no more bottles of beer on the wall." << endl;
    return 0;
}
