#include <bits/stdc++.h>
using namespace std;
typedef struct LNode {
    int data;
    struct LNode* next;
} LNode, *LinkList;
void buildlist(LinkList& L) {
    L = (LinkList)malloc(sizeof(LinkList));
    L->next = NULL;
    LNode *s, *r = L;
    int x;
    scanf("%d", &x);
    while (x != 999) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
}
void disp(LinkList L) {
    LNode* p = L->next;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 我写的---------------------------------------------------------------
LinkList divide(LinkList& L1) {
    LinkList L2 = (LinkList)malloc(sizeof(LNode));
    L2->next = L1->next->next;
    LNode *p1 = L1->next, *p2 = L2->next;
    while (p2 && p2->next) {
        p1->next = p2->next;
        p1 = p1->next;
        p2->next = p1->next;
        p2 = p2->next;
    }
    p1->next = NULL;
    return L2;
}

LinkList divide(LinkList& A) {
    LinkList B = (LinkList)malloc(sizeof(LNode));
    LNode* p = A->next;
    A->next = NULL;
    B->next = NULL;
    LNode *ra = A, *rb = B;
    while (p != NULL) {
        ra->next = p;
        ra = p;
        p = p->next;
        if (p == NULL)
            break;
        rb->next = p;
        rb = p;
        p = p->next;
    }
    ra->next = NULL;
    rb->next = NULL;
    return B;
}
// ---------------------------------------------------------------

// 书上的答案---------------------------------------------------------------
LinkList DisCreat_1(LinkList& A) {
    int i = 0;
    LinkList B = (LinkList)malloc(sizeof(LNode));
    B->next = NULL;
    LNode *ra = A, *rb = B, *p;
    p = A->next;
    A->next = NULL;
    while (p != NULL) {
        i++;
        if (i % 2 == 0) {
            rb->next = p;
            rb = p;
        } else {
            ra->next = p;
            ra = p;
        }
        p = p->next;
    }
    ra->next = NULL;
    rb->next = NULL;
    return B;
}
// ---------------------------------------------------------------

int main() {
    LinkList L;
    buildlist(L);
    disp(L);

    // LinkList L2 = divide(L);
    LinkList L2 = DisCreat_1(L);
    disp(L);
    disp(L2);
    return 0;
}