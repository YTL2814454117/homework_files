#ifndef _LINKLIST_H
#define _LINKLIST_H
#include <iostream>
struct LinklistNodeStruct //
{
    float data;
    LinklistNodeStruct *next; //
    LinklistNodeStruct *prev; //
    //
    LinklistNodeStruct(float data) : data(data), next(nullptr), prev(nullptr){};
};
class LinklistClass //
{
public:
    //
    LinklistClass() : head(nullptr), dataCounter(0){};
    //
    ~LinklistClass()
    {
        if (head == nullptr)
            return;
        LinklistNodeStruct *currentNode = head->next; // 定义当前结点指针（从头开始释放堆内存）
        head->next = nullptr;
        LinklistNodeStruct *deleteNode; //
        while (currentNode != nullptr)
        {
            deleteNode = currentNode;
            currentNode = currentNode->next;
            delete deleteNode;
        }
    }

private:
    LinklistNodeStruct *head;
    size_t dataCounter;
};
#endif
