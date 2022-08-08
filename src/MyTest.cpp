#include <opencv2/opencv.hpp>          // 插入opencv头文件
#include <iostream>                    // 插入输入输出流头文件
#include <string>                      // 插入字符串头文件
#include <opencv2/highgui/highgui.hpp> // 插入opencv头文件
using namespace cv;                    // 规定命名空间
using namespace std;                   // 规定命名空间

// 程序入口
int main(int argc, char **argv)
{
    Mat ser = imread("../img/serious.jpg"); // 读入图片储存在矩阵中
    Mat cat = imread("../img/cat.jpg");     // 读入图片储存在矩阵中
    Mat catg;                               // 定义矩阵
    Mat cath;                               // 定义矩阵
    cvtColor(cat, catg, COLOR_RGB2GRAY);    // 将图片灰度化
    cvtColor(cat, cath, COLOR_RGB2HSV);     // 将图片转到hsv域
    while (true)                            // 设置命令循环
    {
        string operate;        // 定义命令变量
        getline(cin, operate); // 获得命令
        if (cin.fail())
            cin.clear();
        cin.sync();          // 确保输入成功
        if (operate == "tf") // 如果命令为“tf”
        {
            imshow("color", cat); // 展示原图
            waitKey(1000);        // 展示时间
            imshow("gray", catg); // 展示灰域图
            waitKey(1000);        // 展示时间
            imshow("hsv", cath);  // 展示hsv图
            waitKey(7000);        // 展示时间
            destroyAllWindows();  // 清除窗口
        }
        else if (operate == "bn") // 如果命令为“bn"
        {
            Mat catb;                                   // 定义黑白矩阵
            threshold(catg, catb, 0, 255, THRESH_OTSU); // 将灰度图转成黑白图
            imshow("catb", catb);                       // 展示黑白图
            waitKey(7000);                              // 展示时间
            destroyAllWindows();                        // 清除所有窗口
        }
        else if (operate == "cut") // 如果命令为”cut“
        {
            cout << "Width:" << ser.size().width << endl;         // 输出图片宽度
            cout << "Height:" << ser.size().height << endl;       // 输出图片长度
            Mat croppedSer = ser(Range(0, 600), Range(100, 813)); // 将图片裁剪
            imshow("serious", ser);                               // 展示原图
            waitKey(1000);                                        // 展示时间
            imshow("input", croppedSer);                          // 展示裁剪后的图片
            waitKey(7000);                                        // 展示时间
            destroyAllWindows();                                  // 清除所有窗口
        }
        else if (operate == "cn") // 如果命令为”cn“
        {
            Mat Windy = imread("../img/Windy.jpg");    // 读入图片储存在矩阵中
            imshow("原始图", Windy);                   // 展示原图
            waitKey(1000);                             // 展示时间
            Mat DstPic, edge, Wingy;                   // 定义所需矩阵
            DstPic.create(Windy.size(), Windy.type()); // 创造同大小类型的矩阵
            cvtColor(Windy, Wingy, COLOR_BGR2GRAY);    // 将原图灰度化
            blur(Wingy, edge, Size(3, 3));             // 使用3×3内核降噪
            Canny(edge, edge, 3, 9, 3);                // 运行canny算子
            imshow("Canny算法轮廓提取结果", edge);     // 展示提取的轮廓
            waitKey(7000);                             // 展示时间
            destroyAllWindows();                       // 清除所有窗口
        }
        else if (operate == "q") // 如果命令为“q"
            break;               // 退出
    }
    return 0; // 程序结束
}