#include <iostream>
#include <string>
using namespace std;
int main ()
{
    string imie_1;
    int wiek_1;
    cout << "Podaj imie pierwszej osoby: ";
    cin >> imie_1;
    cout << "\nPodaj wiek pierwszej osoby: ";
    cin >> wiek_1;
    string imie_2;
    int wiek_2;
    cout << "\nPodaj imie drugiej osoby: ";
    cin >> imie_2;
    cout << "\nPodaj wiek drugiej osoby: ";
    cin >> wiek_2;
    if (wiek_1 > wiek_2)
    {
        cout << "\n" << imie_1 << " ma wiecej lat od " << imie_2;
    }
    else if (wiek_1 == wiek_2)
    {
        cout << "\n" << imie_1 << " oraz " << imie_2 << "sa w tym samym wieku";
    }
    else
    {
        cout << "\n" << imie_1 << " ma mniej lat od " << imie_2;
    }
    if (wiek_1 > 100 && wiek_2 > 100)
    {
        cout << "\n\nWidze, ze znasz baaardzo stare osoby xD\n";
    }
    cout << endl;
}
