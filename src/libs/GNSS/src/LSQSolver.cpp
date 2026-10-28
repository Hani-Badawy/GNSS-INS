#include "gnss/LSQSolver.h"
#include <util/Reader.h>
#include <util/Converter.h>
#include <cmath>
#include <iostream>
#include <iomanip>
LSQSolver::LSQSolver(std::string fileName)
{
	Reader reader(fileName);
	time = reader.readDouble();
	size = (int)reader.readChar();
	for (int i = 0; i < size; i++)
	{
		SatData satData = reader.readEpoch(time);
		dataset.push_back(satData);
	}

}

void LSQSolver::batchSolve()
{
	size = dataset.size();
	psuedoranges.resize(size);
	sat_positions.resize(size, 3);
	for (int i = 0; i < size; i++)
	{
		psuedoranges(i) = dataset[i].getPseudorange();
		sat_positions(i, 0) = dataset[i].getX();
		sat_positions(i, 1) = dataset[i].getY();
		sat_positions(i, 2) = dataset[i].getZ();
	}


	states(0) = 0;
	states(1) = 0;
	states(2) = 0;
	states(3) = 0.0;
	states *= 0;
	Eigen::Vector4d dx;
	dx.Ones();
	dx *= 10;
	while (dx(Eigen::seq(0, 2)).norm() > 1e-14 && std::abs(dx(3) / C) > 1e-14)
	{
		Eigen::VectorXd dz = misclosure();
		Eigen::MatrixXd H = designMatrix();
		Eigen::MatrixXd R = observation_cov(5);
		Eigen::MatrixXd P = H.transpose() * R.inverse() * H;
		dx = P.inverse() * H.transpose() * R.inverse() * dz;
		states += dx;
		std::cout << states(Eigen::seq(0, 2)) << '\n' << states(3) / C << "\n";
	}
	std::vector<double> lph = Converter::xyz2lph(states(0), states(1), states(2));
	std::cout<<std::setprecision(9) << lph[0] << '\t' << lph[1] << '\t' << lph[2] << '\t' << std::endl;
}
std::vector<double> LSQSolver::getStates()
{
	std::vector<double> result;
	return result;
}

Eigen::MatrixXd LSQSolver::designMatrix()
{
	Eigen::MatrixXd result(size, 4);
	for (int i = 0; i < size; i++)
	{
		std::vector<double> row;
		for (int j = 0; j < 3; j++)
			result(i, j) = (states(j) - sat_positions(i, j)) / psuedoranges(i);
		result(i, 3) = 1.0;
	}
	return result;
}

Eigen::MatrixXd LSQSolver::observation_cov(double sigma)
{
	Eigen::MatrixXd result(size, size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			result(i, j) = i == j ? sigma : 0;
		}
	}

	return result;
}

Eigen::VectorXd LSQSolver::misclosure()
{
	Eigen::VectorXd result(size);
	for (int i = 0; i < size; i++)
	{
		double dx = std::pow(states[0] - sat_positions(i, 0), 2);
		double dy = std::pow(states[1] - sat_positions(i, 1), 2);
		double dz = std::pow(states[2] - sat_positions(i, 2), 2);
		double dt = states[3] - time;
		result[i] = psuedoranges[i] - (std::sqrt(dx + dy + dz) + dt);
	}
	return result;
}

