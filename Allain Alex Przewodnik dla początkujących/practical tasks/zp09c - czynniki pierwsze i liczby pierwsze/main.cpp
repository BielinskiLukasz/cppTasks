#include <iostream>

using namespace std;

void dzielniki_pierwsze (int liczba);
bool liczby_pierwsze (int liczba_sumy);

int main()
{
    cout << "Liczby spelniajace warunki to:" << endl;
    for (int i = 1; i <= 1000; i++)
    {
        dzielniki_pierwsze (i);
    }
    return 0;
}

void dzielniki_pierwsze (int liczba)
{
    int zmienna = liczba;
    int suma = 0;
    for (int i = 2; zmienna != 1; i++)
    {
        if (zmienna % i == 0)
        {
            suma += i;
            zmienna = zmienna / i;
            i--;
        }
    }
    if (liczby_pierwsze (suma))
    {
        cout << liczba << "\t";
    }
}

bool liczby_pierwsze (int liczba_sumy)
{
    for (int i = 2; i < liczba_sumy; i++)
    {
        if (liczba_sumy % i == 0)
        {
            return false;
        }
    }
    return true;
}
