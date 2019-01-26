#include <iostream>

using std::cout, std::cin, std::endl;

void unions();

void structs();

struct Element {
    char *imie;
    Element *next;
};

Element *get_new_element();

void insert(Element *element);

void show();

void sorted_stricts();

void insert_and_sort(Element *element);

void struct_vs_class();

/**
 * Dany utwór powstał w wyniku realizowania procesu edukacyjnego w PJATK.
 */
int main() {
    //I. Wykorzystujac technike tworzenia unii, zdefiniuj typ złozony ze zmiennych typów int i long double. Nastepnie
    // wykonaj ponizsze operacje:
    // utwórz zmienna zdefiniowanej unii,
    // zainicjuj ja zmienna typu int,
    // wyswietl na ekran rozmiar utworzonej zmiennej i wartosc pól unii,
    // zainicjuj unie zmienna typu long double,
    // wyswietl na ekran rozmiar utworzonej zmiennej i wartosc pól unii.
    unions();

    //II. Utwórz strukture Element o polach char* imie i Element next. Utwórz zmienna Element* lista, której poczatkowa
    // wartoscia bedzie 0. Nastepnie utwórz funkcje:
    // Element* getNewElement() – pobierajaca z klawiatury wartosci zmiennej imie i opakowujaca ja w strukture typu
    //      Element;
    // void insert(Element*) – znajdujaca element listy z polem next równym 0, któremu przypisze argument z jakim
    //      została wywołana;
    // void show() – wyswietajaca wszystkie elementy znajdujace sie w zmiennej lista.
    // W funkcji main petla nieskonczona bedzie powtarzac nastepujace kroki: getNewElement, insert, show, itd.
    structs();

    //III. Wykorzystujac rezultat poprzedniego zadania zadbaj, aby dodawane Elementy były sortowane rosnaco.
    sorted_stricts();

    //IV. Zadeklaruj typy złozone z pól char* imie, int wiek i bool plec wykorzystujac:
    // technike tworzenia struktur,
    // technike tworzenia klas.
    //  Nastepnie utwórz obiekty tych typów i odwołaj sie do ich pól. Jaka jest róznica pomiedzy tymi odwołaniami?
    struct_vs_class();
}

void unions() {
    union Number {
        int wrtInt;
        double wrtDouble;
    };

    Number sample;

    sample.wrtInt = 1;
    cout << "Union size: " << sizeof(sample) << ", int: " << sample.wrtInt << ", double: " << sample.wrtDouble << endl;

    sample.wrtDouble = 2.3;
    cout << "Union size: " << sizeof(sample) << ", int: " << sample.wrtInt << ", double: " << sample.wrtDouble << endl;
}

void structs() {
    cout << "How many elements will be added?" << endl;
    int element_number;
    cin >> element_number;

    for (int i = 0; i < element_number; i++) {
        Element *new_element = get_new_element();
        insert(new_element);
        show();
    }
}

Element *lista = 0;

Element *get_new_element() {
    cout << "Type element name: " << endl;
    char *input_data = new char[20];
    cin >> input_data;

    Element *element = new Element{input_data, 0};

    return element;
}

void insert(Element *element) {
    if (lista == 0) {
        lista = element;
    } else {
        Element *last_element = lista;
        while (last_element->next != 0) {
            last_element = last_element->next;
        }
        last_element->next = element;
    }
}

void show() {
    Element *element = lista;
    cout << endl << element->imie << endl;

    while (element->next != nullptr) {
        element = element->next;
        cout << element->imie << endl;
    }
}

void sorted_stricts() {
    cout << "How many elements will be added and sorted?" << endl;
    int element_number;
    cin >> element_number;

    for (int i = 0; i < element_number; i++) {
        Element *new_element = get_new_element();
        insert_and_sort(new_element);
        show();
    }
}

void insert_and_sort(Element *element) {
    if (lista == 0) {
        lista = element;
    } else if (lista->next == 0) {
        if (*(lista->imie) > *(element->imie)) {
            lista->next = element;
        } else {
            Element *tmp = lista;
            lista = element;
            element->next = tmp;
        }
    } else if (*(lista->imie) < *(element->imie)) {
        Element *tmp = lista;
        lista = element;
        element->next = tmp;
    } else {
        Element *last_element = lista->next;
        Element *previous = lista;

        while (last_element->next != 0 && *(last_element->imie) > *(element->imie)) {
            previous = previous->next;
            last_element = last_element->next;
        }

        if (last_element->next == 0 && *(last_element->imie) > *(element->imie)) {
            last_element->next = element;
        } else {
            previous->next = element;
            element->next = last_element;
        }
    }
}

void struct_vs_class() {
    struct Osoba_struct {
        char imie[20];
        int wiek;
        bool plec;
    };

    class Osoba_class {
    public:
        char imie[20];
        int wiek;
        bool plec;
    };

    Osoba_struct Magda = {"Magda", 26, true};
    Osoba_class Lukasz = {"Lukasz", 26, false};

    cout << Magda.imie << " " << Magda.wiek << endl;
    cout << "Kobieta? " << Magda.plec << endl;
    cout << Lukasz.imie << " " << Lukasz.wiek << endl;
    cout << "Kobieta? " << Lukasz.plec << endl;
}
