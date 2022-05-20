/*
找两条链表的公共结点
*/
#include <bits/stdc++.h>
using namespace std;
typedef struct LNode {
    int data;
    struct LNode* next;
} LNode, *LinkList;
void buildlist(LinkList& L) {
    L = new LNode;
    L->next = NULL;
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
    r->next = NULL;
}
void disp(LinkList& L) {
    LNode* p = L->next;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
void merge(LinkList& L, LinkList& tail) {
    LNode* r = L;
    while (r->next) {
        r = r->next;
    }
    r->next = tail->next;
}

/***
 * 1. 先要分别遍历两个链表得到它们的长度，并求出：两个长度之差
 * 2. 在长的链表上先遍历长度之差个结点后
 * 3. 再同步遍历两个链表，直到找到相同的结点，或者一直到链表结束
 * 
 * Time Complexity: O(len1+len2)
 */

int Length(LinkList L) {
    LNode* p = L->next;
    int res = 0;
    while (p != NULL) {
        p = p->next;
        res++;
    }
    return res;
}
LinkList Search_lst_Common(LinkList& L1, LinkList& L2) {
    int len1 = Length(L1), len2 = Length(L2);
    LinkList longList, shortList;
    int dist = 0;
    if (len1 > len2) {
        longList = L1->next;
        shortList = L2->next;
        dist = len1 - len2;
    } else {
        longList = L2->next;
        shortList = L1->next;
        dist = len2 - len1;
    }
    for (int i = 0; i < dist; ++i) {
        longList = longList->next;
    }
    while (longList != shortList) {
        longList = longList->next;
        shortList = shortList->next;
    }
    return longList;
}

LinkList findd1(LinkList& L1, LinkList& L2) {
    LNode *s1 = L1->next, *s2 = L2->next;
    while (s1) {
        s2 = L2->next;
        while (s2) {
            if (s2 == s1) {
                return s1;
            } else
                s2 = s2->next;
        }
        s1 = s1->next;
    }
    return NULL;
}
LinkList findd2(LinkList& L1, LinkList& L2) {
    int len1 = Length(L1), len2 = Length(L2);
    LinkList _long, _short;
    int dist = 0;
    if (len1 > len2) {
        _long = L1->next;
        _short = L2->next;
        dist = len1 - len2;
    } else {
        _long = L2->next;
        _short = L1->next;
        dist = len2 - len1;
    }
    while (dist--)
        _long = _long->next;
    while (_long != NULL) {
        if (_long == _short) {
            return _long;
        } else {
            _long = _long->next;
            _short = _short->next;
        }
    }
    return NULL;
}

int main() {
    cout << "------tail-------" << endl;
    LinkList tail;
    buildlist(tail);
    cout << "------L1-------" << endl;
    LinkList L1;
    buildlist(L1);
    merge(L1, tail);
    disp(L1);
    cout << "------L2-------" << endl;
    LinkList L2;
    buildlist(L2);
    merge(L2, tail);
    disp(L2);
    cout << "------Common List-------" << endl;
    LinkList common_L = new LNode;
    // common_L->next = Search_lst_Common(L1, L2);
    // common_L->next = findd1(L1, L2);
    common_L->next = findd2(L1, L2);
    disp(common_L);
    return 0;
}