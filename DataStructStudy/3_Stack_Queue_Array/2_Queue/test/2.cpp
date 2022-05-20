#include <bits/stdc++.h>
using namespace std;

typedef int ElemType;
typedef struct linknode {
    ElemType data;
    struct linknode* next;
} linknode;
typedef struct {
    linknode *front, *rear;
} Queue;

void Init_1(Queue& Q) {
    Q.front = Q.rear = new linknode;
    Q.front->next = NULL;
}
bool isEmpty_1(Queue Q) {
    return Q.front == Q.rear;
}
void EnQueue_1(Queue& Q, ElemType e) {
    linknode* s = new linknode;
    s->data = e;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
}
bool DeQueue_1(Queue& Q, ElemType& e) {
    if (Q.front == Q.rear)
        return false;
    linknode* p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)
        Q.rear = Q.front;
    delete p;
    return true;
}

void Init_2(Queue& Q) {
    Q.front = Q.rear = NULL;
}
bool isEmpty_2(Queue Q) {
    return Q.front == NULL;
}
void EnQueue_2(Queue& Q, ElemType e) {
    linknode* s = new linknode;
    s->data = e;
    s->next = NULL;
    if (Q.front == NULL)
        Q.front = Q.rear = s;
    else {
        Q.rear->next = s;
        Q.rear = s;
    }
}
bool DeQueue_2(Queue& Q, ElemType& e) {
    if (Q.front == NULL)
        return false;
    linknode* p = Q.front;
    e = p->data;
    Q.front = p->next;
    if (Q.rear == p)
        Q.rear = Q.front = NULL;
    delete p;
    return true;
}

void test_1() {
    Queue Q;
    Init_1(Q);

    if (isEmpty_1(Q))
        cout << "Empty queue" << endl;
    else
        cout << "Not empty" << endl;

    cout << "-----------EnQueue-----------" << endl;
    ElemType e;
    cin >> e;
    while (e != 999) {
        EnQueue_1(Q, e);
        cin >> e;
    }

    if (isEmpty_1(Q))
        cout << "Empty queue" << endl;
    else
        cout << "Not empty" << endl;

    cout << "-----------DnQueue-----------" << endl;
    while (DeQueue_1(Q, e))
        cout << e << " ";
    cout << endl;

    if (isEmpty_1(Q))
        cout << "Empty queue" << endl;
    else
        cout << "Not empty" << endl;
}

void test_2() {
    Queue Q;
    Init_2(Q);

    if (isEmpty_2(Q))
        cout << "Empty queue" << endl;
    else
        cout << "Not empty" << endl;

    cout << "-----------EnQueue-----------" << endl;
    ElemType e;
    cin >> e;
    while (e != 999) {
        EnQueue_2(Q, e);
        cin >> e;
    }

    if (isEmpty_2(Q))
        cout << "Empty queue" << endl;
    else
        cout << "Not empty" << endl;

    cout << "-----------DnQueue-----------" << endl;
    while (DeQueue_2(Q, e))
        cout << e << " ";
    cout << endl;

    if (isEmpty_2(Q))
        cout << "Empty queue" << endl;
    else
        cout << "Not empty" << endl;
}

int main() {
    cout << "-----------test_1-----------" << endl;
    test_1();
    cout << "-----------test_2-----------" << endl;
    test_2();
    return 0;
}