#include <iostream>
#include "Osoba.cpp"

/**
 * Dany utwór powstał w wyniku realizowania procesu edukacyjnego w PJATK.
 */
int main() {
    //I. Przygotuj klase Osoba z polami char* imie i int wiek. Nastepnie utwórz dwa obiekty zdefiniowanej klasy,
    // uzywajac konstruktorów wykorzystujacych mechanizmy: dynamicznego alokowania pamieci oraz lokalnej definicji.
    char data0[] = "Jan"; //konieczna definicja gdyż kożystamy z char* a nie string ")
    Osoba *osoba0 = new Osoba(data0, 65);

    char data1[] = "Jaś";
    Osoba *osoba1 = new Osoba(data1, 5);

    //II. Rozwin definicje klasy Osoba o konstruktory:
    // pusty – wprowadzajacy wartosci pól do dynamicznie alokowanych zasobów,
    // przyjmujacy dwa parametry (char*, int) – inicjujacy pola przez liste inicjacyjna.
    // Oba z konstruktorów powinny wyswietlic na ekranie informacje o utworzeniu obiektu Osoba. Dodefiniuj destruktor,
    // wyswietlajacy informacje o zniszczeniu obiektu i zwalniajacy dynamicznie za alokowane zasoby. W ciele funkcji
    // main przedstaw tworzenie obiektów powyzszej klasy z uzyciem obu typów konstruktorów.
    Osoba *osoba2 = new Osoba();
    delete osoba0;
    osoba0 = 0;

    //III. Wykorzystujac operator new, utwórz obiekt klasy Osoba i uzywajac funkcji show wyswietl zawarte w nim pola.
    // Utwórz odnosnik ref do tego obiektu, a nastepnie utwórz nowy obiekt klasy Osoba dostarczajac jako parametr
    // konstruktora odnosnika ref. Ponownie wyswietl stany pól wszystkich utworzonych obiektów. Usun pierwszy z
    // utworzonych obiektów i wyswietl stan pól pozostałego obiektu.
    char data3[] = "Kunegunda";
    Osoba *osoba3 = new Osoba(data3, 69);
    osoba3->show();

    Osoba &ref = *osoba3;
    Osoba *osoba4 = new Osoba(*osoba3);
    osoba3->show();
    osoba4->show();

    delete osoba3;
    osoba4->show();

    //IV. Zdefiniuj klase Rachunek zawierajaca pola Osoba wlasciciel (zdefiniowana na poprzednich zajeciach) oraz double
    // stan_konta. Nastepnie utwórz klase Bank przechowujaca obiekty klasy Rachunek i pozwalajaca na wywołanie funkcji:
    // otworzNowyRachunek - tworzaca nowy rachunek dla wskazanego klienta,
    // zmienWlasciciela - modyfikujaca Osobe bedaca włascicielem rachunku,
    // usunRachunek - kasujaca rachunek.
    // W programie nalezy zadbac aby wszystkie obiekty zawierały zdefiniowane i funkcjonalne:
    // konstruktory,
    // destruktory.
    //Przedstaw działanie programu na przykładzie Pana Tomka, który załozył trzy rachunki i wpłacił na nie po 100 zł.
    // Nastepnie jeden rachunek przepisał na małzonke Małgorzate, a drugi usunał. Przy kazdej z tych operacji bank
    // wyswietlał na konsoli wszystkie posiadane rachunki, wraz z imieniem klienta i stanem konta.
    // TODO
}