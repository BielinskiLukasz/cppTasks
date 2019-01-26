#include <iostream>

using std::cout, std::cin, std::endl;

void unions();

void structs();

struct Element {
    char *imie;
    Element *next;
};

Element *getNewElement();

void insert(Element *element);

void show();

void sortedStricts();

void insertAndSort(Element *pElement);

void structVsClass();

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
    sortedStricts();

    //IV. Zadeklaruj typy złozone z pól char* imie, int wiek i bool plec wykorzystujac:
    // technike tworzenia struktur,
    // technike tworzenia klas.
    //  Nastepnie utwórz obiekty tych typów i odwołaj sie do ich pól. Jaka jest róznica pomiedzy tymi odwołaniami?
    structVsClass();
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
    int elementNumber;
    cin >> elementNumber;

    for (int i = 0; i < elementNumber; i++) {
        Element *newElement = getNewElement();
        insert(newElement);
        show();
    }
}

Element *lista = 0;

Element *getNewElement() {
    cout << "Type element name: " << endl;
    char *inputData = new char[20];
    cin >> inputData;

    Element *element = new Element{inputData, 0};

    return element;
}

void insert(Element *element) {
    if (lista == 0) {
        lista = element;
    } else {
        Element *lastElement = lista;
        while (lastElement->next != 0) {
            lastElement = lastElement->next;
        }
        lastElement->next = element;
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

void sortedStricts() {
    cout << "How many elements will be added and sorted?" << endl;
    int elementNumber;
    cin >> elementNumber;

    for (int i = 0; i < elementNumber; i++) {
        Element *newElement = getNewElement();
        insertAndSort(newElement);
        show();
    }
}

void insertAndSort(Element *element) {
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
        Element *lastElement = lista->next;
        Element *previous = lista;

        while (lastElement->next != 0 && *(lastElement->imie) > *(element->imie)) {
            previous = previous->next;
            lastElement = lastElement->next;
        }

        if (lastElement->next == 0 && *(lastElement->imie) > *(element->imie)) {
            lastElement->next = element;
        } else {
            previous->next = element;
            element->next = lastElement;
        }
    }
}

void structVsClass() {
    struct OsobaStruct {
        char imie[20];
        int wiek;
        bool plec;
    };

    class OsobaClass {
    public:
        char imie[20];
        int wiek;
        bool plec;
    };

    OsobaStruct Magda = {"Magda", 26, true};
    OsobaClass Lukasz = {"Lukasz", 26, false};

    cout << Magda.imie << " " << Magda.wiek << endl;
    cout << "Kobieta? " << Magda.plec << endl;
    cout << Lukasz.imie << " " << Lukasz.wiek << endl;
    cout << "Kobieta? " << Lukasz.plec << endl;
}
