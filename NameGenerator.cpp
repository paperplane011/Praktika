#include <string>
#include <cctype> // toupper()
#include "include/effolkronium/random.hpp"
#include "NameGenerator.h"

using Random = effolkronium::random_static;
using namespace std;


int const NameGenerator::MIN_NAME_LENGTH = 4;
int const NameGenerator::MAX_NAME_LENGTH = 9;

char NameGenerator::GetRandomChar() {
	return (char)Random::get<int>(97, 122);
}

string NameGenerator::GetRandomName() {
	
	string randomName = "";
	int nameLength = Random::get<int>(MIN_NAME_LENGTH, MAX_NAME_LENGTH);

	for (int i = 0; i < nameLength; i++) {
		randomName += GetRandomChar();
	}

	randomName[0] = toupper(randomName[0]);

	return randomName;
}







