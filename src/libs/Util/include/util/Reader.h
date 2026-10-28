#pragma once
#include <string>
#include <fstream>
#include "SatData.h"

class Reader
{
public:
	Reader(std::string fileName);
	~Reader();
	SatData readEpoch(double time);
	char readChar();
	int readInt();
	double readDouble();
private:
	std::string fileName;
	std::ifstream file;
};

