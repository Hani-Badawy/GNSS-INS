#pragma once
namespace fusion {
struct Estimate1D { double value{}; double variance{1.0}; };
Estimate1D update(Estimate1D prior, double measurement, double measurement_variance);
}
