#include <iostream>
#include <string>

using namespace std;

void czystka ()
{
    std::cin.clear();
    std::cin.sync();
}

char znak (int numer, int pole_planszy)
{
    enum PolePlanszy {PP_puste, PP_O, PP_X};
    switch (pole_planszy)
    {
    case PP_puste:
        return ' ';
        break;
    case PP_O:
        return 'O';
        break;
    case PP_X:
        return 'X';
        break;
    default:
        return 0;
    }
}

void plansza (char ppw_1, char ppw_2, char ppw_3, char ppw_4, char ppw_5, char ppw_6, char ppw_7, char ppw_8, char ppw_9)
{
    cout << "  Numer pola \t  Plansza   " << endl << endl;
    cout << "  1 | 2 | 3 \t " << ppw_1 << " | " << ppw_2 << " | " << ppw_3 <<  endl;
    cout << " ---+---+---\t---+---+---" << endl;
    cout << "  4 | 5 | 6 \t " << ppw_4 << " | " << ppw_5 << " | " << ppw_6 << endl;
    cout << " ---+---+---\t---+---+---" << endl;
    cout << "  7 | 8 | 9 \t " << ppw_7 << " | " << ppw_8 << " | " << ppw_9 << endl << endl;
}

int gra()
{
    //gracze
    cout << endl;
    cout << "Gracz 1 (kolko)" << endl;
    cout << "Podaj nazwe gracza: ";
    string nick_1;
    cin >> nick_1;
    czystka ();
    cout << endl;
    cout << "Gracz 2 (krzyzyk)" << endl;
    cout << "Podaj nazwe gracza: ";
    string nick_2;
    cin >> nick_2;
    czystka ();
    //pola planszy
    cout << endl;
    enum PolePlanszy {PP_puste, PP_O, PP_X};
    char pp_1 = znak (1, PP_puste);
    char pp_2 = znak (2, PP_puste);
    char pp_3 = znak (3, PP_puste);
    char pp_4 = znak (4, PP_puste);
    char pp_5 = znak (5, PP_puste);
    char pp_6 = znak (6, PP_puste);
    char pp_7 = znak (7, PP_puste);
    char pp_8 = znak (8, PP_puste);
    char pp_9 = znak (9, PP_puste);
    bool wybor_pola = false;
    plansza (pp_1, pp_2, pp_3, pp_4, pp_5, pp_6, pp_7, pp_8, pp_9);
    cout << endl;
    for (int licznik_rund = 1; licznik_rund < 10; licznik_rund ++)
    {
        cout << "Teraz " << nick_1 << " (kolko)" << endl;
        wybor_pola = false;
        while (wybor_pola == false)
        {
            cout << "Wybierz pole: ";
            int pole;
            cin >> pole;
            czystka ();
            cout << endl;
            switch (pole)
            {
            case 1:
                if (pp_1 == znak (1, PP_puste))
                {
                    pp_1 = znak (1, PP_O);
                    wybor_pola = true;
                    break;
                }
                else
                {
                    cout << "Pole zajete" << endl;
                    break;
                }
            case 2:
                if (pp_2 == znak (2, PP_puste))
                {
                    pp_2 = znak (2, PP_O);
                    wybor_pola = true;
                    break;
                }
                else
                {
                    cout << "Pole zajete" << endl;
                    break;
                }
            case 3:
                if (pp_3 == znak (3, PP_puste))
                {
                    pp_3 = znak (3, PP_O);
                    wybor_pola = true;
                    break;
                }
                else
                {
                    cout << "Pole zajete" << endl;
                    break;
                }
            case 4:
                if (pp_4 == znak (4, PP_puste))
                {
                    pp_4 = znak (4, PP_O);
                    wybor_pola = true;
                    break;
                }
                else
                {
                    cout << "Pole zajete" << endl;
                    break;
                }
            case 5:
                if (pp_5 == znak (5, PP_puste))
                {
                    pp_5 = znak (5, PP_O);
                    wybor_pola = true;
                    break;
                }
                else
                {
                    cout << "Pole zajete" << endl;
                    break;
                }
            case 6:
                if (pp_6 == znak (6, PP_puste))
                {
                    pp_6 = znak (6, PP_O);
                    wybor_pola = true;
                    break;
                }
                else
                {
                    cout << "Pole zajete" << endl;
                    break;
                }
            case 7:
                if (pp_7 == znak (7, PP_puste))
                {
                    pp_7 = znak (7, PP_O);
                    wybor_pola = true;
                    break;
                }
                else
                {
                    cout << "Pole zajete" << endl;
                    break;
                }
            case 8:
                if (pp_8 == znak (8, PP_puste))
                {
                    pp_8 = znak (8, PP_O);
                    wybor_pola = true;
                    break;
                }
                else
                {
                    cout << "Pole zajete" << endl;
                    break;
                }
            case 9:
                if (pp_9 == znak (9, PP_puste))
                {
                    pp_9 = znak (9, PP_O);
                    wybor_pola = true;
                    break;
                }
                else
                {
                    cout << "Pole zajete" << endl;
                    break;
                }
            default:
                {
                    cout << "Bledne pole" << endl;
                    break;
                }
                // tutaj widze potencjal pod funkcje
            }
        }
        plansza (pp_1, pp_2, pp_3, pp_4, pp_5, pp_6, pp_7, pp_8, pp_9);
        cout << endl;
        if (pp_1 == znak (1, PP_O) & pp_2 == znak (2, PP_O) & pp_3 == znak (3, PP_O) ||
            pp_4 == znak (4, PP_O) & pp_5 == znak (5, PP_O) & pp_6 == znak (6, PP_O) ||
            pp_7 == znak (7, PP_O) & pp_8 == znak (8, PP_O) & pp_9 == znak (9, PP_O) ||
            pp_1 == znak (1, PP_O) & pp_4 == znak (4, PP_O) & pp_7 == znak (7, PP_O) ||
            pp_2 == znak (2, PP_O) & pp_5 == znak (5, PP_O) & pp_8 == znak (8, PP_O) ||
            pp_3 == znak (3, PP_O) & pp_6 == znak (6, PP_O) & pp_9 == znak (9, PP_O) ||
            pp_1 == znak (1, PP_O) & pp_5 == znak (5, PP_O) & pp_9 == znak (9, PP_O) ||
            pp_3 == znak (3, PP_O) & pp_5 == znak (5, PP_O) & pp_7 == znak (7, PP_O))
            {
                cout << "\nWygrales!!!\n";
                return 0;
            }
        cout << "Teraz " << nick_2 << " (krzyzyk)" << endl;
        wybor_pola = false;
        while (wybor_pola == false)
        {
            cout << "Wybierz pole: ";
            int pole;
            cin >> pole;
            czystka ();
            cout << endl;
            switch (pole)
            {
            case 1:
                if (pp_1 == znak (1, PP_puste))
                {
                    pp_1 = znak (1, PP_X);
                    wybor_pola = true;
                    break;
                }
                else
                {
                    cout << "Pole zajete" << endl;
                    break;
                }
            case 2:
                if (pp_2 == znak (2, PP_puste))
                {
                    pp_2 = znak (2, PP_X);
                    wybor_pola = true;
                    break;
                }
                else
                {
                    cout << "Pole zajete" << endl;
                    break;
                }
            case 3:
                if (pp_3 == znak (3, PP_puste))
                {
                    pp_3 = znak (3, PP_X);
                    wybor_pola = true;
                    break;
                }
                else
                {
                    cout << "Pole zajete" << endl;
                    break;
                }
            case 4:
                if (pp_4 == znak (4, PP_puste))
                {
                    pp_4 = znak (4, PP_X);
                    wybor_pola = true;
                    break;
                }
                else
                {
                    cout << "Pole zajete" << endl;
                    break;
                }
            case 5:
                if (pp_5 == znak (5, PP_puste))
                {
                    pp_5 = znak (5, PP_X);
                    wybor_pola = true;
                    break;
                }
                else
                {
                    cout << "Pole zajete" << endl;
                    break;
                }
            case 6:
                if (pp_6 == znak (6, PP_puste))
                {
                    pp_6 = znak (6, PP_X);
                    wybor_pola = true;
                    break;
                }
                else
                {
                    cout << "Pole zajete" << endl;
                    break;
                }
            case 7:
                if (pp_7 == znak (7, PP_puste))
                {
                    pp_7 = znak (7, PP_X);
                    wybor_pola = true;
                    break;
                }
                else
                {
                    cout << "Pole zajete" << endl;
                    break;
                }
            case 8:
                if (pp_8 == znak (8, PP_puste))
                {
                    pp_8 = znak (8, PP_X);
                    wybor_pola = true;
                    break;
                }
                else
                {
                    cout << "Pole zajete" << endl;
                    break;
                }
            case 9:
                if (pp_9 == znak (9, PP_puste))
                {
                    pp_9 = znak (9, PP_X);
                    wybor_pola = true;
                    break;
                }
                else
                {
                    cout << "Pole zajete" << endl;
                    break;
                }
            default:
                {
                    cout << "Bledne pole" << endl;
                    break;
                }
                // tutaj widze potencjal pod funkcje
            }
        }
    if (pp_1 == znak (1, PP_O) & pp_2 == znak (2, PP_O) & pp_3 == znak (3, PP_O) ||
        pp_4 == znak (4, PP_O) & pp_5 == znak (5, PP_O) & pp_6 == znak (6, PP_O) ||
        pp_7 == znak (7, PP_O) & pp_8 == znak (8, PP_O) & pp_9 == znak (9, PP_O) ||
        pp_1 == znak (1, PP_O) & pp_4 == znak (4, PP_O) & pp_7 == znak (7, PP_O) ||
        pp_2 == znak (2, PP_O) & pp_5 == znak (5, PP_O) & pp_8 == znak (8, PP_O) ||
        pp_3 == znak (3, PP_O) & pp_6 == znak (6, PP_O) & pp_9 == znak (9, PP_O) ||
        pp_1 == znak (1, PP_O) & pp_5 == znak (5, PP_O) & pp_9 == znak (9, PP_O) ||
        pp_3 == znak (3, PP_O) & pp_5 == znak (5, PP_O) & pp_7 == znak (7, PP_O))
        {
            cout << "\nWygrales!!!\n";
            return 0;
        }
        plansza (pp_1, pp_2, pp_3, pp_4, pp_5, pp_6, pp_7, pp_8, pp_9);
        cout << endl;
    }
    //petla rewanżu
}

int main ()
{
    cout << "###   KOLKO I KRZYZYK   ###" << endl;
    cout << "\t1. Nowa gra" << endl;
    cout << "\t2. Wyjscie" << endl << "\t";
    int wybor_menu;
    cin >> wybor_menu;
    czystka();
    do
    {
        switch (wybor_menu)
        {
            case 1:
                gra ();
                break;
            case 2:
                return 0;
            default:
                cout << "Bledny wybor" << endl;
        }
    } while ((wybor_menu != 1 & wybor_menu != 2));
}
