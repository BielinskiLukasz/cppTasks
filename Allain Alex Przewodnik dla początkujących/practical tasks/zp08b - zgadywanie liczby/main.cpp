#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void czystka ()
{
    std::cin.clear();
    std::cin.sync();
}

int main()
{
    srand (time (NULL));
    int liczba;
    liczba = (rand () % 100) + 1;
    int strzal = 0;
    int ilosc_strzalow = 0;
    cout << "Szukana liczba z przedzialu 0 - 100" << endl;
    while (strzal != liczba)
    {
        cout << "Zgaduj liczbe: ";
        cin >> strzal;
        cout << endl;
        czystka ();
        ilosc_strzalow++;
        if (strzal > liczba)
        {
            cout << "Pudlo! Szukana liczba jest mniejsza." << endl;
        }
        else if (strzal < liczba)
        {
            cout << "Pudlo! Szukana liczba jest wieksza." << endl;
        }
    }
    cout << "ZGADLES!!!" << endl << "Potrzebowales " << ilosc_strzalow << " prob" << endl;
    return 0;
}
