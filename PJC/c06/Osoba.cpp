//
// Created by Lukasz on 2019-01-26.
//

#include <iostream>

using std::cout, std::endl;

class Osoba {

protected:
    //I. Przygotuj klase Osoba z polami char* imie i int wiek. Nastepnie utwórz dwa obiekty zdefiniowanej klasy,
    // uzywajac konstruktorów wykorzystujacych mechanizmy: dynamicznego alokowania pamieci oraz lokalnej definicji.
    char *imie;
    int wiek;

public:
    //II. Rozwin definicje klasy Osoba o konstruktory:
    // pusty – wprowadzajacy wartosci pól do dynamicznie alokowanych zasobów,
    // przyjmujacy dwa parametry (char*, int) – inicjujacy pola przez liste inicjacyjna.
    // Oba z konstruktorów powinny wyswietlic na ekranie informacje o utworzeniu obiektu Osoba. Dodefiniuj destruktor,
    // wyswietlajacy informacje o zniszczeniu obiektu i zwalniajacy dynamicznie za alokowane zasoby. W ciele funkcji
    // main przedstaw tworzenie obiektów powyzszej klasy z uzyciem obu typów konstruktorów.
    Osoba(char *imie, int wiek) : wiek(wiek) {
        //Rozwiązanie problemu, że po zmianie tablicy dostarczanej jako argument do obiektu zmienia się również
        // parametr obiektu (gdyż w przypisaniu do tablicy jak wiek tworzono by wskaźnik na zewnętrzną tablicę)
        this->imie = copy_name(imie);

        constructor_info();
    }

    void show() {
        cout << imie << endl;
    }

    Osoba() : imie("nobody"), wiek(0) {
        constructor_info();
    }

    ~Osoba() {
        deconstructor_info();
        delete imie;
    }

    //III. Wykorzystujac operator new, utwórz obiekt klasy Osoba i uzywajac funkcji show wyswietl zawarte w nim pola.
    // Utwórz odnosnik ref do tego obiektu, a nastepnie utwórz nowy obiekt klasy Osoba dostarczajac jako parametr
    // konstruktora odnosnika ref. Ponownie wyswietl stany pól wszystkich utworzonych obiektów. Usun pierwszy z
    // utworzonych obiektów i wyswietl stan pól pozostałego obiektu.
    Osoba(Osoba &o) : wiek(o.wiek) {
        this->imie = copy_name(o.imie);

        constructor_info();
    }

private:
    void constructor_info() {
        cout << imie << " created" << endl;
    }

    void deconstructor_info() {
        cout << imie << " deleted" << endl;
    }

    char *copy_name(char* name) {
        int tmp_size = strlen(name) + 1;
        char *tmp = new char[tmp_size];
        strcpy_s(tmp, tmp_size, name);

        return tmp;
    };
};
