# - Main CMake script for pp6calculator
# Comments in CMake begin with a '#' just like shell and python scripts
#
# - Require latest generation of CMake
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

# - Declare the project
project(pp6calculator)

# - Use standard flag set when using the GNU compiler
if(CMAKE_COMPILER_IS_GNUXX)
  set(CMAKE_CXX_FLAGS "-std=c++98 -pedantic-errors -Wall -Wextra -Werror -Wfatal-errors -Wwrite-strings -Woverloaded-virtual -fno-gnu-keywords -fstrict-aliasing")
  endif()

# - Tell compiler where to find headers
include_directories(cpphw/PP6LIB)

# - Add the pp6lib library
add_subdirectory(cpphw/PP6LIB)

# - Add the pp6calculator program
add_executable(pp6calculator cpphw/cpphw.cpp cpphw/PP6LIB/cppMath.cpp cpphw/PP6LIB/cppMath.hpp cpphw/PP6LIB/cppMenu.cpp cpphw/PP6LIB/cppMenu.hpp cpphw/PP6LIB/cppPhysics.cpp cpphw/PP6LIB/cppPhysics.hpp cpphw/PP6LIB/FileReader.cpp cpphw/PP6LIB/FileReader.hpp cpphw/PP6LIB/FourVector.cpp cpphw/PP6LIB/FourVector.hpp cpphw/PP6LIB/Particle.cpp cpphw/PP6LIB/Particle.hpp cpphw/PP6LIB/ThreeVector.cpp cpphw/PP6LIB/ThreeVector.hpp)

# - Link pp6calculator to the pp6lib library
target_link_libraries(pp6calculator pp6lib)

# - Install pp6calculator to the bin subdirectory of CMAKE_INSTALL_PREFIX
install(TARGETS pp6calculator DESTINATION bin)

# - Package pp6calculator sources and executable
include(CPack)



