#include <bits/stdc++.h>
using namespace std;
typedef struct node {
    int data;
    struct node* next;
} NODE;
typedef NODE* linklist;
void buildlist(linklist& L) {
    L = new NODE;
    L->next = NULL;
    NODE *s, *r = L;
    int x;
    cin >> x;
    while (x != 999) {
        s = new NODE;
        s->data = x;
        r->next = s;
        r = s;
        cin >> x;
    }
    r->next = NULL;
}
void disp(linklist L) {
    NODE* p = L->next;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 我写的------------------------------------------
// time complexity: O(n)
// space complexity: O(1)
int get_len(linklist L) {
    NODE* p = L->next;
    int res = 0;
    while (p) {
        res++;
        p = p->next;
    }
    return res;
}
void divide(linklist& L1, linklist& L2) {
    int len = get_len(L1);
    int len1;
    if (len % 2 == 0)
        len1 = len / 2;
    else
        len1 = len / 2 + 1;
    NODE *p = L1, *r;
    for (int i = 0; i < len1; i++) {
        p = p->next;
    }
    r = p->next;
    p->next = NULL;
    L2 = new NODE;
    L2->next = r;
}
void reverse(linklist& L) {
    NODE *pre, *p = L->next, *r = p->next;
    p->next = NULL;
    while (r != NULL) {
        pre = p;
        p = r;
        r = r->next;
        p->next = pre;
    }
    L->next = p;
}
void merge(linklist& L1, linklist& L2) {
    NODE *p1 = L1->next, *p2 = L2->next;
    NODE *r1, *r2;
    while (p1 && p2) {
        r1 = p1->next;
        r2 = p2->next;
        p2->next = p1->next;
        p1->next = p2;
        p1 = r1;
        p2 = r2;
    }
    delete L2;
}
void func(linklist& L) {
    linklist L2;
    divide(L, L2);
    reverse(L2);
    merge(L, L2);
}
// void divide(linklist& L1, linklist& L2) {
//     L2 = new NODE;
//     NODE *p1 = L1, *p2 = L2;  // p1尾插法，p2头插法
//     L2->next = NULL;
//     int i = 0;
//     NODE *p = L1->next, *r;  // p为工作指针，r防止断链
//     while (p != NULL) {
//         i++;
//         if (i % 2 == 0) {
//             r = p->next;
//             p->next = p2->next;
//             p2->next = p;
//             p = r;
//         } else {
//             p1->next = p;
//             p1 = p;
//             p = p->next;
//         }
//     }
//     p1->next = NULL;
// }
// void merge(linklist& L1, linklist& L2) {
//     NODE *p1 = L1->next, *p2 = L2->next;
//     NODE *r1, *r2;
//     while (p1 && p2) {
//         r1 = p1->next;
//         r2 = p2->next;
//         p2->next = p1->next;
//         p1->next = p2;
//         p1 = r1;
//         p2 = r2;
//     }
//     delete L2;
// }
// void func(linklist& L) {
//     linklist L2;
//     divide(L, L2);
//     merge(L, L2);
// }
// ------------------------------------------

// 书上的答案------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(1)
// 寻找中间结点->将链表后半段逆置->将逆置后的部分结点依次插入到前半段的链表
void change_list(linklist& h) {
    NODE *p, *q, *r, *s;
    p = q = h;
    while (q->next != NULL) {  // 寻找中间结点  Time Complexity: O(n)
        p = p->next;
        q = q->next;
        if (q->next != NULL)
            q = q->next;
    }
    q = p->next;
    p->next = NULL;      // 将链表后半段逆置  Time Complexity: O(n)
    while (q != NULL) {  // miku 这个过程一定要画图仔细分析 —— 相当于头插法，依次将q插入到p和NULL之间
        r = q->next;
        q->next = p->next;
        p->next = q;
        q = r;
    }
    q = p->next;
    p->next = NULL;  // 链表尾指针置空
    s = h->next;     // 将逆置后的部分结点依次插入到前半段的链表  Time Complexity: O(n)
    while (q != NULL) {
        r = q->next;
        q->next = s->next;
        s->next = q;
        s = q->next;  // s的位置后移2位
        q = r;
    }
}
// ------------------------------------------

int main() {
    linklist L;
    buildlist(L);
    disp(L);
    // func(L);
    change_list(L);
    disp(L);
    return 0;
}