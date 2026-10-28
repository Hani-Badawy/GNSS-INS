add_library(IMU STATIC src/Imu.cpp include/imu/Imu.h)
target_include_directories(IMU PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(IMU PUBLIC NavCore)
set_target_properties(IMU PROPERTIES FOLDER "libs")
