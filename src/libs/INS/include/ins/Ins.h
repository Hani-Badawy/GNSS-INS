#pragma once
#include <navcore/Types.h>
#include <imu/Imu.h>
namespace ins {
// Educational Cartesian constant-acceleration integration only.
// No attitude rotation, gravity, Coriolis, or Earth model yet.
nav::PositionVelocity propagate(nav::PositionVelocity state, const imu::Sample& sample, double dt_s);
}
