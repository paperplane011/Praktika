#include "PetSorter.h"
#include "Pet.h"
#include <string>
#include <iostream>



void PetSorter::SortByOption(Pet** firstElem, int arrayLength, int option, bool isAscending) {

	enum sortOption {name, year, vetPass};
	sortOption curSortOption;

	// ѕредставл€ем option как enum дл€ удобночитаемого кода 
	// и чтобы исключить веро€тность ошибок
	switch (option) {
	case 1:
		curSortOption = name;
		break;
	case 2:
		curSortOption = year;
		break;
	case 3:
		curSortOption = vetPass;
		break;
	default:
		throw new exception("Invalid argument");
	}


	int maxElemIndex = -1;
	Pet* buffer;

	for (int lastElem = arrayLength - 1; lastElem != 0; lastElem--) {

		maxElemIndex = -1;

		for (int i = 0; i <= lastElem; i++) {

			// ѕри первой итерации указываем первый элемент как максимальный
			if (maxElemIndex == -1) {
				maxElemIndex = i;
				continue;
			}

			// ≈сли встреченное значение меньше максимального, идЄм на следующий цикл
			if (curSortOption == name) {

				if ((firstElem[i]->GetName().compare(firstElem[maxElemIndex]->GetName()) <= 0) ? true : false) {
					continue;
				}
			}
			else if (curSortOption == year) {

				if (firstElem[i]->GetBirthYear() <= firstElem[maxElemIndex]->GetBirthYear()) {
					continue;
				}
			}
			else if (curSortOption == vetPass) {

				if (firstElem[i]->GetVetPass() < firstElem[maxElemIndex]->GetVetPass()) {
					continue;
				}
			}

			// ≈сли встреченное значение больше максимального, записываем его индекс как максимальный
			maxElemIndex = i;
		}

		// ѕослдений элемент мен€ем местами с максимальным
		buffer = firstElem[lastElem]; 
		firstElem[lastElem] = firstElem[maxElemIndex];  
		firstElem[maxElemIndex] = buffer; 
	}


	if (!isAscending) {
		Reverse(firstElem, arrayLength);
	}

}


void PetSorter::Reverse(Pet** firstElem, int arrayLength) {
	
	Pet* buffer;

	int limit = (arrayLength % 2 == 0) ? arrayLength / 2 : arrayLength / 2 - 1;

	for (int i = 0; i < limit; i++) {
		buffer = firstElem[i];
		firstElem[i] = firstElem[arrayLength - i - 1];
		firstElem[arrayLength - i - 1] = buffer;
	}
}






