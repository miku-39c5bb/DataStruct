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
void del_all_min(linklist& L) {
    lnode *p, *pre, *minp, *minpre;
    while (L->next != L) {
        p = L->next;
        pre = L;
        minp = p;
        minpre = pre;
        while (p != L) {
            if (p->data < minp->data) {
                minp = p;
                minpre = pre;
            }
            pre = p;
            p = p->next;
        }
        cout << minp->data << " ";
        minpre->next = minp->next;
        delete minp;
    }
    delete L;
    L = nullptr;
}
// ---------------------------------------------------------------

// 书上的答案---------------------------------------------------------------
void Del_All(linklist& L) {
    lnode *p, *pre, *minp, *minpre;
    while (L->next != L) {
        p = L->next;
        pre = L;
        minp = p;
        minpre = pre;
        while (p != L) {
            if (p->data < minp->data) {
                minp = p;
                minpre = pre;
            }
            pre = p;
            p = p->next;
        }
        printf("%d ", minp->data);
        minpre->next = minp->next;
        free(minp);
    }
    free(L);
    L = nullptr;
}
// ---------------------------------------------------------------

int main(int argc, char** argv) {
    linklist L;
    buildlsit(L);
    disp(L);
    cout << "-------" << endl;
    // Del_All(L);
    del_all_min(L);
    disp(L);
    return 0;
}