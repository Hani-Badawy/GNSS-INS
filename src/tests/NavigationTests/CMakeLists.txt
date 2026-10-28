add_executable(NavigationTests NavigationTests.cpp)
target_link_libraries(NavigationTests PRIVATE GNSS IMU INS SensorFusion)
set_target_properties(NavigationTests PROPERTIES FOLDER "tests")
add_test(NAME NavigationSmokeTests COMMAND NavigationTests)
