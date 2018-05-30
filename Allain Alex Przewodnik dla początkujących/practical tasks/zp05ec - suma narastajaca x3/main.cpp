#include <iostream>
using namespace std;
int main ()
{

}

int d ()
{
    double liczba = 0;
    double suma = 0;
    do
    {
        cout << "Podaj liczbe do zsumowania: ";
        cin >> liczba;
        suma += liczba;
        cout << "Suma to: " << suma << endl;
    } while (liczba != 0);
    return 0;
}

int w ()
{
    double liczba = 1;
    double suma = 0;
    while (liczba != 0)
    {
        cout << "Podaj liczbe do zsumowania: ";
        cin >> liczba;
        suma += liczba;
        cout << "Suma to: " << suma << endl;
    }
    return 0;
}

int f()
{
    double suma = 0;
    for (double liczba; liczba != 0; suma += liczba)
    {
        cout << "Podaj liczbe do zsumowania: ";
        cin >> liczba;
        cout << "Suma to: " << suma + liczba << endl;
    }
    return 0;
}
