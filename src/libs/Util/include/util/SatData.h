#pragma once
#include "Data.h"
class SatData :
    public Data
{
public:
    void setPrn(char prn);
    void setPseudorange(double range);
    void setPseudorangeRate(double rangeRate);
    void setAzimuth(double azimuth);
    void setElevation(double elevation);
    void setX(double x);
    void setY(double y);
    void setZ(double z);
    void setVx(double vx);
    void setVy(double vy);
    void setVz(double vz);
    void setTime(double time);
    char getPrn() const;
    double getPseudorange() const;
    double getPseudorangeRate() const;
    double getAzimuth() const;
    double getElevation() const;
    double getX() const;
    double getY() const;
    double getZ() const;
    double getVx() const;
    double getVy() const;
    double getVz() const;
    double getTime() const;
private:
    char prn;
    double pseudorange;
    double pseudorangeRate;
    double azimuth;
    double elevation;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
    double time;
};

