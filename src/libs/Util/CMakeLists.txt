file(GLOB UTIL_FILES CONFIGURE_DEPENDS
    "src/*.cpp"
    "include/util/*.h"
)
add_library(Util STATIC ${UTIL_FILES})
target_include_directories(Util PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(Util PUBLIC NavCore IMU GNSS)
set_target_properties(Util PROPERTIES FOLDER "libs")
