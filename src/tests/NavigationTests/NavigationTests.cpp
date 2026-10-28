#include <gnss/Gnss.h>
#include <imu/Imu.h>
#include <ins/Ins.h>
#include <fusion/Kalman1D.h>
#include <cassert>
#include <cmath>
int main() {
    assert(gnss::isUsable({{1,2,3}, 0, true}));
    assert(!gnss::isUsable({{1,2,3}, 0, false}));
    const auto state = ins::propagate({}, {{2,0,0}, {}, 0}, 2);
    assert(std::abs(state.position_m.x - 4.0) < 1e-12);
    assert(std::abs(state.velocity_mps.x - 4.0) < 1e-12);
    const auto estimate = fusion::update({0, 1}, 10, 1);
    assert(std::abs(estimate.value - 5.0) < 1e-12);
    return 0;
}
