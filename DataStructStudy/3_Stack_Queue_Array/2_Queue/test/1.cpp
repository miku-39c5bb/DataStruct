#include <bits/stdc++.h>
using namespace std;

#define MaxSize 10
typedef struct {
    int data[MaxSize];
    int front, rear;
} Queue;
void Init(Queue& Q) {
    Q.front = Q.rear = 0;
}
bool isEmpty(Queue Q) {
    return Q.front == Q.rear;
}
bool EnQueue(Queue& Q, int x) {
    if ((Q.rear + 1) % MaxSize == Q.front)
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}
bool DeQueue(Queue& Q, int& x) {
    if (Q.rear == Q.front)
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}
bool GetHead(Queue Q, int& x) {
    if (Q.rear == Q.front)
        return false;
    x = Q.data[Q.front];
    return true;
}

int main() {
    Queue q;
    Init(q);
    if (isEmpty(q))
        cout << "Empty queue" << endl;
    int e;
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
    if (isEmpty(q))
        cout << "Empty queue" << endl;
    return 0;
}