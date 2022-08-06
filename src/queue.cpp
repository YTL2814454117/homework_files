#include <iostream>
#include <string>
#include "inc/queue.h" // 插入头文件
using namespace std;   // 规定命名空间
int main()
{
    QueueClass *queue = new QueueClass(4); // 创建4个长度的循环队列
    while (true)
    {
        string operate;
        getline(cin, operate); // 获得指令
        if (cin.fail())
            cin.clear();
        cin.sync(); // 确保输入正确

        if (operate == "e") // 实现入队
        {
            float x;
            cin >> x; // 输入元素
            if (cin.fail())
            {
                cin.clear();
                cin.sync();
                continue; // 确保输入正确
            }
            queue->enqueue(x); // 实现入队
        }
        else if (operate == "d") // 实现出队
        {
            float x;
            queue->dequeue(x);       // 实现出队
            cout << x << "" << endl; // 展示出队元素
        }
        else if (operate == "f") // 展示队首元素
        {
            if (!queue->isEmpty())
                cout << queue->getFront() << endl; // 展示队首元素
        }
        else if (operate == "s")
            queue->show(); // 展示所有元素
        else if (operate == "q")
            break; // 退出
    }
    return 0;
}