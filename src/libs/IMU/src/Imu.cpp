#include <imu/Imu.h>
#include <cmath>
namespace imu { bool isUsable(const Sample& sample) { return nav::finite(sample.acceleration_mps2) && nav::finite(sample.angular_rate_radps) && std::isfinite(sample.time_s); } }
