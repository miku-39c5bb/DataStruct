#include <bits/stdc++.h>
using namespace std;
typedef struct LNode {
    int data;
    struct LNode* next;
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
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 我写的---------------------------------------------------------------
linklist comb_dec(linklist& A, linklist& B) {
    linklist C = (linklist)malloc(sizeof(lnode));
    C->next = NULL;
    lnode *pa = A->next, *pb = B->next, *q;
    free(A);
    free(B);
    while (pa != NULL && pb != NULL) {
        if (pa->data < pb->data) {
            q = pa->next;  // miku 先用q保存pa的后继，防止断链
            pa->next = C->next;
            C->next = pa;
            pa = q;
        } else {
            q = pb->next;  // wowaka 先用q保存pa的后继，防止断链
            pb->next = C->next;
            C->next = pb;
            pb = q;
        }
    }
    while (pa != NULL) {
        q = pa->next;  // 初音未来 先用q保存pa的后继，防止断链
        pa->next = C->next;
        C->next = pa;
        pa = q;
    }
    while (pb != NULL) {
        q = pb->next;  // 初音未来 先用q保存pa的后继，防止断链
        pb->next = C->next;
        C->next = pb;
        pb = q;
    }
    return C;
}
// ---------------------------------------------------------------

// 书上的答案---------------------------------------------------------------
void MergeList(linklist& La, linklist& Lb) {
    lnode *r, *pa = La->next, *pb = Lb->next;
    La->next = NULL;
    while (pa && pb) {
        if (pa->data <= pb->data) {
            r = pa->next;
            pa->next = La->next;
            La->next = pa;
            pa = r;
        } else {
            r = pb->next;
            pb->next = La->next;
            La->next = pb;
            pb = r;
        }
    }
    if (pa)
        pb = pa;
    while (pb) {
        r = pb->next;
        pb->next = La->next;
        La->next = pb;
        pb = r;
    }
    free(Lb);
}
// ---------------------------------------------------------------

int main() {
    linklist A;
    buildlist(A);
    disp(A);
    linklist B;
    buildlist(B);
    disp(B);

    // linklist C = comb_dec(A, B);
    // disp(C);
    MergeList(A, B);
    disp(A);

    return 0;
}