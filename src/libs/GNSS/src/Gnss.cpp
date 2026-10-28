#include <gnss/Gnss.h>
#include <cmath>
namespace gnss {
bool isUsable(const Fix& fix) {
return fix.valid && nav::finite(fix.position_ecef_m) && std::isfinite(fix.time_s);
} 
}
