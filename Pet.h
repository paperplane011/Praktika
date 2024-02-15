#pragma once

#include <string>

using namespace std;

class Pet
{
	string name;
	int birthYear;
	bool hasVetPass;

public:
	Pet();
	Pet(string, int, bool);
	string GetName();
	int GetBirthYear();
	bool GetVetPass();
	void PrintInfo();
	void FillRandom();
};

