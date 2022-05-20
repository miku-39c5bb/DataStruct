// 链式存储的队列
#include <bits/stdc++.h>
using namespace std;
typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode* next;
} LinkNode;
typedef struct {
    LinkNode *front, *rear;  // 队列的队头指针和队尾指针
} LinkQueue;

// --------------------------------------------
// miku 带头结点
void InitQueue_1(LinkQueue& Q) {
    // 初始化时，front和rear都指向头结点
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}
bool IsEmpty_1(LinkQueue Q) {
    if (Q.front == Q.rear)
        return true;
    else
        return false;
    // return Q.front->next == NULL;
}
void EnQueue_1(LinkQueue& Q, ElemType e) {
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = e;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
}
bool DeQueue_1(LinkQueue& Q, ElemType& e) {
    // if (Q.front->next == NULL)
    if (Q.front == Q.rear)
        return false;
    LinkNode* p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)       // highlight 此次是最后一个结点出队
        Q.rear = Q.front;  // front=rear; 再次变为空队列
    free(p);
    return true;
}
// --------------------------------------------

// --------------------------------------------
// miku 不带头结点
void InitQueue_2(LinkQueue& Q) {
    Q.front = Q.rear = NULL;
}
bool IsEmpty_2(LinkQueue Q) {
    if (Q.front == NULL)
        return true;
    else
        return false;
}
void EnQueue_2(LinkQueue& Q, ElemType e) {
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = e;
    s->next = NULL;
    if (Q.front == NULL) {  // 不带头结点
        Q.front = s;        // highlight 若原队列为空，则front和rear都指向s
        Q.rear = s;
    } else {
        Q.rear->next = s;
        Q.rear = s;
    }
}
bool DeQueue_2(LinkQueue& Q, ElemType& e) {
    if (Q.front == NULL)
        return false;
    LinkNode* p = Q.front;
    e = p->data;
    Q.front = p->next;
    if (Q.rear == p) {   // highlight 此次是最后一个结点出队
        Q.front = NULL;  // front=rear=NULL;
        Q.rear = NULL;
    }
    free(p);
    return true;
}
// --------------------------------------------

void test_1() {
    LinkQueue Q;
    InitQueue_1(Q);

    if (IsEmpty_1(Q))
        cout << "Empty queue" << endl;
    else
        cout << "Not empty" << endl;

    cout<<"-----------EnQueue-----------"<<endl;
    ElemType e;
    cin >> e;
    while (e != 999) {
        EnQueue_1(Q, e);
        cin >> e;
    }

    if (IsEmpty_1(Q))
        cout << "Empty queue" << endl;
    else
        cout << "Not empty" << endl;

    cout<<"-----------DnQueue-----------"<<endl;
    while (DeQueue_1(Q, e))
        cout << e << " ";
    cout << endl;

    if (IsEmpty_1(Q))
        cout << "Empty queue" << endl;
    else
        cout << "Not empty" << endl;
}

void test_2() {
    LinkQueue Q;
    InitQueue_2(Q);

    if (IsEmpty_2(Q))
        cout << "Empty queue" << endl;
    else
        cout << "Not empty" << endl;

    cout<<"-----------EnQueue-----------"<<endl;
    ElemType e;
    cin >> e;
    while (e != 999) {
        EnQueue_2(Q, e);
        cin >> e;
    }

    if (IsEmpty_2(Q))
        cout << "Empty queue" << endl;
    else
        cout << "Not empty" << endl;

    cout<<"-----------DnQueue-----------"<<endl;
    while (DeQueue_2(Q, e))
        cout << e << " ";
    cout << endl;

    if (IsEmpty_2(Q))
        cout << "Empty queue" << endl;
    else
        cout << "Not empty" << endl;
}

int main() {
    cout<<"-----------test_1-----------"<<endl;
    test_1();
    cout<<"-----------test_2-----------"<<endl;
    test_2();
    return 0;
}