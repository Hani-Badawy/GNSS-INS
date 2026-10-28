add_library(INS STATIC src/Ins.cpp include/ins/Ins.h)
target_include_directories(INS PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(INS PUBLIC NavCore IMU)
set_target_properties(INS PROPERTIES FOLDER "libs")
