cmake_minimum_required(VERSION 3.25)
project(GNSS_INS VERSION 0.1.0 LANGUAGES C CXX)
add_subdirectory(3rdparty/eigen EXCLUDE_FROM_ALL)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
option(GNSS_INS_BUILD_TESTS "Build unit tests" ON)
option(GNSS_INS_BUILD_TOOLS "Build command-line tools" ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
include(CTest)
add_subdirectory(src)
# Find Python and NumPy
find_package(Python3 REQUIRED
    COMPONENTS Interpreter Development NumPy
)

# Header-only matplotlib-cpp
add_library(matplot INTERFACE)

target_include_directories(matplot
    INTERFACE
        "${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/matplot"
)

target_link_libraries(matplot
    INTERFACE
        Python3::Python
        Python3::NumPy
)