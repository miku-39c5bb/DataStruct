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
    r->link = NULL;
}
void disp(linklist L) {
    lnode* p = L->link;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->link;
    }
    cout << endl;
}

// 我写的------------------------------------------
// time complexity: O(n)
// space complexity: O(1)
int find_last_k(linklist list, int k) {
    if (k == 0)
        return 0;
    lnode *slow = list, *fast = list;
    for (int i = 0; i < k; ++i) {
        if (fast == nullptr)
            break;
        fast = fast->link;
    }
    if (fast == nullptr)
        return 0;
    while (fast != nullptr) {
        slow = slow->link;
        fast = fast->link;
    }
    cout << "倒数第" << k << "个节点的data域的值为" << slow->data << "。" << endl;
    return 1;
}
// ------------------------------------------

// 书上的答案------------------------------------------
int Search_k(linklist list, int k) {
    lnode *p = list->link, *q = list->link;
    int count = 0;
    while (p != NULL) {
        if (count < k)  // 若count<k，则只移动快指针p
            count++;
        else  // 否则快慢指针p、q一起移动
            q = q->link;
        p = p->link;
    }
    if (count < k)
        return 0;
    else {
        printf("%d", q->data);
        return 1;
    }
}
// ------------------------------------------

int main(int argc, char** argv) {
    linklist L;
    buildlist(L);
    disp(L);
    int k;
    cin >> k;
    find_last_k(L, k);
    Search_k(L, k);
    return 0;
}