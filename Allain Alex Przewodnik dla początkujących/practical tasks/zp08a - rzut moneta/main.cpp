#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void czystka ()
{
    std::cin.clear();
    std::cin.sync();
}

int main ()
{
    int ilosc_rzutow;
    cout << "Podaj ilosc rzutow: ";
    cin >> ilosc_rzutow;
    czystka ();
    srand (time (NULL));
    cout << endl;
    int orzel = 0;
    int reszka = 0;
    for (int i = 0; i < ilosc_rzutow; i++)
    {
        int rzut;
        rzut = rand () % 2;
        switch (rzut)
        {
        case 0:
            cout << "Orzel" << endl;
            orzel++;
            break;
        case 1:
            cout << "Reszka" << endl;
            reszka++;
            break;
        }
    }
    cout << endl << "Orzel: " << orzel << endl << "Reszka: " << reszka << endl;
    return 0;
}
