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
void del_repeated(linklist& L) {
    lnode *first = L->next, *second = first->next;
    while (second != NULL) {
        while (second != NULL && first->data == second->data) {
            first->next = second->next;
            free(second);
            second = first->next;
        }
        first = second;
        second = second->next;
    }
    first->next = NULL;
}
// ---------------------------------------------------------------

// 书上的答案---------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(1)
void Del_Same(linklist& L) {
    lnode *p = L->next, *q;
    if (L == NULL)
        return;
    while (p->next != NULL) {
        q = p->next;
        if (p->data == q->data) {
            p->next = q->next;
            free(q);
        } else
            p = p->next;
    }
}
// ---------------------------------------------------------------

// 尾插法-------------------------------------------------------------
void Tail(linklist& L) {
    lnode *r = L->next, *p = r->next, *q;
    r->next = NULL;
    while (p != NULL) {
        if (p->data == r->data) {
            q = p->next;
            free(p);
            p = q;
        } else {
            r->next = p;
            r = p;
            p = p->next;
        }
    }
    r->next = NULL;
}
// ---------------------------------------------------------------

int main() {
    linklist L;
    buildlist(L);
    disp(L);
    // del_repeated(L);
    // Del_Same(L);
    Tail(L);
    disp(L);
    return 0;
}