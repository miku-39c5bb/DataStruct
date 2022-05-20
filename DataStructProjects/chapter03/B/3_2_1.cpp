#include <bits/stdc++.h>
using namespace std;

#define MaxSize 5
typedef int ElementType;
typedef struct {
    ElementType data[MaxSize];
    int front, rear;
    int tag;
} Queue;
void InitQueue(Queue& Q) {
    Q.front = Q.rear = 0;
    Q.tag = 0;
}
bool IsEmpty(Queue Q) {
    if (Q.front == Q.rear && Q.tag == 0)
        return true;
    return false;
}
bool IsFull(Queue Q) {
    if (Q.front == Q.rear && Q.tag == 1)
        return true;
    return false;
}
bool EnQueue(Queue& Q, ElementType e) {
    if (Q.front == Q.rear && Q.tag == 1)
        return false;
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MaxSize;
    Q.tag = 1;
    return true;
}
bool DeQueue(Queue& Q, ElementType& e) {
    if (Q.front == Q.rear && Q.tag == 0)
        return false;
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    Q.tag = 0;
    return true;
}

void test() {
    Queue Q;
    InitQueue(Q);
    if (IsEmpty(Q))
        cout << "队空" << endl;
    ElementType x;
    cin >> x;
    while (x != 999) {
        if (!EnQueue(Q, x)) {
            cout << "EnQueue false" << endl;
            if (IsFull(Q))
                cout << "队满" << endl;
            break;
        }
        cin >> x;
    }
    if (IsEmpty(Q))
        cout << "队空" << endl;
    while (DeQueue(Q, x))
        cout << x << " ";
    cout << endl;
    if (IsEmpty(Q))
        cout << "队空" << endl;
}
int main() {
    test();
    return 0;
}