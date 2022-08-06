#include <iostream>

#include "inc/stack.h" // 插入头文件

using namespace std; // 规定命名空间
int main()
{
    StackClass *stack = new StackClass(4); // 在堆内存中申请4个长度的栈
    while (true)
    {
        string operate;        // 定义字符串指令
        getline(cin, operate); // 输入指令
        if (cin.fail())
            cin.clear();
        cin.sync(); // 保证指令输入成功

        if (operate == "ps") // 入栈
        {
            float x;
            cin >> x; // 键入入栈数据
            if (cin.fail())
            {
                cin.clear();
                cin.sync();
                continue;
            }               // 保证x获得数据
            stack->push(x); // 数据入栈
        }
        else if (operate == "pp") // 出栈
        {
            float x;
            stack->pop(x);
            cout << x << endl; //后进先出
        }
        else if (operate == "t") // 显示栈顶值
        {
            if (!stack->isEmpty())            // 判断是否为空栈
                cout << stack->top() << endl; // 输出栈顶值
        }
        else if (operate == "s") // 展示栈内元素
            stack->show();
        else if (operate == "q") // 退出
            break;
    }
    return 0;
}