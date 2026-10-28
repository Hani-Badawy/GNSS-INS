add_library(SensorFusion STATIC src/Kalman1D.cpp include/fusion/Kalman1D.h)
target_include_directories(SensorFusion PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
set_target_properties(SensorFusion PROPERTIES FOLDER "libs")
