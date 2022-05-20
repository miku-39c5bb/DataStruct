#include <bits/stdc++.h>
using namespace std;
typedef struct lnode {
    int data;
    struct lnode* next;
} lnode, *linklist;
void buildlist(linklist& L) {
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
    r->next = nullptr;
}
void disp(linklist L) {
    if (L == nullptr)
        return;
    lnode* p = L->next;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 我写的---------------------------------------------------------------
bool isSubsequent(linklist& la, linklist& lb) {
    lnode *pa = la->next, *pb = lb->next;
    while (pa) {
        while (pa->data == pb->data) {
            pa = pa->next;
            pb = pb->next;
            if (pb == nullptr) {
                return true;
            }
        }
        pb = lb->next;
        pa = pa->next;
    }
    return false;
}
// ---------------------------------------------------------------

// 书上的答案---------------------------------------------------------------
int Pattern(linklist A, linklist B) {
    lnode* p = A->next;
    lnode* pre = p;
    lnode* q = B->next;
    while (p && q) {
        if (p->data == q->data) {
            p = p->next;
            q = q->next;
        } else {
            pre = pre->next;
            p = pre;
            q = B->next;
        }
    }
    if (q == nullptr) {
        return 1;
    } else {
        return 0;
    }
}
// ---------------------------------------------------------------

int main() {
    linklist L1;
    buildlist(L1);
    disp(L1);
    linklist L2;
    buildlist(L2);
    disp(L2);
    // cout << isSubsequent(L1, L2) << endl;
    cout << Pattern(L1, L2) << endl;
    return 0;
}