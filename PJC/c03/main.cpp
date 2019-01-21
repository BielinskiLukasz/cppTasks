#include <iostream>

using std::cout, std::endl;

void pointersToVariable();

void pointersToPointers();

void fruits();

/**
 * Dany utwór powstał w wyniku realizowania procesu edukacyjnego w PJATK.
 */
int main() {
    //I. Przedstaw deklaracje zmiennych typów char, double i int, po czym utwórz wskazniki do tych zmiennych.
    // Nastepnie wyswietl na ekranie wszystkie zadeklarowane zmienne.
    char a = 'b';
    double c = 1.2;
    int d = 3;

    char *e = &a;
    double *f = &c;
    int *g = &d;

    cout << "char " << a << " char* " << e << endl; // wskaźnik char pokazuje ciąg znaków (tablica znaków, jeżeli jest
    // to pojedynczy znak to pokazuje dany znak oraz kolejne znaki aż do osiągnięcia długości wskaźnika char
    // (zależne od kompilatora)
    cout << "double " << c << " double* " << f << endl;
    cout << "int " << d << " int* " << g << endl;

    //II. Przedstaw program w którym dwa wskazniki (ptr1 i ptr2) beda pokazywały te sama zmienna. Nastepnie zmodyfikuj
    // wartosc wskazywana przez zmienna ptr1 i wyswietl zmienna i wartosci wskazywane przez wskazniki.
    pointersToVariable();

    //III. Zadeklaruj zmienna typu int o nazwie wrt, wskaznik do zmiennej wrt o nazwie ptr1 i wskaznik do zmiennej ptr1
    // o nazwie ptr2. Wyswietl wartosci i stany wszystkich utworzonych zmiennych.
    pointersToPointers();

    //IV. Zadeklaruj typ wyliczeniowy opisujacy owoce, natepnie przedstaw deklaracje zmiennych, ich inicjacje
    // i wyswietlenie wartosci.
    fruits();

    //V. Dany jest ciag znaków “fantasmagoria” przechowywany w zmiennej tab. Utwórz wskazniki ptr1 i ptr2 pokazujace
    // odpowiednio pierwszy i ostatni znak ciagu tab. Nastepnie wypisz na ekranie wyniki operacji matematycznych + i -.


    //VI. Dana jest statyczna tablica zmiennych typu char o rozmiarze 100 elementów. Napisz program, który wprowadzi
    // do tej tablicy dowolny (nieseparowalny znakami białymi) ciag znaków wprowadzony z klawiatury. Nastepnie
    // dla kazdego znaku z wprowadzonego ciagu znajdzie wszystkie kolejne wystapienia znaków o tej samej wartosci,
    // utworzy do nich wskazniki i wypisze na ekran odległosci w postaci:
    //  a0 - a11 -> odległosc 5.


    //VII. Zaimplementuj funkcje int mystrlen(char*) zwracajaca długosc dostarczonego ciagu znaków. Program powinien
    // przedstawiac wykorzystanie arytmetyki wskazników.


    //VIII. Zaimplementuj funkcje bool isPalindrom(char*) zwracajaca wartosc 1 jezeli dostarczony ciag znaków
    // jest palindromem lub 0 w przeciwnym przypadku.


    //IX. Dany jest wskaznik do ciagu znaków “Ala ma kota, a kot ma ale”. Napisz program przedstawiajacy działanie
    // funkcji która:
    // podzieli ciag na wyrazy,
    // kazdy z wyrazów przechowa w oddzielnej tablicy znaków,
    // wszystkie wyrazy przechowa w oddzielnej tablicy słów zwracanej jako wynik funkcji.
    //W całym programie mozna wykorzystywac jedynie funkcje zaimplementowane przez siebie, ponadto do tablic mozna
    // odwołac sie jedynie za pomoca wskazników.


}

void pointersToVariable() {
    int wrt = 2;
    int *ptr1 = &wrt;
    int *ptr2 = &wrt;

    cout << "value " << wrt << " - pointer1 " << *ptr1 << " & pointer2 " << *ptr2 << endl;
    wrt = 5;
    cout << "value " << wrt << " - pointer1 " << *ptr1 << " & pointer2 " << *ptr2 << endl;
}

void pointersToPointers() {
    int wrt = 2;
    int *ptr1 = &wrt;
    int **ptr2 = &ptr1;

    cout << "value " << wrt << endl;
    cout << "pointer1 " << ptr1 << " - value " << *ptr1 << endl;
    cout << "pointer2 " << ptr2 << " - value " << *ptr2 << " & deeper value " << **ptr2 << endl;
}

void fruits() {
    enum fruit {
        orange = 0, apple = 1, pineapple = 2, pear = 3, banana = 4
    };

    fruit jablko = apple;
    fruit banan = orange;
    banan = banana;

    cout << "jablko - " << jablko << " & banan - " << banana << endl;
}
