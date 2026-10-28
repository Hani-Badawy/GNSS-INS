add_library(NavCore INTERFACE)
target_include_directories(NavCore INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")
set_target_properties(NavCore PROPERTIES FOLDER "libs")
