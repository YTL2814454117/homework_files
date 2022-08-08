#include <opencv2/opencv.hpp> // 插入opencv头文件
#include <iostream>           // 插入输入输出流头文件

using namespace cv;  // 规定命名空间
using namespace std; // 规定命名空间

// 程序入口
int main(int argc, char **argv)
{
    Mat src = imread("/home/ytl/opencv-4.6.0/1.jpg"); // 读入图片信息并保存在矩阵中
    imshow("input", src);                             // 在input窗口显示图片
    waitKey(0);                                       // 等待图片展示
    destroyAllWindows;                                // 清空所有窗口
    return 0;                                         // 程序结束
}