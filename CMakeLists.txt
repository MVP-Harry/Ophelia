cmake_minimum_required(VERSION 3.10)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(Ophelia VERSION 1.0)

set(SOURCE_FILES src/board.cpp src/move.cpp src/data.cpp src/generator.cpp src/global.cpp)
add_executable(test ${SOURCE_FILES})
target_include_directories(test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# add_executable(move src/move.cpp)
# target_include_directories(move PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
#
# add_executable(data src/data.cpp)
# target_include_directories(data PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
#
# add_executable(generator src/generator.cpp)
# target_include_directories(generator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# file(GLOB APP_SOURCES src/*.cpp)
# foreach(testsourcefile ${APP_SOURCES})
#     string( REPLACE ".cpp" "" testname ${testsourcefile} )
#     add_executable(${testname} ${testsourcefile})
# 	target_include_directories(${testname} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
# endforeach( testsourcefile ${APP_SOURCES} )
