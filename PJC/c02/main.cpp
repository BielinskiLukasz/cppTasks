#include <iostream>

using std::cout, std::endl, std::cin;

void comment();

void findMax();

int max(int num1, int num2, int num3);

void signNumberChangeCounter();

void selectCarColor();

enum colorLexus {
    black = 1, red, green, blue, white
};

enum colorLexus selectColor();

void helloInLoops();

int main() {
    // task01
    // Utworz funkcje main wyswietlajaca napis “Hello” (wykorzystaj biblioteke iostream).
    cout << "Hello" << endl;

    // task02
    // Przedstaw w programie 3 metody zaznaczenia kodu, który bedzie traktowany jak komentarz.
    comment();

    // task03
    // W funkcji main zdefiniuj wszystkie typy proste wystepujace w jezyku C++. Nastepnie napisz program łaczacy
    // wszystkie zmienne w jeden ciag wyjsciowy i wyswietl go na ekranie.
    short a = 1;
    int b = 2;
    long c = 3;
    double d = 4.5;
    float e = 6.7;
    char f = 'g';
    bool i = true;

    cout << a << b << c << d << e << f << i << endl;

    // task04
    // Napisz program wczytujacy z konsoli trzy liczby i wypisujaacy na ekranie najwieksza z nich. Mozna uzyc najwyzej
    // dwóch if-ów (bez fraz else lub else if).
    findMax();

    // task05
    // Napisz program wczytujacy liczby całkowite az do pojawienia sie zera i wypisujacy na ekranie ile razy znak dwóch
    // kolejno wczytanych liczb był rózny.
    signNumberChangeCounter();

    // task06
    // Wykorzystujac mozliwosc definiowania typu wylicznikowego napisz program pozwalajacy uzytkownikowi wybrac kolor
    // nadwozia dla dwóch samochodów: Forda T i Lexusa.
    selectCarColor();

    // task07
    // Nalezy napisac program, który wczyta wartosc z klawiatury i przechowa ja w zmiennej wrt. Nastepnie uzywajac
    // wszystkich znanych rodzajów petli wyswietli na ekranie napis “Hello” powtarzajac go tyle razy ile okresla
    // wartosc wrt. Program bedzie nieskonczenie powtarzał powyzsze operacje. Nalezy zadbac aby zapis wszystkich petli
    // był optymalnie skondensowany.
    helloInLoops();
}

void comment() {
    // first
    /* second */
#if(0)
    third
#endif
}

void findMax() {
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

void signNumberChangeCounter() {
    double newReal = 0, oldReal = 0;
    int counter = 0;
    do {
        cout << "Type real numbers (0 number will end stream): ";
        if (oldReal / newReal < 0) counter++;
        oldReal = newReal;
        cin >> newReal;
    } while (newReal);

    cout << "Number sigh change " << counter << " times" << endl;
}

void selectCarColor() { // TODO learn!!!
    enum colorFordT {
        black
    } fordT = black;

    enum colorLexus lexus;
    lexus = selectColor();

    cout << "FordT - " << fordT << "; Lexus - " << lexus << endl;
}

enum colorLexus selectColor() {
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

void helloInLoops() {
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
