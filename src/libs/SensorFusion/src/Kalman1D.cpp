#include <fusion/Kalman1D.h>
#include <cmath>
#include <stdexcept>
namespace fusion {
Estimate1D update(Estimate1D prior, double measurement, double measurement_variance) {
    if (!std::isfinite(prior.value) || !std::isfinite(prior.variance) || prior.variance < 0 || !std::isfinite(measurement) || !std::isfinite(measurement_variance) || measurement_variance <= 0)
        throw std::invalid_argument("invalid Kalman inputs");
    const double k = prior.variance / (prior.variance + measurement_variance);
    return {prior.value + k * (measurement - prior.value), (1.0 - k) * prior.variance};
}
}
