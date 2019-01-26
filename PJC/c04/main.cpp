#include <iostream>

using std::cout, std::endl, std::cin;

void arrays();

void show(int *tab[3], int tabSize, int innerTabSize);

void pointerAndReference();

void dynamicArray();

long mystrlen(char *tab);

void copyArray(const char *src, char *des, int size);

void multipleWords();

void printWords(char **, int);

void intFun();

void fun1(int wtr);

void fun2(int *wtr);

void fun3(int &wtr);

void charFun();

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
    pointerAndReference();

    //III. Dana jest globalna tablica zmiennych typu char o rozmiarze 100 elementów i nazwie inputData. Uzywajac
    // operatora cin wprowadzamy do tej tablicy ciag znaków. Nastepnie okreslamy ilosc wprowadzonych znaków i tworzymy
    // dedykowana, dynamicznie tworzona tablice o rozmiarze dopasowanym do długosci wprowadzonego słowa.
    dynamicArray();

    //IV. Program z poprzedniego punktu nalezy wzbogacic o dynamicznie tworzona tablice przechowujaca wskazniki
    // do wszystkich wprowadzonych słów. Wprowadzenie kolejnego słowa bedzie skutkowac wyswietleniem wszystkich
    // wprowadzonych do tej pory słów. Jezeli w tablicy brakuje miejsca na kolejne słowa nalezy zwiekszyc rozmiar
    // dotychczasowej tablicy dwukrotnie.
    multipleWords();

    //V. Utwórz funkcje fun1, fun2 i fun3, które jako parametr beda przyjmowac odpowiednio int, wskaznik i odnosnik.
    // Celem wszystkich funkcji bedzie wyswietlenie wartosci dostarczonych jako parametry, inkrementacja tych wartosci
    // i ponowne wyswietlenie.
    // W funkcji main:
    // zadeklaruj i zainicjuj zmienna wrt typu int,
    // wyswietl jej wartosc na ekran,
    // wywołaj funkcje fun1, fun2 i fun3 dostarczajac jako parametr wrt,
    // ponownie wyswietl wartosc zmiennej wrt.2
    intFun();

    //VI. Funkcja fun otrzyma jako parametry char& i char* do dwóch ciagów znaków. Zadaniem tej funkcji bedzie
    // znalezienie najdłuzszego podciagu. Jako wynik wyswietlone zostana wskazniki na poczatek i koniec najdłuzszego
    // podciagu.
    charFun();
}

void arrays() {
    int tab1[3]{1, 2, 3};
    int tab2[3] = {4, 5, 6};
    int tab3[] = {7, 8, 9};

    int *tab[]{tab1, tab2, tab3};

    show(tab, 3, 3);
}

void show(int *tab[3], int tabSize, int innerTabSize) {
    for (int i = 0; i < tabSize; i++) {
        for (int j = 0; j < innerTabSize; j++) {
            cout << *(*(tab + i) + j) << endl;
        }
    }
}

void pointerAndReference() { // TODO learn
    int i = 5;
    int *ptr = &i;
    int *&ref = ptr;

    int **tab[] = {&ptr, &ref};

    cout << ***tab << endl
         << ***(tab + 1) << endl;
}

void dynamicArray() {
    char inputData[100];
    cout << "Input data: " << endl;
    cin >> inputData;
    long arraySize = mystrlen(inputData);

    char *dynamicTab = new char[arraySize + 1];
    copyArray(inputData, dynamicTab, arraySize);
    cout << dynamicTab << endl;
    delete[] dynamicTab;
}

long mystrlen(char *tab) {
    char *temp = tab;
    while (*temp++);
    return --temp - tab;
}

void copyArray(const char *src, char *des, int size) {
    for (int i = 0; i < size; i++) {
        *(des + i) = *(src + i);
    }
    *(des + size) = '\0';
}

void multipleWords() {
    int dynamicTabOfTabsSize = 1;
    char **dynamicTabOfTabs = new char *[dynamicTabOfTabsSize];

    int wordsCounter = 0;
    char inputData[100];
    cout << "Input data: " << endl;
    cin >> inputData;

    while (*inputData != '0') {
        long arraySize = mystrlen(inputData);

        char *dynamicTab = new char[arraySize + 1];
        copyArray(inputData, dynamicTab, arraySize);

        if (wordsCounter >= dynamicTabOfTabsSize) {
            dynamicTabOfTabsSize *= 2;
            char **newTab = new char *[dynamicTabOfTabsSize];
            for (int i = 0; i < dynamicTabOfTabsSize / 2; i++)
                newTab[i] = dynamicTabOfTabs[i];
            delete[] dynamicTabOfTabs;
            dynamicTabOfTabs = newTab;
        }
        dynamicTabOfTabs[wordsCounter++] = dynamicTab;
        printWords(dynamicTabOfTabs, wordsCounter);

        cout << "Input data: " << endl;
        cin >> inputData;
    }

    cout << "Array size " << dynamicTabOfTabsSize << endl
         << "words in " << wordsCounter;
    for (int i = 0; i < wordsCounter; i++) {
        delete dynamicTabOfTabs[i];
    }
    delete[] dynamicTabOfTabs;
}

void printWords(char **words, int counter) {
    for (int i = 0; i < counter; i++) {
        cout << words[i] << endl;
    }
}

void intFun() {
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

void charFun() {
    char *shortSentence = "It's short, isn't it?";
    char *longSentence = "It's long sentence, isn't it?";

    fun(*shortSentence, longSentence);
}

void fun(char &arg1, char *arg2) {
    long arg1Length = mystrlen(&arg1);
    cout << "Size of first arg is " << arg1Length << endl;
    long arg2Length = mystrlen(arg2);
    cout << "Size of second arg is " << arg2Length << endl;

    char *longestSentence = arg1Length > arg2Length ? &arg1 : arg2;
    long longestSize = arg1Length > arg2Length ? arg1Length : arg2Length;

    char *startOfLongestSentence = longestSentence;
    char *endOfLongestSentence = (longestSentence + longestSize - 1);

    cout << "Longest sentence is " << longestSentence << " with size " << longestSize << endl
         << "Starts: " << startOfLongestSentence << endl
         << "Ends: " << endOfLongestSentence << endl;
}
