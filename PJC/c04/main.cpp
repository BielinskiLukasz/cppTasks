#include <iostream>

using std::cout, std::endl, std::cin;

void arrays();

void show(int *tab[3], int tab_size, int inner_tab_size);

void pointer_and_reference();

void dynamic_array();

long mystrlen(char *tab);

void copy_array(const char *src, char *des, int size);

void multiple_words();

void print_words(char **, int);

void int_fun();

void fun1(int wtr);

void fun2(int *wtr);

void fun3(int &wtr);

void char_fun();

void fun(char &arg1, char *arg2);

/**
 * Dany utwór powstał w wyniku realizowania procesu edukacyjnego w PJATK.
 */
int main() {
    //I. Utwórz trzy tablice o rozmiarze 3 elementów i wypełnij je dowolnymi wartosciami. Nastepnie przygotuj
    // trzyelementowa tablice wskazników, której elementy beda wskazywały tablice z liczbami. Napisz funkcje show
    // wyswietlajaca na ekranie wartosci wszystkich tablic.
    arrays();

    //II. Zdefiniuj zmienna typu int i zainicjuj ja wartoscia “5”. Nastepnie utwórz wskaznik do tej zmiennej. Potem
    // utwórz odnosnik do zdefiniowanego wskaznika. Nastepnie przygotuj dwuelementowa tablice, której elementami beda
    // wskazniki na przygotowany wskaznik i odnosnik. Wreszcie wypisz na ekran wartosc zmiennej int posługujac sie
    // zadeklarowana tablica.
    pointer_and_reference();

    //III. Dana jest globalna tablica zmiennych typu char o rozmiarze 100 elementów i nazwie inputData. Uzywajac
    // operatora cin wprowadzamy do tej tablicy ciag znaków. Nastepnie okreslamy ilosc wprowadzonych znaków i tworzymy
    // dedykowana, dynamicznie tworzona tablice o rozmiarze dopasowanym do długosci wprowadzonego słowa.
    dynamic_array();

    //IV. Program z poprzedniego punktu nalezy wzbogacic o dynamicznie tworzona tablice przechowujaca wskazniki
    // do wszystkich wprowadzonych słów. Wprowadzenie kolejnego słowa bedzie skutkowac wyswietleniem wszystkich
    // wprowadzonych do tej pory słów. Jezeli w tablicy brakuje miejsca na kolejne słowa nalezy zwiekszyc rozmiar
    // dotychczasowej tablicy dwukrotnie.
    multiple_words();

    //V. Utwórz funkcje fun1, fun2 i fun3, które jako parametr beda przyjmowac odpowiednio int, wskaznik i odnosnik.
    // Celem wszystkich funkcji bedzie wyswietlenie wartosci dostarczonych jako parametry, inkrementacja tych wartosci
    // i ponowne wyswietlenie.
    // W funkcji main:
    // zadeklaruj i zainicjuj zmienna wrt typu int,
    // wyswietl jej wartosc na ekran,
    // wywołaj funkcje fun1, fun2 i fun3 dostarczajac jako parametr wrt,
    // ponownie wyswietl wartosc zmiennej wrt.2
    int_fun();

    //VI. Funkcja fun otrzyma jako parametry char& i char* do dwóch ciagów znaków. Zadaniem tej funkcji bedzie
    // znalezienie najdłuzszego podciagu. Jako wynik wyswietlone zostana wskazniki na poczatek i koniec najdłuzszego
    // podciagu.
    char_fun();
}

void arrays() {
    int tab1[3]{1, 2, 3};
    int tab2[3] = {4, 5, 6};
    int tab3[] = {7, 8, 9};

    int *tab[]{tab1, tab2, tab3};

    show(tab, 3, 3);
}

void show(int *tab[3], int tab_size, int inner_tab_size) {
    for (int i = 0; i < tab_size; i++) {
        for (int j = 0; j < inner_tab_size; j++) {
            cout << *(*(tab + i) + j) << endl;
        }
    }
}

void pointer_and_reference() { // TODO learn
    int i = 5;
    int *ptr = &i;
    int *&ref = ptr;

    int **tab[] = {&ptr, &ref};

    cout << ***tab << endl
         << ***(tab + 1) << endl;
}

void dynamic_array() {
    char input_data[100];
    cout << "Input data: " << endl;
    cin >> input_data;
    long array_size = mystrlen(input_data);

    char *dynamic_tab = new char[array_size + 1];
    copy_array(input_data, dynamic_tab, array_size);
    cout << dynamic_tab << endl;
    delete[] dynamic_tab;
}

long mystrlen(char *tab) {
    char *temp = tab;
    while (*temp++);
    return --temp - tab;
}

void copy_array(const char *src, char *des, int size) {
    for (int i = 0; i < size; i++) {
        *(des + i) = *(src + i);
    }
    *(des + size) = '\0';
}

void multiple_words() {
    int dynamic_tab_of_tabs_size = 1;
    char **dynamic_tab_of_tabs = new char *[dynamic_tab_of_tabs_size];

    int words_counter = 0;
    char input_data[100];
    cout << "Input data: " << endl;
    cin >> input_data;

    while (*input_data != '0') {
        long arraySize = mystrlen(input_data);

        char *dynamic_tab = new char[arraySize + 1];
        copy_array(input_data, dynamic_tab, arraySize);

        if (words_counter >= dynamic_tab_of_tabs_size) {
            dynamic_tab_of_tabs_size *= 2;
            char **newTab = new char *[dynamic_tab_of_tabs_size];
            for (int i = 0; i < dynamic_tab_of_tabs_size / 2; i++)
                newTab[i] = dynamic_tab_of_tabs[i];
            delete[] dynamic_tab_of_tabs;
            dynamic_tab_of_tabs = newTab;
        }
        dynamic_tab_of_tabs[words_counter++] = dynamic_tab;
        print_words(dynamic_tab_of_tabs, words_counter);

        cout << "Input data: " << endl;
        cin >> input_data;
    }

    cout << "Array size " << dynamic_tab_of_tabs_size << endl
         << "words in " << words_counter;
    for (int i = 0; i < words_counter; i++) {
        delete dynamic_tab_of_tabs[i];
    }
    delete[] dynamic_tab_of_tabs;
}

void print_words(char **words, int counter) {
    for (int i = 0; i < counter; i++) {
        cout << words[i] << endl;
    }
}

void int_fun() {
    int wtr = 0;
    cout << "Before " << wtr << endl;
    fun1(wtr);
    cout << "After fun1 " << wtr << endl;
    fun2(&wtr);
    cout << "After fun2 " << wtr << endl;
    fun3(wtr);
    cout << "After fun3 " << wtr << endl;
}

void fun1(int wtr) {
    cout << "fun 1 before " << wtr << endl;
    wtr++;
    cout << "fun1 after " << wtr << endl;
}

void fun2(int *wtr) {
    cout << "fun 2 before " << *wtr << endl;
    (*wtr)++;
    cout << "fun2 after " << *wtr << endl;
}

void fun3(int &wtr) {
    cout << "fun 3 before " << wtr << endl;
    wtr++;
    cout << "fun3 after " << wtr << endl;
}

void char_fun() {
    char *short_sentence = "It's short, isn't it?";
    char *long_sentence = "It's long sentence, isn't it?";

    fun(*short_sentence, long_sentence);
}

void fun(char &arg1, char *arg2) {
    long arg1_length = mystrlen(&arg1);
    cout << "Size of first arg is " << arg1_length << endl;
    long arg2_length = mystrlen(arg2);
    cout << "Size of second arg is " << arg2_length << endl;

    char *longest_sentence = arg1_length > arg2_length ? &arg1 : arg2;
    long longest_size = arg1_length > arg2_length ? arg1_length : arg2_length;

    char *start_of_longest_sentence = longest_sentence;
    char *end_of_longest_sentence = (longest_sentence + longest_size - 1);

    cout << "Longest sentence is " << longest_sentence << " with size " << longest_size << endl
         << "Starts: " << start_of_longest_sentence << endl
         << "Ends: " << end_of_longest_sentence << endl;
}
