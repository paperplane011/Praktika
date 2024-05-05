#include "Pet.h"
#include <iostream>
#include <string>

#include "NameGenerator.h"
#include "include/effolkronium/random.hpp"


using namespace std;
using Random = effolkronium::random_static;


Pet::Pet() {
	this->name = "";
	this->birthYear = -1;
	this->hasVetPass = false;
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

void Pet::Input() {
	cout << endl << "Adding a new pet" << endl;

	cout << "Name: ";
	cin >> this->name;

	cout << "Birth year: ";
	cin >> this->birthYear;
	
	cout << "Has veterinary pass (1 - yes, 0 - no): ";
	cin >> this->hasVetPass;

	cout << endl << "New pet added. " << "Name: " << this->name << ", birth year: " << this->birthYear << ", hasVetPass: " << this->hasVetPass << endl;
}

void Pet::Set(string name, int birthYear, bool hasVetPass) {
	this->name = name;
	this->birthYear = birthYear;
	this->hasVetPass = hasVetPass;
}
