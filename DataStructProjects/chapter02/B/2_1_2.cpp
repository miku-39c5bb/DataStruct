/*
删除不带头结点的单链表L中所有值为x的结点，用递归实现
*/
#include <bits/stdc++.h>
using namespace std;
typedef struct lnode {
    int data;
    struct lnode* next;
} lnode;
int a[4] = {1, 2, 3, 4};
int n = 4;
void buildlist(lnode* L) {
    lnode *s, *r = L;
    r->data = a[0];
    if (n == 1)
        r->next = NULL;
    else {
        for (int i = 1; i < n; i++) {
            s = (lnode*)malloc(sizeof(lnode));
            s->data = a[i];
            r->next = s;
            r = s;
        }
        r->next = NULL;
    }
}
void disp(lnode* L) {
    lnode* s = L;
    while (s != nullptr) {
        cout << s->data << " ";
        s = s->next;
    }
    cout << endl;
}
// Time Complexity: O(n)
// Space Complexity: O(n)
void deletex(lnode*& L, int x) {
    if (L == NULL)
        return;
    lnode* p;
    if (L->data == x) {
        p = L;
        L = L->next;
        free(p);
        deletex(L, x);
    } else
        deletex(L->next, x);
}
int main() {
    // lnode list;  // 要用new，否则删除1会有问题，因为无法free()
    // lnode* L = &list;
    lnode* L = new lnode;
    buildlist(L);
    disp(L);
    deletex(L, 1);  
    disp(L);
    delete L;

    return 0;
}