#ifndef _VECTOR_
#define _VECTOR_
#include <math.h> // 插入头文件

struct vectorf2 // 创建二维向量
{
    float x, y, t;                                                               // 定义变量
    vectorf2() : x(0), y(0) {}                                                   // 初始化
    vectorf2(float x) : x(x), y(x) {}                                            // 函数重载
    vectorf2(float x, float y) : x(x), y(y) {}                                   // 函数重载
    vectorf2 operator+(vectorf2 &v) const { return vectorf2(x + v.x, y + v.y); } // 重构“+”
    // 自增
    void operator+=(const vectorf2 &v) { x += v.x, y += v.y; }
    // 自减
    void operator-=(const vectorf2 &v) { x -= v.x, y -= v.y; }
    // 自乘
    void operator*=(const vectorf2 &v) { x *= v.x, y *= v.y; }
    // 二范数
    float norm() const { return sqrt(x * x + y * y); }
    // 点积
    float dot(const vectorf2 &v) const { return x * v.x + y * v.y; }
    // 投影
    float projection(const vectorf2 &v) const { return this->dot(v) / v.norm(); }
    // 返回自身的标准化值
    vectorf2 normalize() const { return vectorf2(x / norm(), y / norm()); }
    // 将自身标准化
    void normalized() { t = norm(), x = x / t, y = y / t; }
};

#endif