#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int losowanie (int minimum, int maximum)
{
    return (rand () % (maximum - minimum + 1)) + minimum;
}

int main()
{
    srand (time (NULL));
    int liczba;
    liczba = losowanie (1, 100);
    int strzal = 0;
    int ilosc_strzalow = 0;
    cout << "Szukana liczba z przedzialu 0 - 100 to " << liczba << endl;
    int zmienne_min = 1;
    int zmienne_max = 100;
    while (strzal != liczba)
    {
        strzal = losowanie (zmienne_min, zmienne_max);
        cout << "AI wytypowalo " << strzal << endl;
        ilosc_strzalow++;
        if (strzal > liczba)
        {
            cout << "Pudlo! Szukana liczba jest mniejsza." << endl;
            zmienne_max = strzal - 1;
        }
        else if (strzal < liczba)
        {
            cout << "Pudlo! Szukana liczba jest wieksza." << endl;
            zmienne_min = strzal + 1;
        }
    }
    cout << "AI ZGADLO!!!" << endl << "Potrzebowalo " << ilosc_strzalow << " prob" << endl;
    return 0;
}
