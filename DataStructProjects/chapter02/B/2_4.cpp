#include <bits/stdc++.h>
using namespace std;
typedef struct lnode {
    int data;
    struct lnode* next;
} lnode, *linklist;
void buildlist(linklist& L) {
    L = (linklist)malloc(sizeof(struct lnode));
    L->next = NULL;
    lnode *s, *r = L;
    int x;
    cin >> x;
    while (x != 999) {
        s = (lnode*)malloc(sizeof(struct lnode));
        s->data = x;
        r->next = s;
        r = s;
        cin >> x;
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

bool del_min(linklist& L) {
       if (L == nullptr || L->next == nullptr)
           return false;
    lnode *pre = L, *p = L;
    int min_data = INT_MAX;
    while (p->next) {
        if (p->next->data < min_data) {
            pre = p;
            min_data = p->next->data;
        }
        p = p->next;
    }
    p = pre->next;
    pre->next = p->next;
    free(p);
    return true;
}

// 改良代码（可读性更高）
// Time Complexity: O(n)
// Space Complexity: O(1)
linklist Delete_Min(linklist& L) {
    lnode *pre = L, *p = L->next;
    lnode *minpre = pre, *minp = p;
    while (p != NULL) {
        if (p->data < minp->data) {
            minpre = pre;
            minp = p;
        }
        pre = pre->next;
        p = p->next;
    }
    minpre->next = minp->next;
    free(minp);
    return L;
}

int main() {
    linklist L;
    buildlist(L);
    disp(L);
    //    del_min(L);
    Delete_Min(L);
    disp(L);
    return 0;
}
