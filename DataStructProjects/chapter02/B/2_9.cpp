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
    if (!L) {
        cout << "L == NULL ?" << endl;
        return;
    }
    LNode* p = L->next;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void Sort(LinkList& L) {
    LNode *pre = L, *p = L->next, *r = p->next;
    p->next = NULL;
    p = r;
    while (p) {
        r = p->next;
        pre = L;
        while (pre->next != NULL && pre->next->data < p->data)
            pre = pre->next;
        p->next = pre->next;
        pre->next = p;
        p = r;
    }
}
void Min_Del(LinkList& L) {
    Sort(L);
    LNode *p = L->next, *r;
    while (p) {
        r = p->next;
        cout << p->data << " ";
        delete p;
        p = r;
    }
    delete L;
    L = NULL;
}

void Min_Delete(LinkList& head) {
    while (head->next != NULL) {
        LNode* pre = head;
        LNode* p = pre->next;
        while (p->next != NULL) {
            if (p->next->data < pre->next->data)
                pre = p;
            p = p->next;
        }
        cout << pre->next->data << " ";
        LNode* u = pre->next;
        pre->next = u->next;
        delete u;
    }
    delete head;
    head = NULL;
}

int main() {
    LinkList L;
    buildlist(L);
    disp(L);
    // Min_Del(L);
    Min_Delete(L);
    cout << endl;
    disp(L);
    return 0;
}