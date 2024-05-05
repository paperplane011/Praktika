#include <iostream>
#include <string>
#include <fstream>
#include "include/effolkronium/random.hpp"
#include "Pet.h"
#include "PetSorter.h"

using namespace std;

void PrintPetArray(Pet**, int);

int main() {

	int petArrayLength;
	Pet** petPointersArray = new Pet*;


	// get fill option
	
	int fillOption;

	cout << "1 - fill by hand" << endl;
	cout << "2 - fill by file" << endl;
	cout << "3 - fill by random" << endl;
	cout << "Enter fill option: " << endl;
	cin >> fillOption;
	

	// fill array

	// if option needs length input
	if (fillOption == 1 || fillOption == 3) {


		cout << "Enter array length: " << endl;
		cin >> petArrayLength;

		petPointersArray = new Pet * [petArrayLength];
		for (int i = 0; i < petArrayLength; i++) {
			petPointersArray[i] = new Pet();
		}

		if (fillOption == 1) {
			for (int i = 0; i < petArrayLength; i++) {
				petPointersArray[i]->Input();
			}
		}
		else
		{
			for (int i = 0; i < petArrayLength; i++) {
				petPointersArray[i]->FillRandom();
			}
		}

	}
	else if (fillOption == 2) { // if option doesn't need length input
		ifstream petListFile("PetList.txt");
		string line;
		char delimeter = ',';

		if (petListFile.is_open()) {

			// allocate memory

			int petListFilePetCount = 0;

			while (getline(petListFile, line)) {
				petListFilePetCount++;
			}

			petPointersArray = new Pet * [petListFilePetCount];
			for (int i = 0; i < petListFilePetCount; i++) {
				petPointersArray[i] = new Pet();
			}

			petArrayLength = petListFilePetCount;

			// read file & fill array

			int petIndex = 0;
			int leftBorder = 0;

			string newName;
			int newBirthYear;
			bool newHasVetPass;

			petListFile.clear();
			petListFile.seekg(0);

			while (getline(petListFile, line)) {
				
				leftBorder = 0;

				for (int i = 0; i < 3; i++) {

					int delimIndex = line.find(delimeter, leftBorder);

					string substr = line.substr(leftBorder, delimIndex);

					leftBorder = delimIndex + 1;

					if (i == 0) {
						newName = substr;
						cout << "new name: " << newName << endl;
					}
					else if (i == 1) {
						newBirthYear = stoi(substr);
						cout << "new year: " << newBirthYear << endl;
					}
					else if (i == 2) {
						newHasVetPass = stoi(substr) == 1 ? true : false;
						cout << "new pass: " << newHasVetPass << endl;

						petPointersArray[petIndex]->Set(newName, newBirthYear, newHasVetPass);
						petIndex++;
					}
				}
			}


		}


		petListFile.close();
	}




	cout << endl << "--- Start of unsorted array ---" << endl << endl;
	PrintPetArray(petPointersArray, petArrayLength);
	cout << endl << "^^^ End of unsorted array ^^^" << endl << endl;


	// get sorting option

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


	// sort

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



