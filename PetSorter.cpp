#include "PetSorter.h"
#include "Pet.h"
#include <string>
#include <iostream>



void PetSorter::SortByOption(Pet** firstElem, int arrayLength, int option, bool isAscending) {

	enum sortOption {name, year, vetPass};
	sortOption currentSortOption;

	// ѕредставл€ем sortOption как enum дл€ удобночитаемого кода 
	// и чтобы уменьшить веро€тность ошибок
	switch (option) {
	case 1:
		currentSortOption = name;
		break;
	case 2:
		currentSortOption = year;
		break;
	case 3:
		currentSortOption = vetPass;
		break;
	default:
		throw new exception();
	}


	// —ортировка выбором
	// ѕроходим по неотсортированной части массива и ищем максимальный элемент
	// «атем мен€ем местами максимальный элемент с последним элементом неотсортированной части массива

	 
	int maxElemIndex = -1; // maxElemIndex - сюда записываем индекс максимального элемента неотсортиванной части массива
	Pet* buffer;

	// lastElem - последний элемент неотсортиванной части массива
	for (int lastElem = arrayLength - 1; lastElem != 0; lastElem--) {

		maxElemIndex = -1;

		for (int i = 0; i <= lastElem; i++) {

			// ѕри первой итерации указываем первый элемент как максимальный
			if (maxElemIndex == -1) {
				maxElemIndex = i;
				continue;
			}

			// ≈сли встреченное значение меньше максимального, идЄм на следующий цикл
			if (currentSortOption == name) {

				if ((firstElem[i]->GetName().compare(firstElem[maxElemIndex]->GetName()) <= 0) ? true : false) {
					continue;
				}
			}
			else if (currentSortOption == year) {

				if (firstElem[i]->GetBirthYear() <= firstElem[maxElemIndex]->GetBirthYear()) {
					continue;
				}
			}
			else if (currentSortOption == vetPass) {

				if (firstElem[i]->GetVetPass() < firstElem[maxElemIndex]->GetVetPass()) {
					continue;
				}
			}

			// ≈сли встреченное значение больше максимального, записываем его индекс как максимальный
			maxElemIndex = i;
		}

		// ѕоследний элемент мен€ем местами с максимальным, т.е. записываем максимальный элемент в конец
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






