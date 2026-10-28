#include "util/SatData.h"

void SatData::setPrn(char prn)
{
this->prn = prn;
}

void SatData::setPseudorange(double range)
{
	this->pseudorange = range;
}

void SatData::setPseudorangeRate(double rangeRate)
{
	this->pseudorangeRate = rangeRate;
}

void SatData::setAzimuth(double azimuth)
{
	this->azimuth = azimuth;
}

void SatData::setElevation(double elevation)
{
	this->elevation = elevation;
}

void SatData::setX(double x)
{
	this->x = x;
}

void SatData::setY(double y)
{
	this->y= y;
}

void SatData::setZ(double z)
{
	this->z = z;
}

void SatData::setVx(double vx)
{
	this->vx= vx;
}

void SatData::setVy(double vy)
{
	this->vy=vy;
}

void SatData::setVz(double vz)
{
	this->vz=vz;
}

void SatData::setTime(double time)
{
	this->time = time;
}

char SatData::getPrn() const
{
	return prn;
}

double SatData::getPseudorange() const
{
	return pseudorange;
}

double SatData::getPseudorangeRate() const
{
	return pseudorangeRate;
}

double SatData::getAzimuth() const
{
	return azimuth;
}

double SatData::getElevation() const
{
	return elevation;
}

double SatData::getX() const
{
	return x;
}

double SatData::getY() const
{
	return y;
}

double SatData::getZ() const
{
	return z;
}

double SatData::getVx() const
{
	return vx;
}

double SatData::getVy() const
{
	return vy;
}

double SatData::getVz() const
{
	return vz;
}

double SatData::getTime() const
{
	return time;
}
