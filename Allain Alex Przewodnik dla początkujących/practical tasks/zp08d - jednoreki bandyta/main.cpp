#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int los (int minimum, int maximum)
{
    return rand () % (maximum - minimum + 1) + 1;
}

void czystka ()
{
    cin.clear();
    cin.sync();
}

int zaklad (int max_zaklad)
{
    cout << "Ile wrzucasz do automatu? (min 0, max " << max_zaklad << ")" << endl;
    int zaklad;
    cin >> zaklad;
    czystka();
    return zaklad;
}

void wynik (int a, int b, int c)
{
    switch (a)
    {
    case 1:
        cout << "# ";
        break;
    case 2:
        cout << "$ ";
        break;
    case 3:
        cout << "% ";
        break;
    }
    switch (b)
    {
    case 1:
        cout << "# ";
        break;
    case 2:
        cout << "$ ";
        break;
    case 3:
        cout << "% ";
        break;
    }
    switch (c)
    {
    case 1:
        cout << "# ";
        break;
    case 2:
        cout << "$ ";
        break;
    case 3:
        cout << "% ";
        break;
    }
}

int main()
{
    srand (time(NULL));
    int portfel = 10;
    while (portfel > 0)
    {
        cout << "Posiadasz " << portfel << " zl" << endl;
        int pula;
        pula = zaklad (portfel);
        while (pula > portfel)
        {
            cout << "Nie masz tyle srodkow" << endl;
            pula = zaklad (portfel);
        }
        cout << "Pociagnij dzwignie" << endl;
        cin.get();
        int los_1; int los_2; int los_3;
        los_1 = los (1, 3);
        los_2 = los (1, 3);
        los_3 = los (1, 3);
        wynik (los_1, los_2, los_3);
        cin.get();
        if ((los_1 == 1 && los_2 == 1 && los_3 == 1) || (los_1 == 3 && los_2 == 3 && los_3 == 3))
        {
            portfel += (pula * 3);
        }
        else if (los_1 == 2 && los_2 == 2 && los_3 == 2)
        {
            portfel += (pula * 10);
        }
        else if ((los_1 == 2 && los_2 == 2) || (los_1 == 2 && los_3 == 2) || (los_2 == 2 && los_3 == 2))
        {
            portfel += pula;
        }
        else if (los_1 == 2 || los_2 == 2 || los_3 == 2)
        {
            portfel = portfel;
        }
        else
        {
            portfel -= pula;
        }
        //cout << endl << "Posiadasz " << portfel << " zl" << endl << endl;
        if (portfel == 0)
        {
            cout << "Brak srodkow do dalszej gry" << endl;
            return 0;
        }
        /*cout << "Kontynuujesz gre?" << endl << "t - tak" << endl << "n - nie" << endl;
        char kontynuacja;
        cin >> kontynuacja;
        czystka();
        switch (kontynuacja)
        {
        case 'n':
            return 0;
            break;
        case 't':
            cout << "Powodzenia!" << endl << endl;
            break;
        default:
            cout << "Brak decyzji? Wiec grasz dalej!";
            break;
        }*/
    }
}
