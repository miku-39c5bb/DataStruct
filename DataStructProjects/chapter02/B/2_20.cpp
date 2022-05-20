#include <bits/stdc++.h>
using namespace std;
typedef struct lnode {
    int data;
    struct lnode *pred, *next;
    int freq;
} lnode, *linklist;
void buildlist(linklist& L) {
    L = (linklist)malloc(sizeof(lnode));
    L->next = NULL;
    L->pred = NULL;
    L->freq = 0;
    lnode *s, *r = L;
    int x;
    cin >> x;
    while (x != 999) {
        s = (lnode*)malloc(sizeof(lnode));
        s->data = x;
        s->freq = 0;
        r->next = s;
        s->pred = r;
        r = s;
        cin >> x;
    }
    r->next = NULL;
}
void disp(linklist& L) {
    if (!L || !L->next)
        return;
    lnode* p = L->next;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 我写的---------------------------------------------------------------
// miku
void locate(linklist& L, int x) {
    lnode *p = L, *q, *pre, *u;
    bool flag = false;
    while (p->next != NULL) {
        if (p->next->data == x) {
            flag = true;
            p->next->freq++;

            q = p->next;
            u = q->next;
            pre = L;
            while (pre->next && q->freq < pre->next->freq) {
                pre = pre->next;
            }
            if (q == pre->next) {
                p = p->next;
            } else {
                q->next = pre->next;
                pre->next = q;
                p->next = u;
            }
        } else {
            p = p->next;
        }
    }
    if (!flag) {
        cout << "没有找到x: " << x << endl;
        return;
    }
}
// ---------------------------------------------------------------

// 书上的答案---------------------------------------------------------------
// miku 查找、删除、插入
linklist Locate(linklist& L, int x) {
    lnode *p = L->next, *q;
    while (p && p->data != x)  // ①查找值为x的结点
        p = p->next;
    if (!p)  // 没有值为x的结点
        exit(0);
    else {
        p->freq++;                                    // 值为x的结点freq++
        if (p->pred == L || p->pred->freq > p->freq)  // ②如果该结点为第一个结点，或者++后的freq位序仍然不变
            return p;                                 // 则直接返回指向该节点的指针p
        if (p->next != NULL)                          // ③将结点*p从链表上摘下
            p->next->pred = p->pred;
        p->pred->next = p->next;
        q = p->pred;  // ④用q查找可以插入的位置的前驱
        while (q != L && q->freq <= p->freq)
            q = q->pred;
        p->next = q->next;  // ⑤执行插入操作，将*p结点插在*q的后面
        if (q->next != NULL)
            q->next->pred = p;
        p->pred = q;
        q->next = p;
    }
    return p;  // 返回*p结点
}
// ---------------------------------------------------------------
linklist _Locate(linklist& L, int x) {
    lnode *p = L->next, *q;
    while (p && p->data != x)
        p = p->next;
    if (!p)
        exit(0);
    else {
        p->freq++;
        if (p->pred == L || p->pred->freq > p->freq)
            return p;
        if (p->next != NULL)
            p->next->pred = p->pred;
        p->pred->next = p->next;
        q = p->pred;
        while (q != L && q->freq <= p->freq)
            q = q->pred;
        p->next = q->next;
        if (q->next != NULL)
            q->next->pred = p;
        p->pred = q;
        q->next = p;
    }
    return p;
}

int main() {
    linklist L;
    buildlist(L);
    disp(L);
    int x;
    cin >> x;
    while (x != 999) {
        lnode* p = Locate(L, x);
        cout << "-------" << endl;
        disp(L);
        disp(p);
        cout << "-------" << endl;
        cin >> x;
    }
    return 0;
}