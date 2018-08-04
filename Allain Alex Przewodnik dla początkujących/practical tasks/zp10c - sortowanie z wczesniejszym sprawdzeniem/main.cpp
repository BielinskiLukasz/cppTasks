#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int sprawdz_czy_posortowana (int tablica [], int rozmiar);
void wyswietl_tablice (int tablica [], int rozmiar);

int main()
{
    srand (time(NULL));
    int rozmiar = 10;
    int tablica [rozmiar];
    for (int i = 0; i < rozmiar; i++)
    {
        tablica [i] = rand () % 100 + 1;
    }
    cout << "Wylosowana tablica:" << endl;
    wyswietl_tablice (tablica, rozmiar);
    sprawdz_czy_posortowana (tablica, rozmiar);

    return 0;
}

int sprawdz_czy_posortowana (int tablica [], int rozmiar)
{
    for (int i = 0; i < rozmiar; i++)
    {
        if (tablica [i] > tablica [i + 1])
        {
            return 1;
        }
    }
    cout << "Tablica jest posortowana" << endl;
    return 1;
}

void wyswietl_tablice (int tablica [], int rozmiar)
{
    cout << "{";
    for (int i = 0; i < rozmiar; i++)
    {
        cout << tablica [i];
        if (i != rozmiar - 1)
        {
            cout << ",\t";
        }
    }
    cout << "}" << endl;
}
