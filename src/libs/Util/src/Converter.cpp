#include "util/Converter.h"
#include <cmath>
#include <numbers>
const double A = 6378137.0;
const double B = 6356752.31425;
std::vector<double> Converter::xyz2lph(double x, double y, double z)
{
	std::vector<double> result{ std::numbers::pi / 2.0,0,0};
	double e2 = (std::pow(A,2) - std::pow(B, 2)) / std::pow(A, 2);
	double p = std::sqrt(std::pow(x, 2) + std::pow(y, 2));
	if (p <= 1.0e-6)
	{
		result[0] *= z > 0 ? 1 : -1;
		result[1] = 0.0;
		result[2] = abs(z) - B;
	}
	else
	{
		double N0 = 0;
		double h0 = 0;
		double phi = atan(z / (p * (1 - e2)));
		double N1 = A/(std::sqrt(1.0 - e2 * (std::pow(std::sin(phi),2))));
		double h1 = p /cos(phi) - N1;
		phi = atan((z / p) / (1 - e2 * N1 / (N1 + h1)));
		while (abs(N1 - N0) >= 0.01 && abs(h1 - h0) >= 0.01)
		{
			N0 = N1;
			h0 = h1;
			N1 = A / (std::sqrt(1.0 - e2 * (std::pow(std::sin(phi), 2))));
			h1 = p / cos(phi) - N1;
			phi = atan((z / p) / (1 - e2 * N1 / (N1 + h1)));
		}
		result[0] = phi * 180.0/ std::numbers::pi;
		result[1] = atan2(y, x) * 180.0/ std::numbers::pi;
		result[2] = h1;
	}
	return result;
}
