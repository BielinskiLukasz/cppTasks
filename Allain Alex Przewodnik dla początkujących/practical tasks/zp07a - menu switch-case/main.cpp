#include <iostream>
using namespace std;

void piosenka ()
{
    for (int i=99; i>1 ; i--)
    {
        cout << i << " bottles of beer on the wall, " << i << " bottles fo beer. Take one down and pass it around - " << i-1 << " bottles of beer on the wall." << endl;
    }
    cout << "1 bottle of beer on the wall, 1 bottle of beer. Take it down and pass it around - no more bottles of beer on the wall." << endl;
}

void kalkulator ()
{
    char dzialanie;
    double zmienna_1 = 0;
    double zmienna_2 = 0;
    double wynik = 0;
    cout << "Podaj rodzaj dzialania: ";
    cin >> dzialanie;
    cout << "Podaj pierwsza liczbe: ";
    cin >> zmienna_1;
    cout << "Podaj druga liczbe: ";
    cin >> zmienna_2;
    switch (dzialanie)
    {
        case '+':
            wynik = zmienna_1 + zmienna_2;
            break;
        case '-':
            wynik = zmienna_1 - zmienna_2;
            break;
        case '/':
            wynik = zmienna_1 / zmienna_2;
            break;
        case '*':
            wynik = zmienna_1 * zmienna_2;
            break;
        default:
            cout << "Bledny wybor" << endl;
    }
    cout << "Wynik dzialania to " << wynik;
}

int main ()
{
    int wybor = 0;
    int popr_wybor = 0;
    while (popr_wybor != 1)
    {
        cout << endl;
        cout << "\t#################################" << endl;
        cout << "\t#\t\tWitaj!\t\t#" << endl;
        cout << "\t#\t1 - Piosenka\t\t#" << endl;
        cout << "\t#\t2 - Kalkulator\t\t#" << endl;
        cout << "\t#\t3 - Wyjscie\t\t#" << endl;
        cout << "\t#################################" << endl;
        cout << "\tWybierz operacje: ";
        cin >> wybor;
        if (wybor == 1 || wybor == 2 || wybor == 3)
        {
            popr_wybor = 1;
        }
        switch (wybor)
        {
            case 1:
                piosenka();
                break;
            case 2:
                kalkulator();
                break;
            case 3:
                return 0;
                break;
            default:
                cout << "Bledny wybor, wylaczanie programu" << endl;
                return 0;
        }
        std::cin.clear();
        std::cin.sync();
    }
    return 0;
}
