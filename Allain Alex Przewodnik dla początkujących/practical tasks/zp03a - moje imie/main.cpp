#include <iostream>
#include <string>
using namespace std;
int main ()
{
    cout << "Podaj swoje imie: ";
    string imie;
    getline (cin, imie, '\n');
    cout << "\nWitaj " << imie << endl;
    return 0;
}
