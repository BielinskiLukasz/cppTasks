#include <iostream>
using namespace std;
int main ()
{
    int odp = 1;
    double suma_1 = 0;
    double suma_2 = 0;
    double suma_3 = 0;
    while (odp != 0)
    {
        cout << "Czy lubisz jablka?" << endl;
        cout << "1 - tak" << endl << "2 - nie" << endl << "3 - nie wiem" << endl;
        cout << "Wybierz jedna z odpowiedzi: ";
        cin >> odp;
        if (odp == 1)
            suma_1++;
        else if (odp == 2)
            suma_2++;
        else if (odp ==3)
            suma_3++;
        else if (odp == 0)
        {
            cout << suma_1 << " ankietowanych lubi jablka" << endl;
            cout << suma_2 << " ankietowanych nie lubi jablek" << endl;
            cout << suma_3 << " ankietowanych nie ma zdania" << endl << endl;
            cout << "Wykres slupkowy" << endl;
            double suma_max;
            if (suma_1 > suma_2 && suma_1 > suma_3)
                suma_max = suma_1;
            else if (suma_2 > suma_3)
                suma_max = suma_2;
            else
                suma_max = suma_3;
            cout << "Odp 1\t";
            double slupek_1 = (suma_1/suma_max)*40+1;
            for (int i=0; i<=slupek_1; i++)
            {
                cout << "#";
            }
            cout << " " << suma_1 << endl;
            cout << "Odp 2\t";
            double slupek_2 = (suma_2/suma_max)*40+1;
            for (int i=0; i<=slupek_2; i++)
            {
                cout << "#";
            }
            cout << " " << suma_2 << endl;
            cout << "Odp 3\t";
            double slupek_3 = (suma_3/suma_max)*40+1;
            for (int i=0; i<=slupek_3; i++)
            {
                cout << "#";
            }
            cout << " " << suma_3 << endl;
        }
    }
    return 0;
}
