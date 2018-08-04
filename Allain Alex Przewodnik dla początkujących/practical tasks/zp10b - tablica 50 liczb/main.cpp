#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Napisz program, który wczytuje 50 wartoœci, po czym w osobnych wierszach wypisuje
//wartoœæ najmniejsz¹, najwiêksz¹, œredni¹ oraz ka¿d¹ z wprowadzonych liczb.

int znajdz_najmniejsza (int tablica [], int rozmiar);
int znajdz_najwieksza (int tablica [], int rozmiar);
int znajdz_srednia (int tablica [], int rozmiar);

int main()
{
    srand (time(NULL));
    int tablica_rozmiar = 50;
    int tablica [tablica_rozmiar];
    for (int i = 0; i < tablica_rozmiar; i++)
    {
        tablica [i] = rand () % 1000 + 1;
    }
    int najmniejsza = znajdz_najmniejsza (tablica, tablica_rozmiar);
    int najwieksza = znajdz_najwieksza (tablica, tablica_rozmiar);
    int srednia = znajdz_srednia (tablica, tablica_rozmiar);
    cout << "Najmniejsza wartosc to: " << najmniejsza << endl;
    cout << "Najwieksza wartosc to: " << najwieksza << endl;
    cout << "Srednia wartosc to: " << srednia << endl;
    cout << "Tablica: {";
    for (int i = 0; i < tablica_rozmiar; i++)
    {
        cout << tablica [i];
        if (i != tablica_rozmiar - 1)
        {
            cout << ",\t";
        }
    }
    cout << "}";
    return 0;
}

int znajdz_najmniejsza (int tablica [], int rozmiar)
{
    int indeks_najmniejszej = 0;
    for (int i = 0; i < rozmiar; i++)
    {
        if (tablica [i] < tablica [indeks_najmniejszej])
        {
            indeks_najmniejszej = i;
        }
    }
    return tablica [indeks_najmniejszej];
}

int znajdz_najwieksza (int tablica [], int rozmiar)
{
    int indeks_najwiekszej = 0;
    for (int i = 0; i < rozmiar; i++)
    {
        if (tablica [i] > tablica [indeks_najwiekszej])
        {
            indeks_najwiekszej = i;
        }
    }
    return tablica [indeks_najwiekszej];
}

int znajdz_srednia (int tablica [], int rozmiar)
{
    int suma = 0;
    for (int i = 0; i < rozmiar; i++)
    {
        suma += tablica [i];
    }
    return suma / rozmiar;
}
