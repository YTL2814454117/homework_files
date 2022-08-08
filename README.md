#对计算机视觉的理解
计算机视觉是让机器能够拥有像生物一样看东西的能力，并对看到的图像进行识别与处理。
计算机视觉本质上是对大量数据的快速处理，因为计算机是以像素为单位储存图片信息的，一个
像素占有一定大小的字节，对图片进行各种操作实际上是对每个像素的数据进行操作。
图像分类：color（RGB三个矩阵） gray scale(字节矩阵数字大小表示明暗) binary(0 1)  hsv ......
对于图像的处理有很多方向，如改变色域、目标检测、图像描述、形态学操作......
处理图像数据也有很多方法，如卷积神经算法、高斯算子、canny算子......
计算机视觉的应用前景也很广，医学诊断 自动驾驶 机器人等等
计算机视觉的发展需要硬件和软件的支持，如传感器、驱动器、芯片、算法等


##学习历程
今天上午在ubuntu环境下配置了opencv，遇到了很多困难，首先是安装过程中一直
出现找不到opencv.pc的问题，花了好久才知道要自己创建一个文件夹然后进行配置，
然后在进行测试的时候，头文件一直找不到，路径修改了几次才才能找到头文件，opencv
的版本兼容问题也导致一些函数使用使用困难，换了一个简单的测试，由于不了解cmakelists
中对于opencv库的链接，导致一直不能运行，在学长指点后寻找到了解决问题的方法，最后
成功实现读入图片和输出图片。上午只是实现了简单的图片输入与输出，下午才开始图像处理的主线
任务，下午和晚上的学习过程还算顺利。


###工程细节与学习积累

cmakelists中对于opencv的环境配置
```cmake
project(MyTest) # 项目名称
set(CMAKE_CXX_STANDARD 11) # 设置c++编译标准
set(OpenCV_DIR opencv) # 配置opencv库
find_package(OpenCV REQUIRED) # 寻找指定的opencv库
include_directories(${OpenCV_INCLUDE_DIRS}) # 添加opencv头文件
add_executable(MyTest src/MyTest.cpp) # 添加源文件到项目中
target_link_libraries(MyTest ${OpenCV_LIBS}) # 链接opencv库
```


利用opencv库中的函数进行图片的输入输出与改变颜色
```c++
Mat cat = imread("../img/cat.jpg");     // 读入图片储存在矩阵中
    Mat catg;                               // 定义矩阵
    Mat cath;                               // 定义矩阵
    cvtColor(cat, catg, COLOR_RGB2GRAY);    // 将图片灰度化
    cvtColor(cat, cath, COLOR_RGB2HSV);     // 将图片转到hsv域
    imshow("color", cat); // 展示原图
    waitKey(1000);        // 展示时间
    imshow("gray", catg); // 展示灰域图
    waitKey(1000);        // 展示时间
    imshow("hsv", cath);  // 展示hsv图
    waitKey(7000);        // 展示时间
    destroyAllWindows();  // 清除窗口
```


利用Range类进行图片裁剪并输出结果
```c++
Mat croppedSer = ser(Range(0, 600), Range(100, 813)); // 将图片裁剪
imshow("serious", ser);                               // 展示原图
waitKey(1000);                                        // 展示时间
imshow("input", croppedSer);                          // 展示裁剪后的图片
waitKey(7000);                                        // 展示时间
```


canny轮廓算法的实现
```c++
Mat DstPic, edge, Wingy;                   // 定义所需矩阵
DstPic.create(Windy.size(), Windy.type()); // 创造同大小类型的矩阵
Canny(edge, edge, 3, 9, 3);                // 运行canny算子
imshow("Canny算法轮廓提取结果", edge);     // 展示提取的轮廓
```