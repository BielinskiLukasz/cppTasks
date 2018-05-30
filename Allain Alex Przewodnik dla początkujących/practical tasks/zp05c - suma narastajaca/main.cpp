#include <iostream>
using namespace std;
int main ()
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
}
