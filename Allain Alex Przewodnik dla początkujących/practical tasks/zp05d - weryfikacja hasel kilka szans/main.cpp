#include <iostream>
using namespace std;
int main ()
{
    for (int i=0; i<5; i++)
    {
        cout << "Podaj haslo: ";
        int haslo = 0;
        cin >> haslo;
        if (haslo == 1111)
            break;
    }
    return 0;
}
