#include <iostream>
#include <string>
#include "include/effolkronium/random.hpp"
#include "Pet.h"
#include "PetSorter.h"

using namespace std;

void PrintPetArray(Pet**, int);

int main() {

	int petArrayLength = 10;

	// Allocate memory for an array
	Pet** petPointersArray = new Pet * [petArrayLength];
	for (int i = 0; i < petArrayLength; i++) {
		petPointersArray[i] = new Pet();
	}

	// Fill the array
	for (int i = 0; i < petArrayLength; i++) {
		petPointersArray[i]->FillRandom();
	}

	cout << endl << "--- Start of unsorted array ---" << endl << endl;
	PrintPetArray(petPointersArray, petArrayLength);
	cout << endl << "^^^ End of unsorted array ^^^" << endl << endl;



	int option;
	int orderOption;

	loop:

	cout << "1 - sort by name" << endl;
	cout << "2 - sort by birth year" << endl;
	cout << "3 - sort by veterinary pass" << endl;
	cout << "Enter sorting option: " << endl;
	cin >> option;

	cout << endl;

	cout << "1 - Ascending order" << endl;
	cout << "2 - Descending order" << endl;
	cout << "Enter order option: " << endl;
	cin >> orderOption;

	cout << endl;
	
	bool isAscending = (orderOption == 1) ? true : false;

	PetSorter petSorter;
	petSorter.SortByOption(petPointersArray, petArrayLength, option, isAscending);
	

	
	cout << endl << "--- Start of sorted array ---" << endl << endl;
	PrintPetArray(petPointersArray, petArrayLength);
	cout << endl << "^^^ End of sorted array ^^^" << endl << endl;
	
	
	goto loop;


	for (int i = 0; i < petArrayLength; i++) {
		delete petPointersArray[i];
	}
	delete[] petPointersArray;

	return 0;
}


void PrintPetArray(Pet** firstElem, int arrayLength) {
	for (int i = 0; i < arrayLength; i++) {
		firstElem[i]->PrintInfo();
	}
}



