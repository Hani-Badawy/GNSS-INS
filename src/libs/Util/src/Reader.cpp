#include "util/Reader.h"
#include <iostream>
#include <fstream>

Reader::Reader(std::string fileName)
{
	file = std::ifstream(fileName,std::ios::binary);
}

SatData Reader::readEpoch(double time)
{
	SatData data;
	data.setPrn(readChar());
	data.setPseudorange(readDouble());
	data.setPseudorangeRate(readDouble());
	data.setAzimuth(readDouble());
	data.setElevation(readDouble());
	data.setX(readDouble());
	data.setY(readDouble());
	data.setZ(readDouble());
	data.setVx(readDouble());
	data.setVy(readDouble());
	data.setVz(readDouble());
	data.setTime(time);
	return data;
}

char Reader::readChar()
{
	char value=0;
	file.read(reinterpret_cast<char*>(&value), sizeof(char));
	return value;
}

int Reader::readInt()
{
	int value=0;
	file.read(reinterpret_cast<char*>(&value), sizeof(int));
	return value;
}

double Reader::readDouble()
{
	double value = 0.0;
	file.read(reinterpret_cast<char*>(&value), sizeof(double));
	return value;
}

Reader::~Reader() {
	file.close();
}
