#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void czystka ()
{
    cin.clear();
    cin.sync();
}

string nazwa_karty (int numer_karty) //
{
    /* Wartosc karty reprezentowana jest przez liczbe od 1 do 14, a figura przez setki.
    Liczba ta moze byc rozbita na reszty z dzielenia przez 100, oraz wynik dzielenia przez 100 zapisywany w int. */
    string nazwa_1;
    string nazwa_2;
    int numer;
    numer = numer_karty % 100;
    switch (numer)
    {
    case 1:
        nazwa_1 = "As ";
        break;
    case 2:
        nazwa_1 = "2 ";
        break;
    case 3:
        nazwa_1 = "3 ";
        break;
    case 4:
        nazwa_1 = "4 ";
        break;
    case 5:
        nazwa_1 = "5 ";
        break;
    case 6:
        nazwa_1 = "6 ";
        break;
    case 7:
        nazwa_1 = "7 ";
        break;
    case 8:
        nazwa_1 = "8 ";
        break;
    case 9:
        nazwa_1 = "9 ";
        break;
    case 10:
        nazwa_1 = "10 ";
        break;
    case 11:
        nazwa_1 = "Walet ";
        break;
    case 12:
        nazwa_1 = "Dama ";
        break;
    case 13:
        nazwa_1 = "Krol ";
        break;
    case 14:
        nazwa_1 = "As ";
        break;
    }
    int figura;
    figura = numer_karty / 100;
    switch (figura)
    {
    case 1:
        nazwa_2 = "kier";
        break;
    case 2:
        nazwa_2 = "karo";
        break;
    case 3:
        nazwa_2 = "trefl";
        break;
    case 4:
        nazwa_2 = "pik";
        break;
    }
    return nazwa_1 + nazwa_2;
}

bool sprawdz_talie (int nr_karty_1, int nr_karty_2, int nr_karty_3, int nr_karty_4, int nr_karty_5, int nr_karty_6, int nr_karty_7, int nr_karty_8, int nr_karty_9, int nr_karty_10)
{
    return  ((nr_karty_1 == nr_karty_2) || (nr_karty_1 == nr_karty_3) || (nr_karty_1 == nr_karty_4) || (nr_karty_1 == nr_karty_5) || (nr_karty_1 == nr_karty_6) || (nr_karty_1 == nr_karty_7) || (nr_karty_1 == nr_karty_8) || (nr_karty_1 == nr_karty_9) || (nr_karty_1 == nr_karty_10) ||
            (nr_karty_2 == nr_karty_3) || (nr_karty_2 == nr_karty_4) || (nr_karty_2 == nr_karty_5) || (nr_karty_2 == nr_karty_6) || (nr_karty_2 == nr_karty_7) || (nr_karty_2 == nr_karty_8) || (nr_karty_2 == nr_karty_9) || (nr_karty_2 == nr_karty_10) ||
            (nr_karty_3 == nr_karty_4) || (nr_karty_3 == nr_karty_5) || (nr_karty_3 == nr_karty_6) || (nr_karty_3 == nr_karty_7) || (nr_karty_3 == nr_karty_8) || (nr_karty_3 == nr_karty_9) || (nr_karty_3 == nr_karty_10) ||
            (nr_karty_4 == nr_karty_5) || (nr_karty_4 == nr_karty_6) || (nr_karty_4 == nr_karty_7) || (nr_karty_4 == nr_karty_8) || (nr_karty_4 == nr_karty_9) || (nr_karty_4 == nr_karty_10) ||
            (nr_karty_5 == nr_karty_6) || (nr_karty_5 == nr_karty_7) || (nr_karty_5 == nr_karty_8) || (nr_karty_5 == nr_karty_9) || (nr_karty_5 == nr_karty_10) ||
            (nr_karty_6 == nr_karty_7) || (nr_karty_6 == nr_karty_8) || (nr_karty_6 == nr_karty_9) || (nr_karty_6 == nr_karty_10) ||
            (nr_karty_7 == nr_karty_8) || (nr_karty_7 == nr_karty_9) || (nr_karty_7 == nr_karty_10) ||
            (nr_karty_8 == nr_karty_9) || (nr_karty_8 == nr_karty_10) ||
            (nr_karty_9 == nr_karty_10));
}

int losuj_karte ()
{
    return (rand () % 14 + 1) + (rand () % 4 + 1) * 100;
}

void reka (int nazwa_1, int nazwa_2, int nazwa_3, int nazwa_4, int nazwa_5)
{
    cout << "Twoja reka to: " << endl;
    cout << "\t1 - " << nazwa_karty (nazwa_1) << endl << "\t2 - " << nazwa_karty (nazwa_2) << endl << "\t3 - " << nazwa_karty (nazwa_3) << endl << "\t4 - " << nazwa_karty (nazwa_4) << endl << "\t5 - " << nazwa_karty (nazwa_5) << endl;
}

string wybor_ukladu (int karta_1, int karta_2, int karta_3, int karta_4, int karta_5)
{
    // poker krolewski
    if ((karta_1 / 100 == karta_2 / 100) && (karta_1 / 100 == karta_3 / 100) && (karta_1 / 100 == karta_4 / 100) && (karta_1 / 100 == karta_5 / 100) //sprawdzenie jednoœci koloru
        && (karta_1 % 100 > 9) && (karta_1 % 100 < 15) && (karta_2 % 100 > 9) && (karta_2 % 100 < 15) && (karta_3 % 100 > 9) && (karta_3 % 100 < 15) && (karta_4 % 100 > 9) && (karta_4 % 100 < 15) && (karta_5 % 100 > 9) && (karta_5 % 100 < 15)) // sprawdzenie konkretnych kart
    {
        return "POKER KROLEWSKI!";
    }
    // poker
    else if((karta_1 / 100 == karta_2 / 100) && (karta_1 / 100 == karta_3 / 100) && (karta_1 / 100 == karta_4 / 100) && (karta_1 / 100 == karta_5 / 100) //sprawdzenie jednosci koloru
            && (karta_1 % 100 > karta_2 % 100 - 5) && (karta_1 % 100 > karta_3 % 100 - 5) && (karta_1 % 100 > karta_4 % 100 - 5) && (karta_1 % 100 > karta_5 % 100 - 5)
            && (karta_2 % 100 > karta_1 % 100 - 5) && (karta_2 % 100 > karta_3 % 100 - 5) && (karta_2 % 100 > karta_4 % 100 - 5) && (karta_2 % 100 > karta_5 % 100 - 5)
            && (karta_3 % 100 > karta_1 % 100 - 5) && (karta_3 % 100 > karta_2 % 100 - 5) && (karta_3 % 100 > karta_4 % 100 - 5) && (karta_3 % 100 > karta_5 % 100 - 5)
            && (karta_4 % 100 > karta_1 % 100 - 5) && (karta_4 % 100 > karta_2 % 100 - 5) && (karta_4 % 100 > karta_3 % 100 - 5) && (karta_4 % 100 > karta_5 % 100 - 5)
            && (karta_5 % 100 > karta_1 % 100 - 5) && (karta_5 % 100 > karta_2 % 100 - 5) && (karta_5 % 100 > karta_3 % 100 - 5) && (karta_5 % 100 > karta_4 % 100 - 5)) // sprawdzenie czy karty sa po kolei
    {
        return "POKER";
    }
    // kareta
    else if ((karta_1 % 100 + karta_2 % 100 + karta_3 % 100 + karta_4 % 100 == karta_1) ||
             (karta_1 % 100 + karta_2 % 100 + karta_3 % 100 + karta_5 % 100 == karta_1) ||
             (karta_1 % 100 + karta_2 % 100 + karta_4 % 100 + karta_5 % 100 == karta_1) ||
             (karta_1 % 100 + karta_3 % 100 + karta_4 % 100 + karta_5 % 100 == karta_1) ||
             (karta_2 % 100 + karta_3 % 100 + karta_4 % 100 + karta_5 % 100 == karta_1)) // sprawdzenie jednosci czterech kart
    {
        return "KARETA";
    }
    // full - trójka i para
    else if (((karta_1 % 100 == karta_2 % 100) && (karta_1 % 100 == karta_3 % 100) && (karta_4 % 100 == karta_5 % 100)) ||
             ((karta_1 % 100 == karta_2 % 100) && (karta_1 % 100 == karta_4 % 100) && (karta_3 % 100 == karta_5 % 100)) ||
             ((karta_1 % 100 == karta_2 % 100) && (karta_1 % 100 == karta_5 % 100) && (karta_3 % 100 == karta_4 % 100)) ||
             ((karta_1 % 100 == karta_3 % 100) && (karta_1 % 100 == karta_4 % 100) && (karta_2 % 100 == karta_5 % 100)) ||
             ((karta_1 % 100 == karta_3 % 100) && (karta_1 % 100 == karta_5 % 100) && (karta_2 % 100 == karta_4 % 100)) ||
             ((karta_1 % 100 == karta_4 % 100) && (karta_1 % 100 == karta_5 % 100) && (karta_2 % 100 == karta_3 % 100)) ||
             ((karta_2 % 100 == karta_3 % 100) && (karta_2 % 100 == karta_4 % 100) && (karta_1 % 100 == karta_5 % 100)) ||
             ((karta_2 % 100 == karta_3 % 100) && (karta_2 % 100 == karta_5 % 100) && (karta_1 % 100 == karta_4 % 100)) ||
             ((karta_2 % 100 == karta_4 % 100) && (karta_2 % 100 == karta_5 % 100) && (karta_1 % 100 == karta_3 % 100)) ||
             ((karta_3 % 100 == karta_4 % 100) && (karta_3 % 100 == karta_5 % 100) && (karta_1 % 100 == karta_2 % 100)))
    {
        return "FULL";
    }
    // kolor
    else if ((karta_1 / 100 == karta_2 / 100) && (karta_1 / 100 == karta_3 / 100) && (karta_1 / 100 == karta_4 / 100) && (karta_1 / 100 == karta_5 / 100)) //sprawdzenie jednoœci koloru
    {
        return "KOLOR";
    }
    // straight
    else if((karta_1 % 100 > karta_2 % 100 - 5) && (karta_1 % 100 > karta_3 % 100 - 5) && (karta_1 % 100 > karta_4 % 100 - 5) && (karta_1 % 100 > karta_5 % 100 - 5)
            && (karta_2 % 100 > karta_1 % 100 - 5) && (karta_2 % 100 > karta_3 % 100 - 5) && (karta_2 % 100 > karta_4 % 100 - 5) && (karta_2 % 100 > karta_5 % 100 - 5)
            && (karta_3 % 100 > karta_1 % 100 - 5) && (karta_3 % 100 > karta_2 % 100 - 5) && (karta_3 % 100 > karta_4 % 100 - 5) && (karta_3 % 100 > karta_5 % 100 - 5)
            && (karta_4 % 100 > karta_1 % 100 - 5) && (karta_4 % 100 > karta_2 % 100 - 5) && (karta_4 % 100 > karta_3 % 100 - 5) && (karta_4 % 100 > karta_5 % 100 - 5)
            && (karta_5 % 100 > karta_1 % 100 - 5) && (karta_5 % 100 > karta_2 % 100 - 5) && (karta_5 % 100 > karta_3 % 100 - 5) && (karta_5 % 100 > karta_4 % 100 - 5)) // sprawdzenie czy karty sa po kolei
    {
        return "STRAIGHT";
    }
    // trojka
    else if (((karta_1 % 100 == karta_2 % 100) && (karta_1 % 100 == karta_3 % 100)) ||
             ((karta_1 % 100 == karta_2 % 100) && (karta_1 % 100 == karta_4 % 100)) ||
             ((karta_1 % 100 == karta_2 % 100) && (karta_1 % 100 == karta_5 % 100)) ||
             ((karta_1 % 100 == karta_3 % 100) && (karta_1 % 100 == karta_4 % 100)) ||
             ((karta_1 % 100 == karta_3 % 100) && (karta_1 % 100 == karta_5 % 100)) ||
             ((karta_1 % 100 == karta_4 % 100) && (karta_1 % 100 == karta_5 % 100)) ||
             ((karta_2 % 100 == karta_3 % 100) && (karta_2 % 100 == karta_4 % 100)) ||
             ((karta_2 % 100 == karta_3 % 100) && (karta_2 % 100 == karta_5 % 100)) ||
             ((karta_2 % 100 == karta_4 % 100) && (karta_2 % 100 == karta_5 % 100)) ||
             ((karta_3 % 100 == karta_4 % 100) && (karta_3 % 100 == karta_5 % 100)))
    {
        return "TRÓJKA";
    }
    // dwie pary
    else if ((karta_1 % 100 == karta_2 % 100) || (karta_1 % 100 == karta_3 % 100) || (karta_1 % 100 == karta_4 % 100) || (karta_1 % 100 == karta_5 % 100) ||
             (karta_2 % 100 == karta_3 % 100) || (karta_2 % 100 == karta_4 % 100) || (karta_2 % 100 == karta_5 % 100) ||
             (karta_3 % 100 == karta_4 % 100) || (karta_3 % 100 == karta_5 % 100) ||
             (karta_4 % 100 == karta_5 % 100))
    {
        if ((karta_1 % 100 == karta_2 % 100) || (karta_1 % 100 == karta_3 % 100) || (karta_1 % 100 == karta_4 % 100) || (karta_1 % 100 == karta_5 % 100))
        {
            if ((karta_2 % 100 == karta_3 % 100) || (karta_2 % 100 == karta_4 % 100) || (karta_2 % 100 == karta_5 % 100) ||
                (karta_3 % 100 == karta_4 % 100) || (karta_3 % 100 == karta_5 % 100) ||
                (karta_4 % 100 == karta_5 % 100))
            {
                return "DWIE PARY";
            }
            else
            {
                return "PARA";
            }
        }
        else if ((karta_2 % 100 == karta_3 % 100) || (karta_2 % 100 == karta_4 % 100) || (karta_2 % 100 == karta_5 % 100))
        {
            if ((karta_3 % 100 == karta_4 % 100) || (karta_3 % 100 == karta_5 % 100) ||
                (karta_4 % 100 == karta_5 % 100))
            {
                return "DWIE PARY";
            }
            else
            {
                return "PARA";
            }
        }
        else
        {
            return "PARA";
        }
    }
    // para
        // uwzględnione wyzej
    // wysoka karta
    else
    {
        if ((karta_1 % 100 >= karta_2 % 100) && (karta_1 % 100 >= karta_3 % 100) && (karta_1 % 100 >= karta_4 % 100) && (karta_1 % 100 >= karta_5 % 100))
        {
            return nazwa_karty (karta_1);
        }
        else if ((karta_2 % 100 >= karta_1 % 100) && (karta_2 % 100 >= karta_3 % 100) && (karta_2 % 100 >= karta_4 % 100) && (karta_2 % 100 >= karta_5 % 100))
        {
            return nazwa_karty (karta_2);
        }
        else if ((karta_3 % 100 >= karta_1 % 100) && (karta_3 % 100 >= karta_2 % 100) && (karta_3 % 100 >= karta_4 % 100) && (karta_3 % 100 >= karta_5 % 100))
        {
            return nazwa_karty (karta_3);
        }
        else if ((karta_4 % 100 >= karta_1 % 100) && (karta_4 % 100 >= karta_2 % 100) && (karta_4 % 100 >= karta_3 % 100) && (karta_1 % 100 >= karta_5 % 100))
        {
            return nazwa_karty (karta_4);
        }
        else
        {
            return nazwa_karty (karta_5);
        }
    }
}

int main()
{
    srand(time(NULL));
    cout << "Dociagnij piec kart." << endl;
    cin.get();
    // losowanie karty
    int karta_1 = -1; int karta_2= -2; int karta_3 = -3; int karta_4 = -4; int karta_5 = -5; int karta_6 = -6; int karta_7 = -7; int karta_8 = -8; int karta_9 = -9; int karta_10 = -10;
    karta_1 = losuj_karte ();
    do
    {
        karta_2 = losuj_karte ();
    } while (sprawdz_talie (karta_1, karta_2, karta_3, karta_4, karta_5, karta_6, karta_7, karta_8, karta_9, karta_10));
    do
    {
        karta_3 = losuj_karte ();
    } while (sprawdz_talie (karta_1, karta_2, karta_3, karta_4, karta_5, karta_6, karta_7, karta_8, karta_9, karta_10));
    do
    {
        karta_4 = losuj_karte ();
    } while (sprawdz_talie (karta_1, karta_2, karta_3, karta_4, karta_5, karta_6, karta_7, karta_8, karta_9, karta_10));
    do
    {
        karta_5 = losuj_karte ();
    } while (sprawdz_talie (karta_1, karta_2, karta_3, karta_4, karta_5, karta_6, karta_7, karta_8, karta_9, karta_10));
    reka (karta_1, karta_2, karta_3, karta_4, karta_5);
    // Ocena reki kart
    string uklad;
    uklad = wybor_ukladu (karta_1, karta_2, karta_3, karta_4, karta_5);
    cout << endl << uklad << endl;
    cin.get();
    // wymiana kart
    // wymiana kart - nadpisanie kart do ew wymiany
    cout << endl << "Ile kart chcesz wymienic? (0 - 5)" << endl;
    int wymiana = 0;
    cin >> wymiana;
    int pamiec_1 = -1; int pamiec_2 = -2; int pamiec_3 = -3; int pamiec_4 = -4; int pamiec_5 = -5;
    for (int i = 0; i < wymiana; i++)
    {
        do
        {
            cout << endl <<"Ktora karte wymieniasz? (1 - 5)" << endl;
            int wymieniam;
            cin >> wymieniam;
            switch (i)
            {
            case 0:
                pamiec_1 = wymieniam;
                break;
            case 1:
                pamiec_2 = wymieniam;
                break;
            case 2:
                pamiec_3 = wymieniam;
                break;
            case 3:
                pamiec_4 = wymieniam;
                break;
            case 4:
                pamiec_5 = wymieniam;
                break;
            }
            switch (wymieniam)
            {
            case 1:
                do
                {
                    karta_6 = karta_1;
                    karta_1 = losuj_karte ();
                } while (sprawdz_talie (karta_1, karta_2, karta_3, karta_4, karta_5, karta_6, karta_7, karta_8, karta_9, karta_10));
                break;
            case 2:
                do
                {
                    karta_7 = karta_2;
                    karta_2 = losuj_karte ();
                } while (sprawdz_talie (karta_1, karta_2, karta_3, karta_4, karta_5, karta_6, karta_7, karta_8, karta_9, karta_10));
                break;
            case 3:
                do
                {
                    karta_8 = karta_3;
                    karta_3 = losuj_karte ();
                } while (sprawdz_talie (karta_1, karta_2, karta_3, karta_4, karta_5, karta_6, karta_7, karta_8, karta_9, karta_10));
                break;
            case 4:
                do
                {
                    karta_9 = karta_4;
                    karta_4 = losuj_karte ();
                } while (sprawdz_talie (karta_1, karta_2, karta_3, karta_4, karta_5, karta_6, karta_7, karta_8, karta_9, karta_10));
                break;
            case 5:
                do
                {
                    karta_10 = karta_5;
                    karta_5 = losuj_karte ();
                } while (sprawdz_talie (karta_1, karta_2, karta_3, karta_4, karta_5, karta_6, karta_7, karta_8, karta_9, karta_10));
                break;
            }
            if ((pamiec_1 == pamiec_2) || (pamiec_1 == pamiec_3) || (pamiec_1 == pamiec_4) || (pamiec_1 == pamiec_5) ||
                 (pamiec_2 == pamiec_3) || (pamiec_2 == pamiec_4) || (pamiec_2 == pamiec_5) ||
                 (pamiec_3 == pamiec_4) || (pamiec_3 == pamiec_5) ||
                 (pamiec_4 == pamiec_5))
                 {
                     cout << "Karta zostala juz wymieniona" << endl;
                 }
        } while ((pamiec_1 == pamiec_2) || (pamiec_1 == pamiec_3) || (pamiec_1 == pamiec_4) || (pamiec_1 == pamiec_5) ||
                 (pamiec_2 == pamiec_3) || (pamiec_2 == pamiec_4) || (pamiec_2 == pamiec_5) ||
                 (pamiec_3 == pamiec_4) || (pamiec_3 == pamiec_5) ||
                 (pamiec_4 == pamiec_5));
    }
    cin.get();
    reka (karta_1, karta_2, karta_3, karta_4, karta_5);
    // Ocena reki kart
    uklad = wybor_ukladu (karta_1, karta_2, karta_3, karta_4, karta_5);
    cout << endl << uklad << endl;
    cin.get();
    return 0;
    // UWAGA! PROGRAM NIE OBS£UGUJE B£EDÓW WPROWADZANIA NIEPOPRAWNEGO TYPU ZMIENNEJ! W PRZYPADKU BLEDNEGO WPROWADZENIA PROGRAM WYLACZY SIE.
}
