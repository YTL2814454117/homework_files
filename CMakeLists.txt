
project(MyTest) # 项目名称
set(CMAKE_CXX_STANDARD 11) # 设置c++编译标准
set(OpenCV_DIR opencv) # 配置opencv库
find_package(OpenCV REQUIRED) # 寻找指定的opencv库
include_directories(${OpenCV_INCLUDE_DIRS}) # 添加opencv头文件
add_executable(MyTest src/MyTest.cpp) # 添加源文件到项目中
target_link_libraries(MyTest ${OpenCV_LIBS}) # 链接opencv库