#pragma once

#include <string>


class NameGenerator {

	static int const MIN_NAME_LENGTH;
	static int const MAX_NAME_LENGTH;

	char GetRandomChar();

public:
	std::string GetRandomName();

};