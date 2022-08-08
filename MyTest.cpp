#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
    Mat src = imread("/home/ytl/opencv-4.6.0/1.jpg");
    imshow("input", src);
    waitKey(0);
    destroyAllWindows;
    return 0;
}