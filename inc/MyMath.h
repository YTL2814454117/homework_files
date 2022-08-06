#ifndef _MYMATH_H
#define _MYMATH_H
#define PI 3.1415926535f // 创建宏
template <class T>       // 创建函数模板
//创建交换函数主体
void Swap(T &x, T &y)
{
    T temp = x; // 把x的值传给temp
    x = y;      // 把y的值传给x
    y = temp;   // 实现元素交换
}
#endif