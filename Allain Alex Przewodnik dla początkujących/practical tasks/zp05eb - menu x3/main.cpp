#include <iostream>
using namespace std;
int main ()
{
    int wybor;
    int popr_wybor = 0;
    while (popr_wybor != 1)
    {
        cout << endl;
        cout << "\t#################################" << endl;
        cout << "\t#\t\tWitaj!\t\t#" << endl;
        cout << "\t#\t1 - Nowa gra\t\t#" << endl;
        cout << "\t#\t2 - Wczytaj gre\t\t#" << endl;
        cout << "\t#\t3 - Opcje\t\t#" << endl;
        cout << "\t#\t4 - Wyjscie\t\t#" << endl;
        cout << "\t#################################" << endl;
        cout << "\tWybierz operacje: ";
        cin >> wybor;
        if (wybor == 1 || wybor == 2 || wybor == 3 || wybor == 4)
        {
            popr_wybor = 1;
        }
        std::cin.clear();
        std::cin.sync();
    }
    return 0;
}

int d ()
{
    int wybor;
    int popr_wybor = 0;
    do
    {
        cout << endl;
        cout << "\t#################################" << endl;
        cout << "\t#\t\tWitaj!\t\t#" << endl;
        cout << "\t#\t1 - Nowa gra\t\t#" << endl;
        cout << "\t#\t2 - Wczytaj gre\t\t#" << endl;
        cout << "\t#\t3 - Opcje\t\t#" << endl;
        cout << "\t#\t4 - Wyjscie\t\t#" << endl;
        cout << "\t#################################" << endl;
        cout << "\tWybierz operacje: ";
        cin >> wybor;
        if (wybor == 1 || wybor == 2 || wybor == 3 || wybor == 4)
        {
            popr_wybor = 1;
        }
        std::cin.clear();
        std::cin.sync();
    } while (popr_wybor != 1);
    return 0;
}
