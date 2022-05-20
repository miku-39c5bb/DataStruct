#include <bits/stdc++.h>
using namespace std;
typedef struct LNode {
    int data;
    struct LNode* next;
} LNode, *LinkList;
void buildlist(LinkList& L) {
    L = (LinkList)malloc(sizeof(LNode));
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
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 我写的---------------------------------------------------------------
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
void reverse(LinkList& L) {
    LNode *pre, *p = L->next, *r = p->next;
    p->next = NULL;
    while (r != NULL) {
        pre = p;
        p = r;
        r = r->next;
        p->next = pre;
    }
    L->next = p;
}
void func(LinkList& L, LinkList& A, LinkList& B) {
    A = L;
    B = divide(A);
    reverse(B);
}
// ----------------------------------------------------------------

// 书上的答案---------------------------------------------------------------
LinkList DisCreat_2(LinkList& A) {
    LinkList B = (LinkList)malloc(sizeof(LNode));
    B->next = NULL;
    LNode *p = A->next, *q;
    LNode* ra = A;
    while (p != NULL) {
        ra->next = p;
        ra = p;
        p = p->next;
        if (p != NULL) {  // 先检查*p结点是否存在
            q = p->next;  // 头插法，使B逆序
            p->next = B->next;
            B->next = p;
            p = q;
        }
    }
    ra->next = NULL;  // A尾结点的next置为NULL
    return B;
}
// ----------------------------------------------------------------

int main() {
    LinkList L;
    buildlist(L);
    disp(L);

    // LinkList A, B;
    // func(L, A, B);

    LinkList A, B;
    A = L;
    B = DisCreat_2(A);

    disp(L);
    disp(A);
    disp(B);
    return 0;
}
