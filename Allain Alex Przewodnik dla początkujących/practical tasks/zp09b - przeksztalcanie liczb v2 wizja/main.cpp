#include <iostream>
#include <string>

using namespace std;

void czystka ();

int main()
{
    cout << "Zastanowilem sie i nie podolalem..." << endl;
    return 0;
}

void czystka ()
{
    cin.clear ();
    cin.sync ();
}

/* Problem z pobieraniem wpisanych liczb.
Gdy wprowadzone zostanie mniej liczb to program czeka na wprowadzenie kolejnych.
Gdyby to przeskoczyc problem choc dalej trudny, bylby juz do rozwiazania na obecnym etapie wiedzy.
Wprowadzone liczby bylyby zapisywane jako mnienne, a koncowa liczba bazowalaby na dzialaniu tych zmiennych.
Wprowadzenie blednych danych moznaby rozwiazac przez sprawdzenie ich oraz petle do momentu wprowadzenia poprawnej liczby.
Wprowadzenia wymagalaby cala liczba, a przed ponownym wprowadzaniem wskazany zostanie czlon blednie wprowadzony.
*/
