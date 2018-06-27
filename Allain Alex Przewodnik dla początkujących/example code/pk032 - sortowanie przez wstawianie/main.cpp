#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void wyswietl_tablice(int tablica [], int rozmiar);
void sortuj (int tablica [], int rozmiar);
int znajdz_najmniejszy_pozostaly_element (int tablica [], int rozmiar, int indeks);
void zamien (int tablica [], int pierwszy_indeks, int drugi_indeks);

int main()
{
    int tablica [10];
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        tablica [i] = rand () % 100 + 1;
    }
    cout << "Tablica wyjsciowa: ";
    wyswietl_tablice (tablica, 10);
    cout << endl;
    sortuj (tablica, 10);
    cout << "Tablica posortowana: ";
    wyswietl_tablice (tablica, 10);
    cout << endl;
    return 0;
}

void wyswietl_tablice (int tablica [], int rozmiar)
{
    cout << "{";
    for (int i = 0; i < rozmiar; i++)
    {
        if (i != 0)
        {
            cout << ", ";
        }
        cout << tablica [i];
    }
    cout << "}";
}

void sortuj (int tablica [], int rozmiar)
{
    for (int i = 0; i < rozmiar; i++)
    {
        int indeks = znajdz_najmniejszy_pozostaly_element (tablica, rozmiar, i);
        zamien (tablica, i, indeks);
    }
}

int znajdz_najmniejszy_pozostaly_element (int tablica [], int rozmiar, int indeks)
{
    int indeks_najmniejszej_wartosci = indeks;
    for (int i = indeks + 1; i < rozmiar; i++)
    {
        if (tablica [i] < tablica [indeks_najmniejszej_wartosci])
        {
            indeks_najmniejszej_wartosci = i;
        }
    }
    return indeks_najmniejszej_wartosci;
}

void zamien (int tablica [], int pierwszy_indeks, int drugi_indeks)
{
    int tymczasowa = tablica [pierwszy_indeks];
    tablica [pierwszy_indeks] = tablica [drugi_indeks];
    tablica [drugi_indeks] = tymczasowa;
}
