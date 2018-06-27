#include <iostream>
#include <string>

using namespace std;

void czystka ();
void przeksztalc (int cyfrowo);
void cykl (int trzycyfrowa);
void setki (int dana_100);
void dziesiatki (int dana_10);
void licznik (int licz);

int main()
{
    cout << "Podaj liczbe do przeksztalcenia (zakres -999999 - 999999): ";
    int liczba = 0;
    cin >> liczba;
    czystka ();
    przeksztalc (liczba);
    return 0;
}

void czystka ()
{
    cin.clear ();
    cin.sync ();
}

void przeksztalc (int cyfrowo)
{
    int znak;
    znak = cyfrowo;
    if (cyfrowo < 0)
    {
        cout << "minus";
        znak = -cyfrowo;
    }
    int zmienna;
    zmienna = znak / 1000;
    if (znak > 999)
    {
        cykl (zmienna);
        if (zmienna - zmienna / 10 * 10 > 5 || zmienna / 10 - zmienna / 100 * 10 == 1)
        {
            cout << " tysiecy";
        }
        else if (zmienna - zmienna / 10 * 10 > 1)
        {
            cout << " tysiace";
        }
        else
        {
            cout << " tysiac";
        }
    }
    cykl (znak - zmienna * 1000);
}

void cykl (int trzycyfrowa)
{
    int zmienna_100;
    int zmienna_10;
    int zmienna_1;
    zmienna_100 = trzycyfrowa / 100;
    if (zmienna_100 > 0)
    {
        setki (zmienna_100);
    }
    zmienna_10 = trzycyfrowa /10 - zmienna_100 * 10;
    if (zmienna_10 > 2)
    {
        dziesiatki (zmienna_10);
    }
    else if (zmienna_10 == 2)
    {
        licznik (20);
    }
    else
    {
        licznik (trzycyfrowa - zmienna_100*100);
    }
    zmienna_1 = trzycyfrowa - zmienna_100 * 100 - zmienna_10 * 10;
    if (zmienna_10 > 1)
    {
        licznik (zmienna_1);
    }
}

void setki (int dana_100)
{
    if (dana_100 > 2)
    {
        licznik (dana_100);
        if (dana_100 > 4)
        {
            cout << "set";
        }
        else
        {
            cout << "sta";
        }
    }
    else if (dana_100 == 2)
    {
        cout << " dwiescie";
    }
    else
    {
        cout << " sto";
    }
}

void dziesiatki (int dana_10)
{
    if (dana_10 > 2)
    {
        licznik (dana_10);
        if (dana_10 > 4)
        {
            cout << "dziesiat";
        }
        else
        {
            cout << "dziesci";
        }
    }
}

void licznik (int licz)
{
    switch (licz)
    {
    case 1:
        cout << " jeden";
        break;
    case 2:
        cout << " dwa";
        break;
    case 3:
        cout << " trzy";
        break;
    case 4:
        cout << " cztery";
        break;
    case 5:
        cout << " piec";
        break;
    case 6:
        cout << " szesc";
        break;
    case 7:
        cout << " siedem";
        break;
    case 8:
        cout << " osiem";
        break;
    case 9:
        cout << " dziewiec";
        break;
    case 10:
        cout << " dziesiec";
        break;
    case 11:
        cout << " jedenascie";
        break;
    case 12:
        cout << " dwanascie";
        break;
    case 13:
        cout << " trzynascie";
        break;
    case 14:
        cout << " czternascie";
        break;
    case 15:
        cout << " pietnascie";
        break;
    case 16:
        cout << " szesnascie";
        break;
    case 17:
        cout << " siedemnascie";
        break;
    case 18:
        cout << " osiemnascie";
        break;
    case 19:
        cout << " dziewietnascie";
        break;
    case 20:
        cout << " dwadziescia";
        break;
    }
}
