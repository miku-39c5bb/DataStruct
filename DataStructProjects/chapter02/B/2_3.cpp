#include <bits/stdc++.h>
using namespace std;
#define Max 0xfffffff
typedef struct lnode {
    int data;
    struct lnode* next;
} lnode, *linklist;
void buildlist(linklist& L) {
    L = (linklist)malloc(sizeof(lnode));
    L->next = NULL;
    lnode *r = L, *s;
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

// 链表逆置
void R_disp(linklist L) {
    lnode *pre = L, *p = L->next, *q;
    pre->next = nullptr;
    while (p) {
        q = p;                // 需要用q取得p的位置
        p = p->next;          // p的位置后移一位，这一步的顺序不能改变
        q->next = pre->next;  // *q头插法——逆置链表
        pre->next = q;
    }
    p = pre->next;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 使用栈

// 递归
void R_Print(linklist L) {
    // if(L->next !=nullptr) R_Print(L->next);
    // if(L!=nullptr) cout << L->data << " ";
    if (L != nullptr) {
        R_Print(L->next);
        cout << L->data << " ";
    } else
        return;
}
void R_Ignore_Print(linklist L) {
    if (L->next != nullptr)
        R_Print(L->next);
    cout << endl;
}

int main() {
    linklist L;
    buildlist(L);
    R_Ignore_Print(L);
    R_disp(L);
    return 0;
}
