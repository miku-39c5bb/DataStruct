#include <bits/stdc++.h>
using namespace std;
typedef struct lnode {
    int data;
    struct lnode* next;
} lnode, *linklist;
void buildlist(linklist& L) {
    L = (linklist)malloc(sizeof(lnode));
    L->next = NULL;
    lnode *s, *r = L;
    int x;
    scanf("%d", &x);
    while (x != 999) {
        s = (lnode*)malloc(sizeof(lnode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
}
void disp(linklist L) {
    if (!L)
        return;
    lnode* p = L->next;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 我写的---------------------------------------------------------------
void union_(linklist& A, linklist& B) {
    lnode *pa = A->next, *pb = B->next;
    lnode* r = A;
    r->next = NULL;
    while (pa && pb) {
        if (pa->data == pb->data) {
            r->next = pa;
            r = pa;
            pa = pa->next;
            pb = pb->next;
        } else if (pa->data < pb->data) {
            pa = pa->next;
        } else {
            pb = pb->next;
        }
    }
    r->next = NULL;
}
// ---------------------------------------------------------------

// 书上的答案---------------------------------------------------------------
linklist Union(linklist& la, linklist& lb) {
    lnode *pa = la->next, *pb = lb->next;
    lnode *pc = la, *u;
    while (pa && pb) {
        if (pa->data == pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
            u = pb;
            pb = pb->next;
            free(u);
        } else if (pa->data < pb->data) {
            u = pa;
            pa = pa->next;
            free(u);
        } else {
            u = pb;
            pb = pb->next;
            free(u);
        }
    }
    while (pa) {
        u = pa;
        pa = pa->next;
        free(u);
    }
    while (pb) {
        u = pb;
        pb = pb->next;
        free(u);
    }
    pc->next = NULL;
    free(lb);
    lb = NULL;
    return la;
}
// ---------------------------------------------------------------

int main() {
    linklist L1;
    buildlist(L1);
    disp(L1);
    linklist L2;
    buildlist(L2);
    disp(L2);
    cout << "------------" << endl;
    // union_(L1, L2);
    Union(L1, L2);
    disp(L1);
    disp(L2);
    return 0;
}