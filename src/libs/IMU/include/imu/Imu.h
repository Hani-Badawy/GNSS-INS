#pragma once
#include <navcore/Types.h>
namespace imu {
struct Sample { nav::Vec3 acceleration_mps2; nav::Vec3 angular_rate_radps; double time_s{}; };
bool isUsable(const Sample& sample);
}
