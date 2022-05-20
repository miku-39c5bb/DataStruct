#include <bits/stdc++.h>
#include "./include/queue.h"
#include "./include/stack.h"
using namespace std;

void reverse_queue(LinkQueue& Q) {
    LiStack S;
    InitStack(S);
    int x;
    while (!IsEmpty_1(Q)) {
        DeQueue_1(Q, x);
        Push(S, x);
    }
    while (!StackEmpty(S)) {
        Pop(S, x);
        EnQueue_1(Q, x);
    }
}

void disp_queue(LinkQueue Q) {
    LinkNode* p = Q.front->next;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void test() {
    LinkQueue Q;
    InitQueue_1(Q);
    int x;
    cin >> x;
    while (x != 999) {
        EnQueue_1(Q, x);
        cin >> x;
    }
    disp_queue(Q);
    reverse_queue(Q);
    disp_queue(Q);
}

int main() {
    test();
    return 0;
}