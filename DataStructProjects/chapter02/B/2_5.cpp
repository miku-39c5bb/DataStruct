#include <bits/stdc++.h>
using namespace std;
typedef struct LNode {
    int data;
    struct LNode* next;
} LNode, *LinkList;
void buildlist(LinkList& L) {
    L = new LNode;
    L->next = NULL;
    LNode *s, *r = L;
    int x;
    cin >> x;
    while (x != 999) {
        s = new LNode;
        s->data = x;
        r->next = s;
        r = s;
        cin >> x;
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

void reverse(LinkList& L) {
    LNode *p = L->next, *q;
    L->next = NULL;
    while (p) {
        q = p;
        p = p->next;
        q->next = L->next;
        L->next = q;
    }
}

// 利用 -头查法- 逆置链表
// Time Complexity: O(n)
// Space Complexity: O(1)
LinkList Reverse_1(LinkList& L) {
    LNode *p, *r;    // p为工作指针，r为p的后继，以防断链
    p = L->next;     // 从第一个元素结点开始
    L->next = NULL;  // highlight: 先将头结点L的next置为NULL
    while (p) {      // miku // xudouble // xdd
        r = p->next;
        p->next = L->next;
        L->next = p;
        p = r;
    }
    return L;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
LinkList Reverse_2(LinkList& L) {
    LNode *pre, *p = L->next, *r = p->next;  // p指向第一个结点（从第一个结点开始）
    p->next = NULL;                          // 第一个结点对应逆置后的最后一个结点，next要置为NULL
    while (r != NULL) {                      // r==NULL时，即p是最后一个结点时（此时p的next已经在上一个循环中指向了前一个结点），循环结束
        pre = p;
        p = r;
        r = r->next;    // r防止断链
        p->next = pre;  // p的next指向*pre
    }
    L->next = p;  // L的next指向最后一个结点*p
    return L;
}

int main() {
    LinkList L;
    buildlist(L);
    disp(L);
    // reverse(L);
    // Reverse_1(L);
    Reverse_2(L);
    disp(L);
    return 0;
}
