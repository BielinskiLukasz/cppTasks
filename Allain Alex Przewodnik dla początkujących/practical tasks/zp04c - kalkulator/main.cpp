#include <iostream>
#include <string>
using namespace std;
int main ()
{
    string dzialanie;
    double zmienna_1 = 0;
    double zmienna_2 = 0;
    double wynik = 0;
    cout << "Podaj rodzaj dzialania: ";
    cin >> dzialanie;
    cout << "Podaj pierwsza liczbe: ";
    cin >> zmienna_1;
    cout << "Podaj druga liczbe: ";
    cin >> zmienna_2;
    if (dzialanie == "+")
    {
        wynik = zmienna_1 + zmienna_2;
    }
    else if (dzialanie == "-")
    {
        wynik = zmienna_1 - zmienna_2;
    }
    else if (dzialanie == "/")
    {
        wynik = zmienna_1 / zmienna_2;
    }
    else if (dzialanie == "*")
    {
        wynik = zmienna_1 * zmienna_2;
    }
    cout << "Wynik dzialania to " << wynik;
    return 0;
}
