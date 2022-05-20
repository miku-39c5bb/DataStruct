#include <bits/stdc++.h>
using namespace std;
typedef struct LNode {
    int data;
    struct LNode* next;
} LNode, *LinkList;
void buildlist(LinkList& L) {
    L = new LNode;
    L->next = nullptr;
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
    r->next = nullptr;
}
void disp(LinkList& L) {
    LNode* p = L->next;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void del_x_y(LinkList& L, int x, int y) {
    LNode *pre = L, *p = L->next, *r = p->next;
    while (p != nullptr) {
        if (p->data >= x && p->data <= y) {
            pre->next = r;
            delete p;
        } else
            pre = p;
        p = r;
        if (r != nullptr)
            r = r->next;
    }
}

void RangeDelete(LinkList& L, int min, int max) {
    LNode *pr = L, *p = L->next;  // p是检测指针，pr是其前驱
    while (p != NULL) {
        if (p->data > min && p->data < max) {  // 寻找到被删结点，删除
            pr->next = p->next;
            delete p;
            p = pr->next;
        } else {  // 否则继续寻找被删结点
            pr = p;
            p = p->next;
        }
    }
}

int main() {
    LinkList L;
    buildlist(L);
    disp(L);
    int x, y;
    cin >> x >> y;
    // del_x_y(L, x, y);
    RangeDelete(L, x, y);
    disp(L);
    return 0;
}