#include <iostream>
#include <string>
using namespace std;
int main ()
{
    string nazwa_uzytkownika;
    string haslo;
    cout << "Podaj nazwe uzytkownika: ";
    cin >> nazwa_uzytkownika;
    cout << "Podaj haslo: ";
    cin >> haslo;
    if ((nazwa_uzytkownika == "Lukasz" && haslo == "1234") || (nazwa_uzytkownika == "Magda" && haslo == "1111"))
    {
        cout << "WITAJ!";
    }
    else
    {
        cout << "Niepoprawne haslo i/lub nazwa uzytkownika, sprobuj ponownie" << endl;
    }
    cout << "Podaj nazwe uzytkownika: ";
    cin >> nazwa_uzytkownika;
    cout << "Podaj haslo: ";
    cin >> haslo;
    if ((nazwa_uzytkownika == "Lukasz" && haslo == "1234") || (nazwa_uzytkownika == "Magda" && haslo == "1111"))
    {
        cout << "WITAJ!";
    }
    else
    {
        cout << "Ponownie niepoprawne haslo i/lub nazwa uzytkownika" << endl << "Wylaczanie programu";
        return 0;
    }
}
