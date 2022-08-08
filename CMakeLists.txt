project(MyTest)

set(CMAKE_CXX_STANDARD 11)
set(OpenCV_DIR opencv)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(MyTest MyTest.cpp)
target_link_libraries(MyTest ${OpenCV_LIBS})