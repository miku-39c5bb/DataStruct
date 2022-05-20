#include <bits/stdc++.h>
using namespace std;
typedef struct lnode {
    int data;
    struct lnode* next;
} lnode, *linklist;
void buildlsit(linklist& L) {
    L = new lnode;
    L->next = nullptr;
    lnode *s, *r = L;
    int x;
    cin >> x;
    while (x != 999) {
        s = new lnode;
        s->data = x;
        r->next = s;
        r = s;
        cin >> x;
    }
    r->next = L;
}
void disp(linklist L) {
    if (L == nullptr || L->next == L)
        return;
    lnode* p = L->next;
    while (p != L) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 我写的---------------------------------------------------------------
void combine(linklist& h1, linklist& h2) {
    lnode* r = h1->next;
    while (r->next != h1) {
        r = r->next;
    }
    r->next = h2->next;
    while (r->next != h2) {  // miku 思考一下，若h2只有表头，会是什么情况
        r = r->next;
    }
    r->next = h1;
    delete h2;
    h2 = nullptr;
}
// ---------------------------------------------------------------

// 书上的答案---------------------------------------------------------------
linklist Link(linklist& h1, linklist& h2) {
    lnode *p, *q;
    p = h1->next;
    while (p->next != h1)
        p = p->next;
    q = h2->next;
    while (q->next != h2)  // 思考一下，若h2只有表头，会是什么情况
        q = q->next;
    p->next = h2->next;
    q->next = h1;  // 联系这里思考（我自认为我自己写的combine函数要优于Link函数）
    delete h2;
    h2 = nullptr;
    return h1;
}
// ---------------------------------------------------------------

int main(int argc, char** argv) {
    linklist L1;
    buildlsit(L1);
    disp(L1);
    linklist L2;
    buildlsit(L2);
    disp(L2);
    cout << "-------" << endl;
    combine(L1, L2);
    // Link(L1, L2);
    disp(L1);
    disp(L2);
    return 0;
}