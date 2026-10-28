#include <gnss/LSQSolver.h>
#include <matplotlibcpp.h>
namespace plt = matplotlibcpp;
int main() {
    std::string file = "D:/Data.bin";
    LSQSolver solver(file);
    solver.batchSolve();
}
