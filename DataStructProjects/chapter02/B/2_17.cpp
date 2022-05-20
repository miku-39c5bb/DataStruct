#include <bits/stdc++.h>
using namespace std;
typedef struct lnode {
    int data;
    struct lnode *prior, *next;
} lnode, *linklist;
void buildlist(linklist& L) {
    L = (linklist)malloc(sizeof(lnode));
    L->next = L;
    L->prior = L;
    lnode *s, *r = L;
    int x;
    cin >> x;
    while (x != 999) {
        s = (lnode*)malloc(sizeof(lnode));
        s->data = x;
        r->next = s;
        s->prior = r;
        r = s;
        cin >> x;
    }
    r->next = L;
    L->prior = r;
}
void disp(linklist L) {
    if (!L)
        return;
    lnode* p = L->next;
    while (p != L) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 我写的---------------------------------------------------------------
bool isSymmetry(linklist L) {
    lnode *p = L->next, *q = L->prior;
    while (p != q && p->next != q) {
        if (p->data != q->data) {
            return false;
        }
        p = p->next;
        q = q->prior;
    }
    return true;
}
// ---------------------------------------------------------------

// 书上的答案---------------------------------------------------------------
int Symmetry(linklist L) {
    lnode *p = L->next, *q = L->prior;
    // miku 注意循环的终止条件
    // p和q不指向同一结点，且p不是q的下一个结点（q->next != p）
    // 若是写成p->next != q，则最中间那个两个结点没有对比
    // 应该是(p != q && q->next != p)，而非(p != q && p->next != q)
    while (p != q && q->next != p) {
        if (p->data == q->data) {
            p = p->next;
            q = q->prior;
        } else {
            return 0;
        }
    }
    return 1;
}
// ---------------------------------------------------------------

int main() {
    linklist L;
    buildlist(L);
    disp(L);
    // cout << isSymmetry(L) << endl;
    cout << Symmetry(L) << endl;
    return 0;
}