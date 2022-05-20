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
    lnode* p = L->next;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 我写的---------------------------------------------------------------
linklist Get_Common_1(linklist A, linklist B) {
    linklist C = (linklist)malloc(sizeof(lnode));
    C->next = NULL;
    lnode *s, *r = C;
    A = A->next;
    B = B->next;
    while (A && B) {
        if (A->data == B->data) {
            s = (lnode*)malloc(sizeof(lnode));
            s->data = A->data;
            r->next = s;
            r = s;
            A = A->next;
            B = B->next;
        } else if (A->data < B->data) {
            A = A->next;
        } else {
            B = B->next;
        }
    }
    r->next = NULL;
    return C;
}
// ---------------------------------------------------------------

// 书上的答案---------------------------------------------------------------
linklist Get_Common_2(linklist A, linklist B) {
    lnode *p = A->next, *q = B->next, *r, *s;
    linklist C = (linklist)malloc(sizeof(lnode));
    r = C;
    while (p != NULL && q != NULL) {
        if (p->data < q->data) {
            p = p->next;
        } else if (p->data > q->data) {
            q = q->next;
        } else {
            s = (lnode*)malloc(sizeof(lnode));
            s->data = p->data;
            r->next = s;
            r = s;
            p = p->next;
            q = q->next;
        }
    }
    r->next = NULL;
    return C;
}
// ---------------------------------------------------------------
int main() {
    linklist L1, L2;
    buildlist(L1);
    disp(L1);
    buildlist(L2);
    disp(L2);
    cout << "-------------------------------" << endl;
    linklist L3 = Get_Common_1(L1, L2);
    disp(L1);
    disp(L2);
    disp(L3);
    return 0;
}