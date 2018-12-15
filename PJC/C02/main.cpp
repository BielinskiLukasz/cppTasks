#include <iostream>

int max(int a, int b, int c);

enum color {
    white = 1, black = 2, red = 3, blue = 4, grey = 5
};

enum color selectColor();

int main() {
    //Task01
    std::cout << std::endl << "TASK 01" << std::endl;
    std::cout << "Hello\n";

    //Task02
    std::cout << std::endl << "TASK 02" << std::endl;
    // some line comment

    /*
        and
        more line commment too
    */

#if(0)
    other comment
#endif

    //Task03
    std::cout << std::endl << "TASK 03" << std::endl;
    char exampleChar = 'a';
    short exampleShort = 0;
    int exampleInt = 1;
    long exampleLong = 2;
    float exampleFloat = 4.5;
    double exampleDouble = 5.5;
    bool exampleBool = true;
    //exampleInt = exampleBool;

    std::cout << exampleBool << exampleChar << exampleDouble << exampleFloat << exampleInt << exampleLong <<
              exampleShort << std::endl;

    //Task04
    std::cout << std::endl << "TASK 04" << std::endl;
    std::cout << std::endl << "Type 3 numbers: ";
    int num1, num2, num3;
    std::cin >> num1 >> num2 >> num3;
    std::cout << max(num1, num2, num3);

    //Task05
    std::cout << std::endl << "TASK 05" << std::endl;
    std::cout << std::endl << "Type numbers: ";
    double num = 0;
    double oldNum = 0;
    double counter = 0;
    do {
        if (num * oldNum < 0) counter++;
        oldNum = num;
        std::cin >> num;
    } while (num);
    std::cout << counter;

    //Task06
    std::cout << std::endl << "TASK 06" << std::endl;
    enum color fordT, lexus;
    fordT = black;
    lexus = selectColor();

    //Task07
    std::cout << std::endl << "TASK 07" << std::endl;
    while (true) {
        int wrt = 0;
        std::cout << "Type number of Hello: ";
        std::cin >> wrt;
        for (int i = 0; i < wrt; i++) {
            std::cout << "Hello" << std::endl;
        }
        int counter = 0;
        if (wrt > 0)
            do {
                std::cout << "Hello" << std::endl;
            } while (++counter < wrt);
        while (counter-- > 0) {
            std::cout << "Hello" << std::endl;
        }
    }
}

int max(int a, int b, int c) {
    int tmp = a;
    if (b > tmp) tmp = b;
    if (c > tmp) tmp = c;
    return tmp;
}

enum color selectColor() {
    std::cout << std::endl << "Type car color: " << std::endl <<
              "1 - white" << std::endl <<
              "2 - black" << std::endl <<
              "3 - red" << std::endl <<
              "4 - blue" << std::endl <<
              "5 - grey" << std::endl;
    int choise;
    std::cin >> choise;
    switch (choise) {
        case white:
            return white;
        case black:
            return black;
        case red:
            return red;
        case blue:
            return blue;
        case grey:
            return grey;
        default:
            break;
    }
}