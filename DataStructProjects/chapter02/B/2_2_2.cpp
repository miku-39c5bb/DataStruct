/*
删除带头结点的单链表L中所有值为x的结点
*/

#include <bits/stdc++.h>
using namespace std;
typedef struct lnode {
    int data;
    struct lnode* next;
} lnode, *linklist;
int a[4] = {1, 2, 3, 4};
void buildlist(linklist& L) {
    L = (linklist)malloc(sizeof(lnode));
    L->next = nullptr;
    lnode *s, *r = L;
    for (int i = 0; i < 4; i++) {
        s = (lnode*)malloc(sizeof(lnode));
        s->data = a[i];
        r->next = s;
        r = s;
    }
    r->next = nullptr;
}
void disp(const linklist& L) {
    lnode* p = L->next;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
void deletex(linklist& L, int x) {
    lnode *pre = L, *p = L->next, *q;
    while (p) {
        if (p->data == x) {
            q = p;
            p = p->next;
            pre->next = p;
            free(q);
        } else {
            pre = p;
            p = p->next;
        }
    }
}
// Time Complexity: O(n)
// Space Complexity: O(1)
void deletex_2(linklist& L, int x) {
    lnode *p = L->next, *r = L, *q;
    while (p) {
        if (p->data != x) {
            r->next = p;
            r = p;
            p = p->next;
        } else {
            q = p;
            p = p->next;
            free(q);
        }
    }
    r->next = NULL;
}
void del(linklist& L,int x) {
    if(!L)return;
    lnode*p=L;
    while(p->next) {
        if(p->next->data != x) {
            p=p->next;
        }else{
            lnode*q=p->next;
            p->next = q->next;
            free(q);
        }
    }
}

int main() {
    linklist L;
    buildlist(L);
    disp(L);
    // deletex(L, 3);
    // deletex_2(L, 3);
    del(L,1);
    disp(L);
    return 0;
}