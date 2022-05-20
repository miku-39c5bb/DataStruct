// 队列 ——  一端插入（rear），一端删除（front）
// 先进先出（FIFO）
#include <bits/stdc++.h>
using namespace std;

#define MaxSize 50     // 这是一个循环队列，普通的顺序队列可能出现“假溢出”的情况
typedef int ElemType;  // 牺牲一个存储单元，用以区分队满或队空
typedef struct {       // 队列元素个数：(rear + MaxSize - front) % MaxSize
    ElemType data[MaxSize];
    int front, rear;  // front指向第一个元素的位置，rear指向最后一个元素的下一个位置
} SqQueue;
void InitQueue(SqQueue& Q) {
    Q.front = Q.rear = 0;  // front和rear都初始化为0
}
bool QueueEmpty(SqQueue Q) {
    return Q.front == Q.rear;
}
bool isFull(SqQueue Q) {
    return (Q.rear + 1) % MaxSize == Q.front;
}
bool EnQueue(SqQueue& Q, ElemType e) {
    if ((Q.rear + 1) % MaxSize == Q.front)
        return false;
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}
bool DeQueue(SqQueue& Q, ElemType& e) {
    if (Q.front == Q.rear)
        return false;
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}
bool GetHead(SqQueue Q, ElemType& e) {
    if (Q.front == Q.rear)
        return false;
    e = Q.data[Q.front];
    return true;
}

int main() {
    SqQueue q;
    InitQueue(q);
    if (QueueEmpty(q))
        cout << "Empty queue" << endl;
    ElemType e;
    cin >> e;
    while (e != 999) {
        EnQueue(q, e);
        cin >> e;
    }
    GetHead(q, e);
    cout << e << endl;
    while (DeQueue(q, e))
        cout << e << " ";
    cout << endl;
    if (QueueEmpty(q))
        cout << "Empty queue" << endl;
    return 0;
}