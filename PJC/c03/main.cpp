#include <iostream>

using std::cout, std::endl, std::cin;

void pointers_to_variable();

void pointers_to_pointers();

void fruits();

void fantasmagoria();

int string_length(const char *tab);

void doubles_distances();

long mystrlen(char *tab);

int is_palindrom(char *word);

char **split(char *sentence);

void print_words(char **word, int size);

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
    pointers_to_variable();

    //III. Zadeklaruj zmienna typu int o nazwie wrt, wskaznik do zmiennej wrt o nazwie ptr1 i wskaznik do zmiennej ptr1
    // o nazwie ptr2. Wyswietl wartosci i stany wszystkich utworzonych zmiennych.
    pointers_to_pointers();

    //IV. Zadeklaruj typ wyliczeniowy opisujacy owoce, natepnie przedstaw deklaracje zmiennych, ich inicjacje
    // i wyswietlenie wartosci.
    fruits();

    //V. Dany jest ciag znaków “fantasmagoria” przechowywany w zmiennej tab. Utwórz wskazniki ptr1 i ptr2 pokazujace
    // odpowiednio pierwszy i ostatni znak ciagu tab. Nastepnie wypisz na ekranie wyniki operacji matematycznych + i -.
    fantasmagoria();

    //VI. Dana jest statyczna tablica zmiennych typu char o rozmiarze 100 elementów. Napisz program, który wprowadzi
    // do tej tablicy dowolny (nieseparowalny znakami białymi) ciag znaków wprowadzony z klawiatury. Nastepnie
    // dla kazdego znaku z wprowadzonego ciagu znajdzie wszystkie kolejne wystapienia znaków o tej samej wartosci,
    // utworzy do nich wskazniki i wypisze na ekran odległosci w postaci:
    //  a0 - a11 -> odległosc 5.
    doubles_distances();

    //VII. Zaimplementuj funkcje int mystrlen(char*) zwracajaca długosc dostarczonego ciagu znaków. Program powinien
    // przedstawiac wykorzystanie arytmetyki wskazników.
    char tab[11] = "0123456789";
    cout << tab << " length is " << mystrlen(tab) << endl;

    //VIII. Zaimplementuj funkcje bool isPalindrom(char*) zwracajaca wartosc 1 jezeli dostarczony ciag znaków
    // jest palindromem lub 0 w przeciwnym przypadku.
    char word[100];
    cout << "Type word: ";
    cin >> word;
    cout << "Word " << word << " is" << (is_palindrom(word) ? "" : "n't") << " palindrome" << endl;

    //IX. Dany jest wskaznik do ciagu znaków “Ala ma kota, a kot ma ale”. Napisz program przedstawiajacy działanie
    // funkcji która:
    // podzieli ciag na wyrazy,
    // kazdy z wyrazów przechowa w oddzielnej tablicy znaków,
    // wszystkie wyrazy przechowa w oddzielnej tablicy słów zwracanej jako wynik funkcji.
    // W całym programie mozna wykorzystywac jedynie funkcje zaimplementowane przez siebie, ponadto do tablic mozna
    // odwołac sie jedynie za pomoca wskazników.
    char sentence[100] = "Ala ma kota, a kot ma ale";
    char **words = split(sentence);
    print_words(words, 7);
}

void pointers_to_variable() {
    int wrt = 2;
    int *ptr1 = &wrt;
    int *ptr2 = &wrt;

    cout << "value " << wrt << " - pointer1 " << *ptr1 << " & pointer2 " << *ptr2 << endl;
    wrt = 5;
    cout << "value " << wrt << " - pointer1 " << *ptr1 << " & pointer2 " << *ptr2 << endl;
}

void pointers_to_pointers() {
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
    fruit banan;
    banan = banana;

    cout << "jablko - " << jablko << " & banan - " << banan << endl;
}

void fantasmagoria() {
    char tab[14] = "fantasmagoria";
    char *ptr1 = tab;
    char *ptr2 = tab + string_length(tab) - 1;

    cout << "ptr1: " << ptr1 << "; ptr2: " << ptr2 << endl;
    cout << "ptr2 - ptr1: " << ptr2 - ptr1;
}

int string_length(const char *tab) {
    int char_counter = 0;
    while (tab[char_counter++]);
    return --char_counter;
}

void doubles_distances() { // TODO learn
    char tab[100];
    cout << "Type chars (max 100): ";
    cin >> tab;

    char *ptr1 = tab;
    while (*ptr1) {
        char *ptr2 = ptr1 + 1;
        while (*ptr2) {
            if (*ptr1 == *ptr2) {
                cout << "Distance between " << *ptr1 << " and " << *ptr2 << " is " << ptr2 - ptr1 << endl;
            }
            ptr2++;
        }
        ptr1++;
    }
}

long mystrlen(char *tab) {
    char *temp = tab;
    while (*temp++);
    return --temp - tab;
}

int is_palindrom(char *word) {
    char *ptr = word + mystrlen(word) - 1;
    do
        if (*word != *ptr)
            return 0;
    while (ptr++ < word--);
    return 1;
}

char **split(char *sentence) {
    static char *result[6]{};
    int i = 0;

    *(result + i++) = *&sentence;

    while (*sentence) {
        if (*sentence == ' ') {
            *sentence = '\0';
            sentence++;
            *(result + i++) = *&sentence;
        } else if (*sentence == ',') {
            *sentence = '\0';
            sentence++;
        } else
            sentence++;
    }

    return result;
}

void print_words(char **word, int size) {
    for (int i = 0; i < size; i++) {
        cout << *(word + i) << endl;
    }
}
