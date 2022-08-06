#ifndef _QUEUE_H
#define _QUEUE_H

#include <iostream>
class QueueClass //创建循环队列数据结构
{
public:
    // 构造函数并申请堆内存
    QueueClass(size_t capacity) : capacity(capacity), headIndex(0), tailIndex(0), dataCounter(0) { data = new float[capacity]; }
    // 析构函数释放堆内存
    ~QueueClass() { delete[] data; }
    // 队空
    bool isEmpty() const { return dataCounter <= 0; }
    // 队满
    bool isFull() const { return dataCounter >= capacity; }
    // 获得队首元素
    float getFront() const { return data[headIndex]; }
    /**
     * @brief 入队并记录入队值
     *
     * @param value
     * @return true
     * @return false
     */
    // 入队
    bool enqueue(float value)
    {
        if (isFull())
            return false; // 队满报错
        else
        {
            data[tailIndex] = value;                // 队尾获值
            tailIndex = (tailIndex + 1) % capacity; // 设置循环
            dataCounter++;                          // 计数增加
        }
        return true;
    }
    /**
     * @brief // 出队并记录出队值
     *
     * @param value
     * @return true
     * @return false
     */
    // 出队
    bool dequeue(float &value)
    {
        if (isEmpty())
            return false; // 队空报错
        else
        {
            value = data[headIndex];                // 队首元素出队
            headIndex = (headIndex + 1) % capacity; // 设置循环
            dataCounter--;                          // 计数减少
        }
    }
    // 展示队列元素
    void show()
    {
        for (size_t i = 0; i < dataCounter; i++)
            std::cout << data[(headIndex + i) % capacity] << " "; // 从队首到队尾展示元素
        std::cout << std::endl;
    }

private:
    size_t capacity;    // 数据容量
    size_t headIndex;   // 队首索引
    size_t tailIndex;   // 队尾索引
    size_t dataCounter; // 数据计数器
    float *data;        // 动态申请数据
};
#endif