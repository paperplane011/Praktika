#include "Pet.h"
#include <iostream>
#include <string>

#include "NameGenerator.h"
#include "include/effolkronium/random.hpp"


using namespace std;
using Random = effolkronium::random_static;


Pet::Pet() {
	Pet("", 0, 0);
}

Pet::Pet(string name, int birthYear, bool hasVetPass) {
	this->name = name;
	this->birthYear = birthYear;
	this->hasVetPass = hasVetPass;
}

string Pet::GetName() {
	return this->name;
}

int Pet::GetBirthYear() {
	return this->birthYear;
}

bool Pet::GetVetPass() {
	return this->hasVetPass;
}



void Pet::PrintInfo() {
	cout << "------------" << endl;
	cout << "Name: " << this->name << endl;
	cout << "Birth year: " << this->birthYear << endl;
	cout << "Has veterinary pass: " << this->hasVetPass << endl;
	cout << "------------" << endl;
}

void Pet::FillRandom() {
	NameGenerator nameGen;

	this->name = nameGen.GetRandomName();
	this->birthYear = Random::get<int>(1000, 2024);
	this->hasVetPass = Random::get<int>(0, 1);

}
