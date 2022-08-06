#ifndef _COORDINATE_H
#define _COORDINATE_H

#include <math.h>                     // 插入数学库头文件
#include "vector.h"                   // 插入向量头文件
struct Coordinate2f : public vectorf2 // 地图类继承自向量类
{
    float angle; // 平面角（rad）
    float mag;   // 欧式距离
    // 获得平面角
    float getAngle() const { return angle; }
    // 获得欧式距离
    float getMag() const { return mag; }
    // 计算欧式距离
    void calMag() { mag = norm(); }
    // 计算欧式角
    void calAngle() { angle = (acos(x / norm())); }
};
#endif