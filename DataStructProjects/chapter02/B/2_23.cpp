#include <bits/stdc++.h>
using namespace std;
typedef struct lnode {
    char data;
    struct lnode* next;
} lnode, *linklist;
void buildlist(linklist& L) {
    L = new lnode;
    L->next = NULL;
    lnode *s, *r = L;
    string x_str;
    cin >> x_str;
    const char* x = x_str.c_str();
    int i = 0;
    while (x[i] != '\0') {
        s = new lnode;
        s->data = x[i++];
        r->next = s;
        r = s;
    }
    r->next = NULL;
}
void merge(linklist& L, linklist& tail) {
    lnode* r = L;
    while (r->next != NULL)
        r = r->next;
    r->next = tail->next;
}
void disp(linklist L) {
    lnode* p = L->next;
    while (p != NULL) {
        cout << p->data;
        p = p->next;
    }
    cout << endl;
}

// 我写的------------------------------------------
// time complexity: O(n)
// space complexity: O(1)
int get_len(linklist L) {
    lnode* p = L->next;
    int count = 0;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}
lnode* find_common(linklist& la, linklist& lb) {
    int len_a = get_len(la), len_b = get_len(lb);
    linklist _long, _short;
    int dist;
    if (len_a >= len_b) {
        _long = la->next;
        _short = lb->next;
        dist = len_a - len_b;
    } else {
        _long = lb->next;
        _short = la->next;
        dist = len_b - len_a;
    }
    for (int i = 0; i < dist; ++i)
        _long = _long->next;
    while (_long != _short) {
        _long = _long->next;
        _short = _short->next;
    }
    return _long;
}
// ------------------------------------------

// 书上的答案------------------------------------------
// time complexity: O(len1+len2) 或 O(max(len1,len2))
int listlen(lnode* head) {
    int len = 0;
    while (head->next != NULL) {
        len++;
        head = head->next;
    }
    return len;
}
lnode* find_addr(lnode* str1, lnode* str2) {
    int m, n;
    lnode *p, *q;
    m = listlen(str1);
    n = listlen(str2);
    for (p = str1; m > n; m--)
        p = p->next;
    for (q = str2; m < n; n--)
        q = q->next;
    while (p->next != NULL && p->next != q->next) {
        p = p->next;
        q = q->next;
    }
    return p->next;
}
// ------------------------------------------

int main(int argc, char** argv) {
    linklist tail;
    buildlist(tail);
    disp(tail);
    cout << "------------" << endl;
    linklist L1;
    buildlist(L1);
    disp(L1);
    cout << "------------" << endl;
    linklist L2;
    buildlist(L2);
    disp(L2);
    cout << "------------" << endl;
    merge(L1, tail);
    merge(L2, tail);
    delete tail;
    disp(L1);
    disp(L2);
    cout << "------------" << endl;
    lnode* my_tail = find_common(L1, L2);
    if (my_tail == NULL)
        cout << "没有相同结尾" << endl;
    else {
        cout << "------tail------" << endl;
        lnode* p = my_tail;
        while (p != NULL) {
            cout << p->data;
            p = p->next;
        }
        cout << endl;
    }
    lnode* my_tail2 = find_addr(L1, L2);
    if (my_tail2 == NULL)
        cout << "没有相同结尾" << endl;
    else {
        cout << "------tail2------" << endl;
        lnode* p = my_tail;
        while (p != NULL) {
            cout << p->data;
            p = p->next;
        }
        cout << endl;
    }
    return 0;
}