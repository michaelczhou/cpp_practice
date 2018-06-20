cmake_minimum_required(VERSION 2.8)		
project(basic)

IF(NOT CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE Release)
ENDIF()

MESSAGE("Build type: "${CMAKE_BUILD_TYPE})

# Check C++11 or C++0x support,并增加了多线程.
add_definitions(-DCOMPILEDWITHC11)
if( CMAKE_BUILD_TYPE MATCHES "Debug" )
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -Wall -msse3 -std=c++11 -pthread -g -march=native")
else( CMAKE_BUILD_TYPE MATCHES "Release" )
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -Wall -msse3 -std=c++11 -pthread -O3 -march=native")
endif( CMAKE_BUILD_TYPE MATCHES "Debug" )

include_directories(
${PROJECT_SOURCE_DIR}
${PROJECT_SOURCE_DIR}/include
)

add_library(${PROJECT_NAME} SHARED
src/hello.cpp
)
target_link_libraries(${PROJECT_NAME}

)

add_executable(hello src/hello.cpp)
target_link_libraries(hello ${PROJECT_NAME})

add_executable(add_item src/add_item.cpp)
#add_executable(mutex src/mutex.cpp)
#target_link_libraries(mutex ${PROJECT_NAME})


