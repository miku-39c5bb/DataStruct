#include <bits/stdc++.h>
#include "./include/1_ShunXunZhan.h"
using namespace std;

class Queue {
public:
    Queue() {
        InitStack(S1);
        InitStack(S2);
    }
    bool QueueEmpty() {
        if (StackEmpty(S1) && StackEmpty(S2))
            return true;
        return false;
    }
    bool EnQueue(ElemType e) {
        if (!StackOverflow(S1)) {
            Push(S1, e);
            return true;
        }
        if (StackOverflow(S1) && !StackEmpty(S2)) {
            cout << "队列满" << endl;
            return false;
        }
        if (StackOverflow(S1) && StackEmpty(S2)) {
            while (!StackEmpty(S1)) {
                ElemType x;
                Pop(S1, x);
                Push(S2, x);
            }
        }
        Push(S1, e);
        return true;
    }
    bool DeQueue(ElemType& e) {
        if (!StackEmpty(S2)) {
            Pop(S2, e);
        } else if (StackEmpty(S1)) {
            cout << "队列空" << endl;
            return false;
        } else {
            while (!StackEmpty(S1)) {
                Pop(S1, e);
                Push(S2, e);
            }
            Pop(S2, e);
        }
        return true;
    }

private:
    SqStack S1, S2;
};

void test() {
    Queue Q;
    if (Q.QueueEmpty()) {
        cout << "队空" << endl;
    }
    int x;
    cin >> x;
    while (Q.EnQueue(x)) {
        cin >> x;
        if (x == 999)
            break;
    }
    if (Q.QueueEmpty()) {
        cout << "队空" << endl;
    }
    while (Q.DeQueue(x)) {
        cout << x << " ";
    }
    if (Q.QueueEmpty()) {
        cout << "队空" << endl;
    }
}

// 书上的答案---------------------------------
typedef SqStack Stack;
bool EnQueue(Stack& S1, Stack& S2, ElemType e) {
    if (!StackOverflow(S1)) {
        Push(S1, e);
        return true;
    }
    if (StackOverflow(S1) && !StackEmpty(S2)) {
        cout << "队列满" << endl;
        return false;
    }
    if (StackOverflow(S1) && StackEmpty(S2)) {
        while (!StackEmpty(S1)) {  // 将S1中的元素转到S2
            ElemType x;            // 要单独设置一个变量x，以防污染原本的变量e
            Pop(S1, x);
            Push(S2, x);
        }
    }
    Push(S1, e);
    return true;
}
bool DeQueue(Stack& S1, Stack& S2, ElemType& x) {
    if (!StackEmpty(S2)) {
        Pop(S2, x);
        return true;
    } else if (StackEmpty(S1)) {
        cout << "队列空" << endl;
        return false;
    } else {
        while (!StackEmpty(S1)) {
            Pop(S1, x);
            Push(S2, x);
        }
        Pop(S2, x);
    }
    return true;
}
bool QueueEmpty(Stack& S1, Stack& S2) {
    return StackEmpty(S1) && StackEmpty(S2);
}
void test_2() {
    SqStack S1, S2;
    InitStack(S1);
    InitStack(S2);
    if (QueueEmpty(S1, S2)) {
        cout << "队空" << endl;
    }
    int x;
    cin >> x;
    while (EnQueue(S1, S2, x)) {
        cin >> x;
        if (x == 999)
            break;
    }
    if (QueueEmpty(S1, S2)) {
        cout << "队空" << endl;
    }
    while (DeQueue(S1, S2, x)) {
        cout << x << " ";
    }
    if (QueueEmpty(S1, S2)) {
        cout << "队空" << endl;
    }
}
// ---------------------------------

int main() {
    // test();
    test_2();
    return 0;
}