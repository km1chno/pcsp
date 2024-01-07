cmake_minimum_required(VERSION 3.10)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
  CACHE STRING "Vcpkg toolchain file")
set(CMAKE_CXX_STANDARD 20)

# Specify project name
project(PCSP)

# Specify the source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Specify the include directories
include_directories(include)

## External dependencies

# # Matplot++
find_package(Matplot++ CONFIG REQUIRED)

# Boost
find_package(Boost)
include_directories(${Boost_INCLUDE_DIRS})

# Create the executable
add_executable(main ${SOURCES})

target_link_libraries(main PRIVATE Matplot++::cimg  Matplot++::matplot) 
target_link_libraries(main PRIVATE ${Boost_LIBRARIES})

