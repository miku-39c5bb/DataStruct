#include <bits/stdc++.h>
using namespace std;
typedef struct lnode {
    int data;
    struct lnode* link;
} lnode, *linklist;
void buildlist(linklist& L) {
    L = new lnode;
    L->link = nullptr;
    lnode *s, *r = L;
    int x;
    cin >> x;
    while (x != 999) {
        s = new lnode;
        s->data = x;
        r->link = s;
        r = s;
        cin >> x;
    }
    r->link = nullptr;
}
void disp(linklist& L) {
    lnode* p = L->link;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->link;
    }
    cout << endl;
}

// 我写的------------------------------------------
// time complexity: O(n)
// space complexity: ???
void del_abs_com(linklist& L) {
    lnode *p = L->link, *pre, *u;
    map<int, bool> hash;
    while (p != nullptr) {
        int data = abs(p->data);
        if (!hash.count(data)) {
            hash[data] = true;
        }
        p = p->link;
    }
    pre = L;
    while (pre->link != NULL) {
        int data = abs(pre->link->data);
        if (hash[data]) {
            hash[data] = false;
            pre = pre->link;
        } else {
            u = pre->link;
            pre->link = u->link;
            delete u;
        }
    }
}
// ------------------------------------------

// 书上的答案------------------------------------------
// typedef struct node {
//     int data;
//     struct node* link;
// } NODE;
// typedef NODE* PNODE;

// time complexity: O(m)
// space complexity: O(n)
void func(linklist h, int n) {
    linklist p = h, r;
    int *q, m;
    q = new int[n + 1];
    for (int i = 0; i < n + 1; i++)  // 申请n+1个位置的辅助空间
        *(q + i) = 0;                // 数组元素初值置为0
    // memset(q, 0, sizeof(int) * (n + 1)); // 上面两行可用memset替换
    while (p->link != NULL) {
        m = p->link->data > 0 ? p->link->data : -p->link->data;
        if (*(q + m) == 0) {  // 判断该结点是否出现过
            *(q + m) = 1;     // 出现一次就置为1
            p = p->link;
        } else {
            r = p->link;  // 删除已经出现过的结点
            p->link = r->link;
            delete r;
        }
    }
    delete[] q;  // 释放辅助空间
}
// ------------------------------------------
void _func(linklist h, int n) {
    linklist p = h, r;
    int *q, m;
    q = new int[n + 1];
    memset(q, 0, sizeof(int) * (n + 1));
    while (p->link != NULL) {
        m = p->link->data > 0 ? p->link->data : -p->link->data;
        if (*(q + m) == 0) {
            *(q + m) = 1;
            p = p->link;
        } else {
            r = p->link;
            p->link = r->link;
            delete r;
        }
    }
    delete[] q;
}

int main(int argc, char** argv) {
    linklist L;
    buildlist(L);
    disp(L);
    // del_abs_com(L);
    int n;
    cin >> n;
    func(L, n);
    disp(L);
    return 0;
}