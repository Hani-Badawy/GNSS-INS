#pragma once
#include <vector>
#include <string>
#include <Eigen/Dense>
#include <util/SatData.h>
const double C = 299792458;
class LSQSolver
{
public:
	LSQSolver(std::string fileName);
	void batchSolve();
	std::vector<double> getStates();

private:
	Eigen::MatrixXd designMatrix();
	Eigen::MatrixXd observation_cov(double sigma);
	Eigen::VectorXd misclosure();
	Eigen::Vector4d states;
	int size;
	Eigen::VectorXd psuedoranges;
	Eigen::MatrixXd sat_positions;
	std::vector<SatData> dataset;
	double time;
};
