#include <ins/Ins.h>
#include <stdexcept>
#include <cmath>
namespace ins {
nav::PositionVelocity propagate(nav::PositionVelocity state, const imu::Sample& sample, double dt_s) {
    if (!imu::isUsable(sample) || !std::isfinite(dt_s) || dt_s < 0.0) throw std::invalid_argument("invalid IMU sample or time step");
    const auto a = sample.acceleration_mps2;
    state.position_m.x += state.velocity_mps.x * dt_s + 0.5 * a.x * dt_s * dt_s;
    state.position_m.y += state.velocity_mps.y * dt_s + 0.5 * a.y * dt_s * dt_s;
    state.position_m.z += state.velocity_mps.z * dt_s + 0.5 * a.z * dt_s * dt_s;
    state.velocity_mps.x += a.x * dt_s;
    state.velocity_mps.y += a.y * dt_s;
    state.velocity_mps.z += a.z * dt_s;
    return state;
}
}
