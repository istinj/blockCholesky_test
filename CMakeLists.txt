project(blockChol)
cmake_minimum_required( VERSION 2.8 )
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} --std=gnu++11)
set(CMAKE_MODULE_PATH ~/Documenti/4_TESI/blockChol/cmake_modules)

#find macros and libraries
find_package(Eigen3 REQUIRED
	Boost 1.54.0.1 REQUIRED)

#include directories
include_directories(include
	${EIGEN3_INCLUDE_DIR}
	${Boost_INCLUDE_DIR})

#c++ executable
set(SRCS 
	src/test_blockChol.cpp src/SparseMatrix.cpp)
add_executable(blockChol_main_app ${SRCS})

# Specify libraries to link a library or executable target against
target_link_libraries(blockChol_main_app ${Boost_LIBRARIES})

set_target_properties(blockChol_main_app PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)