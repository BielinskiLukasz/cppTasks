#include <iostream>
using namespace std;
int main ()
{

}

int f ()
{
    for (int i=0; i<5; i++)
    {
        cout << "Podaj haslo: ";
        int haslo = 0;
        cin >> haslo;
        if (haslo == 1111)
            {
                cout << "Witaj";
                break;
            }
        else if (i<3)
            cout << "Pozostalo " << 4-i << " prob" << endl;
        else if (i==3)
            cout << "Pozostala " << 4-i << " proba" << endl;
    }
    return 0;
}

int w ()
{
    int i = 0;
    while (i<5)
    {
        cout << "Podaj haslo: ";
        int haslo = 0;
        cin >> haslo;
        if (haslo == 1111)
            {
                cout << "Witaj";
                break;
            }
        else if (i<3)
            cout << "Pozostalo " << 4-i << " prob" << endl;
        else if (i==3)
            cout << "Pozostala " << 4-i << " proba" << endl;
        i++;
    }
    return 0;
}

int d ()
{
    int i = 0;
    do
    {
        cout << "Podaj haslo: ";
        int haslo = 0;
        cin >> haslo;
        if (haslo == 1111)
            {
                cout << "Witaj";
                break;
            }
        else if (i<3)
            cout << "Pozostalo " << 4-i << " prob" << endl;
        else if (i==3)
            cout << "Pozostala " << 4-i << " proba" << endl;
        i++;
    } while (i<5);
    return 0;
}
