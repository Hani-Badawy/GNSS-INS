#pragma once
#include <cmath>
namespace nav {
struct Vec3 { double x{}, y{}, z{}; };
inline bool finite(Vec3 v) { return std::isfinite(v.x) && std::isfinite(v.y) && std::isfinite(v.z); }
struct PositionVelocity { Vec3 position_m{}; Vec3 velocity_mps{}; };
}
