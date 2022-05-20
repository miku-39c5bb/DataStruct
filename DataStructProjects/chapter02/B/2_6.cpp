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
void disp(LinkList& L) {
    LNode* p = L->next;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void _sort(LinkList& L) {
    LNode *p = L->next, *r;
    LNode* newL = new LNode;
    r = p->next;
    newL->next = p;
    p->next = NULL;
    p = r;
    LNode *np = L->next, *npre;
    while (p) {
        r = p->next;
        npre = newL;
        np = newL->next;
        while (np && p->data > np->data) {
            npre = npre->next;
            np = np->next;
        }
        p->next = np;
        npre->next = p;
        p = r;
    }
    L = newL;
}

void Sort(LinkList& L) {
    LNode *pre, *p = L->next;
    LNode* r = p->next;  // 保存*p后继结点指针，保证不断链
    p->next = NULL;      // 构造只含一个数据结点的有序表
    p = r;
    while (p != NULL) {
        r = p->next;  // 保存*p的后继结点指针
        pre = L;
        while (pre->next != NULL && pre->next->data < p->data)
            pre = pre->next;  // 在有序表中查找插入*p前驱结点*pre
        p->next = pre->next;  // 将*p插入到*pre之后
        pre->next = p;
        p = r;  // 扫描原单链表中剩下的结点
    }
}

int main() {
    LinkList L;
    buildlist(L);
    disp(L);
    // _sort(L);
    Sort(L);
    disp(L);
    return 0;
}
