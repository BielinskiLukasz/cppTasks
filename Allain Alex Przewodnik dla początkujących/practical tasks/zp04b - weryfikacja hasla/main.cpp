#include <iostream>
using namespace std;
int main ()
{
    int haslo = 0;
    cout << "Podaj haslo: ";
    cin >> haslo;
    if (haslo == 1234 || haslo == 1111)
    {
        cout << endl << "Poprawne haslo!" << endl;
    }
    else
    {
        cout << endl << "Podano bledne haslo" << endl;
        return 0;
    }
}
