#include <iostream>

using namespace std;

int sprawdz_haslo (int haslo)
{
    if (haslo == 1111)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main ()
{
    for (int i=0; i<5; i++)
    {
        cout << "Podaj haslo: ";
        int haslo = 0;
        cin >> haslo;
        if (sprawdz_haslo (haslo) == 1)
        {
            cout << "Witaj";
            break;
        }
        else if (i<3)
            cout << "Pozostalo " << 4-i << " prob" << endl;
        else if (i==3)
            cout << "Pozostala " << 4-i << " proba" << endl;
    }
    return 0;
}
