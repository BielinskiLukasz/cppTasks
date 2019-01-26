#include <iostream>

using std::cout, std::endl, std::cin;

void comment();

void find_max();

int max(int num1, int num2, int num3);

void sign_number_change_counter();

void select_car_color();

enum color_lexus {
    black = 1, red, green, blue, white
};

enum color_lexus select_color();

void hello_in_loops();

/**
 * Dany utwór powstał w wyniku realizowania procesu edukacyjnego w PJATK.
 */
int main() {
    //I. Utworz funkcje main wyswietlajaca napis “Hello” (wykorzystaj biblioteke iostream).
    cout << "Hello" << endl;

    //II. Przedstaw w programie 3 metody zaznaczenia kodu, który bedzie traktowany jak komentarz.
    comment();

    //III. W funkcji main zdefiniuj wszystkie typy proste wystepujace w jezyku C++. Nastepnie napisz program łaczacy
    // wszystkie zmienne w jeden ciag wyjsciowy i wyswietl go na ekranie.
    short a = 1;
    int b = 2;
    long c = 3;
    double d = 4.5;
    float e = 6.7;
    char f = 'g';
    bool i = true;

    cout << a << b << c << d << e << f << i << endl;

    //IV. Napisz program wczytujacy z konsoli trzy liczby i wypisujaacy na ekranie najwieksza z nich. Mozna uzyc
    // najwyzej dwóch if-ów (bez fraz else lub else if).
    find_max();

    //V. Napisz program wczytujacy liczby całkowite az do pojawienia sie zera i wypisujacy na ekranie ile razy znak
    // dwóch kolejno wczytanych liczb był rózny.
    sign_number_change_counter();

    //VI. Wykorzystujac mozliwosc definiowania typu wylicznikowego napisz program pozwalajacy uzytkownikowi wybrac
    // kolor nadwozia dla dwóch samochodów: Forda T i Lexusa.
    select_car_color();

    //VII. Nalezy napisac program, który wczyta wartosc z klawiatury i przechowa ja w zmiennej wrt. Nastepnie uzywajac
    // wszystkich znanych rodzajów petli wyswietli na ekranie napis “Hello” powtarzajac go tyle razy ile okresla
    // wartosc wrt. Program bedzie nieskonczenie powtarzał powyzsze operacje. Nalezy zadbac aby zapis wszystkich petli
    // był optymalnie skondensowany.
    hello_in_loops();
}

void comment() {
    // first
    /* second */
#if(0)
    third
#endif
}

void find_max() {
    int num1, num2, num3;
    cout << "Type 3 integers: ";
    cin >> num1 >> num2 >> num3;
    cout << "Max num is " << max(num1, num2, num3) << endl;
}

int max(int num1, int num2, int num3) {
    int tmp = num1;
    if (tmp < num2) tmp = num2;
    if (tmp < num3) tmp = num3;

    return tmp;
}

void sign_number_change_counter() {
    double new_real = 0, old_real = 0;
    int counter = 0;
    do {
        cout << "Type real numbers (0 number will end stream): ";
        if (old_real / new_real < 0) counter++;
        old_real = new_real;
        cin >> new_real;
    } while (new_real);

    cout << "Number sigh change " << counter << " times" << endl;
}

void select_car_color() { // TODO learn!!!
    enum color_ford_t {
        black
    } fordT = black;

    enum color_lexus lexus;
    lexus = select_color();

    cout << "FordT - " << fordT << "; Lexus - " << lexus << endl;
}

enum color_lexus select_color() {
    int choose;

    do {
        cout << endl << "Type lexus color: " << endl <<
             black << " - black" << endl <<
             red << " - red" << endl <<
             green << " - green" << endl <<
             blue << " - blue" << endl <<
             white << " - white" << endl;
        cin >> choose;
        switch (choose) {
            case 1:
                return black;
            case 2:
                return red;
            case 3:
                return green;
            case 4:
                return blue;
            case 5:
                return white;
            default:
                choose = 0;
                break;
        }
    } while (!choose);
}

void hello_in_loops() {
    int wrt;
    cout << "Type how many hello must print each loop: ";
    cin >> wrt;

    for (int i = 0; i < wrt; ++i) {
        cout << "Hello from for" << endl;
    }

    int counter = 0;
    while (wrt > counter++) {
        cout << "Hello from while" << endl;
    }
    counter--;

    if (wrt) {
        do {
            cout << "Hello from do-while" << endl;
        } while (--counter);
    }
}
