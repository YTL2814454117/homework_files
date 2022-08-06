#ifndef _STACK_H
#define _STACK_H // 定义

#include <iostream> // 插入头文件
class StackClass    // 创建栈类型数据结构
{
public:
    // 构造函数确定栈的容量
    StackClass(size_t capacity) : capacity(capacity), topPointer(0) { data = new float(capacity); }
    // 析构函数释放内存
    ~StackClass() { delete[] data; }
    // 栈空
    bool isEmpty() const { return capacity <= 0; }
    // 栈满
    bool isFull() const { return capacity <= topPointer; }
    // 获得栈顶值
    float top() { return data[topPointer - 1]; }
    // 入栈
    bool push(float value)
    {
        if (isFull())
            return false; // 栈满报错
        else
            data[topPointer++] = value; // 数据入栈
        return true;
    }
    // 出栈
    bool pop(float &value)
    {
        if (isEmpty())
            return false; // 栈空报错
        else
            value = data[--topPointer]; // 数据出栈
        return true;
    }
    //展示栈内元素
    void show()
    {
        for (int i = topPointer - 1; i >= 0; i--) //从栈顶向栈底展示
            std::cout << data[i] << " ";
        std ::cout << std::endl;
    }

private:
    size_t capacity;   // 数据容量
    size_t topPointer; // 栈顶计数器
    float *data;       // 动态申请数据
};
#endif