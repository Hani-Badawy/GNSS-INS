#pragma once
#include <navcore/Types.h>
namespace gnss {
struct Fix { nav::Vec3 position_ecef_m; double time_s{}; bool valid{}; };
bool isUsable(const Fix& fix);
}
