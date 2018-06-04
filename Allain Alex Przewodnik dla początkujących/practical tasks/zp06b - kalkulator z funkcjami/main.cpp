#include <iostream>
#include <string>

using namespace std;

double dodawanie (double a, double b)
{
    return a + b;
}

double odejmowanie (double a, double b)
{
    return a - b;
}

double dzielenie (double a, double b)
{
    if (b == 0)
    {
        cout << "Nie dziel przez zero!!!\n";
        return 0;
    }
    else
        return a / b;
}

double mnozenie (double a, double b)
{
    return a * b;
}

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
        wynik = dodawanie (zmienna_1, zmienna_2);
    }
    else if (dzialanie == "-")
    {
        wynik = odejmowanie (zmienna_1, zmienna_2);
    }
    else if (dzialanie == "/")
    {
        wynik = dzielenie (zmienna_1, zmienna_2);
    }
    else if (dzialanie == "*")
    {
        wynik = mnozenie (zmienna_1, zmienna_2);
    }
    cout << "Wynik dzialania to " << wynik;
    return 0;
}
