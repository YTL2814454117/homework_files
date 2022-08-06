#include <iostream>         // 插入输入输出流头文件
#include "inc/MyMath.h"     // 插入数学头文件
#include "inc/vector.h"     // 插入向量头文件
#include "inc/coordinate.h" // 插入地图头文件

using namespace std; // 规定命名空间

//函数入口
int main()
{
    // vectorf2 x(1), y(2);                   // 变量初始化
    // Swap(x, y);                            // 交换
    // vectorf2 ans = x.operator+(y);         // 调用重构函数
    // cout << x.x << " " << y.x << endl;     // 输出结果
    // cout << ans.x << " " << ans.y << endl; // 输出结果
    // ans += y;                              // 调用重构函数
    // cout << ans.x << " " << ans.y << endl; // 输出结果

    float x = 0, y = 0, m = 0, n = 0; // 设置变量
    Coordinate2f mainly;              // 给主向量赋值
    cin >> x >> y;                    // 输入x
    mainly.x = x;                     // 给主变量赋值
    mainly.y = y;                     // 给主变量赋值
    Coordinate2f obj;                 // 给客变量赋值

    while (true)
    {
        string operate;        // 定义指令变量
        getline(cin, operate); // 获得指令
        if (cin.fail())
            cin.clear();
        cin.sync();          // 确保输入正确
        if (operate == "+0") // 如果命令是“+0”
        {
            mainly.operator+=(vectorf2());               // 执行命令
            cout << mainly.x << " " << mainly.y << endl; // 输出结果
        }
        else if (operate == "+") // 如果命令为“+”
        {
            cin >> m >> n;                               // 给客向量赋值
            obj.x = m;                                   // 给客向量赋值
            obj.y = n;                                   // 给客向量赋值
            mainly.operator+=(obj);                      // 实现自加
            cout << mainly.x << " " << mainly.y << endl; // 输出结果
        }

        else if (operate == "-") // 如果命令为“-”
        {
            cin >> m >> n;                               // 给客向量赋值
            obj.x = m;                                   // 给客向量赋值
            obj.y = n;                                   // 给客向量赋值
            mainly.operator-=(obj);                      // 实现自减
            cout << mainly.x << " " << mainly.y << endl; // 输出结果
        }
        else if (operate == "*") // 如果命令为“*”
        {
            cin >> m >> n;                               // 给客向量赋值
            obj.x = m;                                   // 给客向量赋值
            obj.y = n;                                   // 给客向量赋值
            mainly *= (obj);                             // 实现自乘
            cout << mainly.x << " " << mainly.y << endl; // 输出结果
        }
        else if (operate == "sq") // 如果命令为“sq”
        {
            cout << mainly.norm() << endl; // 实现二范数的计算
        }
        else if (operate == ".") // 如果命令为“.”
        {
            cin >> m >> n;                               // 给客向量赋值
            obj.x = m;                                   // 给客向量赋值
            obj.y = n;                                   // 给客向量赋值
            mainly.dot(obj);                             // 实现点乘
            cout << mainly.x << " " << mainly.y << endl; // 输出结果
        }
        else if (operate == "pj") // 如果命令为“pj”
        {
            cin >> m >> n;                          // 给客向量赋值
            obj.x = m;                              // 给客向量赋值
            obj.y = n;                              // 给客向量赋值
            cout << mainly.projection(obj) << endl; // 输出结果
        }
        else if (operate == "nl") // 如果命令为“nl”
        {
            mainly.normalized();                         // 实现标准化
            cout << mainly.x << " " << mainly.y << endl; // 输出结果
        }
        else if (operate == "cm") // 如果命令为“cm”
        {
            mainly.calMag();            // 实现欧氏距离计算
            cout << mainly.mag << endl; // 输出结果
        }
        else if (operate == "ca") // 如果命令为“ca”
        {
            mainly.calAngle();                       // 实现欧式角的计算
            cout << mainly.angle / PI * 180 << endl; // 输出结果
        }
        else if (operate == "q") // 如果命令为“q”
            break;               // 退出
    }
    return 0; // 程序结束
}