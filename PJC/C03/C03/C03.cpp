// C03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int mystrlen(char*);
bool isPalindrom(char*);
//char[][] task9(char*);

int main()
{
	//Task01
	std::cout << std::endl << "TASK 01" << std::endl;
	char exampleChar = 'a';
	double exampleDouble = 1.5;
	int exampleInt = 1;

	char * exampleCharPointer = &exampleChar;
	double * exampleDoublePointer = &exampleDouble;
	int * exampleIntPointer = &exampleInt;

	std::cout << "char: " << exampleChar << std::endl << "double: " << exampleDouble << std::endl <<
		"int: " << exampleInt << std::endl << "char pointer: " << exampleCharPointer << std::endl <<
		"double pointer: " << exampleDoublePointer << std::endl << "int pointer: " <<
		exampleIntPointer << std::endl;

	//Task02
	std::cout << std::endl << "TASK 02" << std::endl;
	int * ptr1 = &exampleInt;
	int * ptr2 = &exampleInt;
	exampleInt = 2;
	std::cout << "prt1: " << *ptr1 << " - " << ptr1 << std::endl <<
		"prt2: " << *ptr2 << " - " << ptr2 << std::endl;

	//Task03
	std::cout << std::endl << "TASK 03" << std::endl;
	int wrt = 1;
	ptr1 = &wrt;
	int ** ptr3 = &ptr1;
	std::cout << "wrt: " << wrt << std::endl <<
		"prt1: " << *ptr1 << " - " << ptr1 << std::endl <<
		"prt3: " << *ptr3 << " - " << ptr3 << std::endl;

	//Task04
	std::cout << std::endl << "TASK 04" << std::endl;
	enum fruit { apple = 1, pineapple = 2, pear = 3, banana = 4, orange = 5 };
	fruit apple1 = apple;
	std::cout << apple1 << std::endl;

	//Task05
	std::cout << std::endl << "TASK 05" << std::endl;
	char tab[] = "fantasmagoria";
	char * ptr4 = &tab[0];
	char * ptr5 = &tab[12];
	std::cout << " - : " << ptr5 - ptr4 << " + : " << (int)ptr4 + (int)ptr5 << std::endl;

	//Task06
	std::cout << std::endl << "TASK 06" << std::endl;
	std::cout << "Podaj ciąg znaków (max 100): " << std::endl;
	int const tableSize = 100;
	char tab2[tableSize]{};
	std::cin >> tab2;
	for (int i = 0; i < tableSize; i++) {
		for (int j = i + 1; j < tableSize; j++) {
			if (tab2[i] == tab2[j] && tab2[i] != '\0') {
				std::cout << tab2[i] << "_" << i << " - " << tab2[j] << "_" << j << " -> odleglosc " << 
					(char*) &tab2[j] - (char*) &tab2[i] << std::endl;
			}
		}
	}

	//Task07
	std::cout << std::endl << "TASK 07" << std::endl;
	char tab3[] = "a123456789";
	char* ptr6 = tab3;
	std::cout << "Size of " << tab3 << " is 10, function mystrlen return " << mystrlen(ptr6) << std::endl;

	//Task08
	std::cout << std::endl << "TASK 08" << std::endl;
	std::cout << std::endl << "Ignored white symbols and upper/lowet case issues" << std::endl;
	char tab4[] = "alamakota";
	char* ptr7 = tab4;
	char tab5[] = "kobyłamamałybok";
	char* ptr8 = tab5;
	std::cout << "Is palindrom - " << isPalindrom(ptr8) << std::endl;
	std::cout << "Isn't palindrom - " << isPalindrom(ptr7) << std::endl;

	//Task09
	std::cout << std::endl << "TASK 09" << std::endl;
	char tab6[] = "Ala ma kota, a kot ma ale";
	char* ptr9 = tab6;
	char results[10][10];
	int length = mystrlen(ptr9);

	for (int i = 0, j = 0, k = 0; i < length + 1; i++) {
		if (*(ptr9 + i) == ' ' || *(ptr9 + i) == ',' || *(ptr9 + i) == '\0') {
			results[k][j++] = '\0';
			if (*(ptr9 + i) != ',') {
				j = 0;
				k++;
			}
		}
		else {
			results[k][j++] = *(ptr9 + i);
		}
	}	

	for (int i = 0; i < 7; i++) {
		std::cout << results[i] << std::endl;
	}

}

int mystrlen(char* charTablePointer) {
	int counter = 0;
	while (*(charTablePointer + counter) != '\0') {
		counter++;
	}
	return counter;
}

bool isPalindrom(char* charTablePointer) {
	int length = mystrlen(charTablePointer);
	for (int i = 0; i < length / 2; i++) {
		if (*(charTablePointer + i) != *(charTablePointer + length - i - 1)) {
			return 0;
		}
	}
	return 1;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
