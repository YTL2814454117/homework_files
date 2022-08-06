#include <iostream>     // 插入输入输出流头文件
#include "inc/MyMath.h" // 插入数学头文件
#include "inc/vector.h" // 插入向量头文件

using namespace std; // 规定命名空间

//函数入口
int main()
{
    vectorf2 x(1), y(2);                   // 变量初始化
    Swap(x, y);                            // 交换
    vectorf2 ans = x.operator+(y);         // 调用重构函数
    cout << x.x << " " << y.x << endl;     // 输出结果
    cout << ans.x << " " << ans.y << endl; // 输出结果
    ans += y;                              // 调用重构函数
    cout << ans.x << " " << ans.y << endl; // 输出结果
    return 0;                              // 程序结束
}