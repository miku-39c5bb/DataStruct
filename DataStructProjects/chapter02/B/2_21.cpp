#include <bits/stdc++.h>
using namespace std;
typedef struct lnode {
    int data;
    struct lnode* next;
} lnode, *linklist;
void buildlist(linklist& L) {
    L = (linklist)malloc(sizeof(lnode));
    L->next = NULL;
    lnode *s, *r = L;
    int x;
    cin >> x;
    while (x != 999) {
        s = (lnode*)malloc(sizeof(lnode));
        s->data = x;
        r->next = s;
        r = s;
        cin >> x;
    }
    r->next = NULL;
}
void disp(linklist L) {
    lnode* p = L->next;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
lnode* locate(linklist L, int x) {
    lnode* p = L->next;
    while (p && p->data != x)
        p = p->next;
    if (!p)
        cout << "未找到x: " << x << endl;
    return p;
}
void _circle(linklist& L) {
    int x;
    cin >> x;
    lnode* p = locate(L, x);
    lnode* r = L;
    while (r->next != NULL)
        r = r->next;
    r->next = p;
}

// 我写的---------------------------------------------------------------
bool isCircle(linklist& L) {
    map<lnode*, bool> hash;
    lnode* p = L->next;
    while (p != NULL) {
        if (hash[p] == true)
            return true;
        hash[p] = true;
        p = p->next;
    }
    return false;
}
// ---------------------------------------------------------------

// 书上的答案---------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(1)
lnode* FindLoopStart(lnode* head) {
    lnode *fast = head, *slow = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    if (fast == NULL || fast->next == NULL)
        return NULL;
    lnode *p1 = head, *p2 = slow;
    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}
// ---------------------------------------------------------------
lnode* _FindLoopStart(lnode* head) {
    lnode *fast = head, *slow = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
            break;
    }
    if (fast == NULL || fast->next == NULL)
        return NULL;
    lnode *p1 = head, *p2 = slow;
    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}

int main(int argc, char** argv) {
    linklist L;
    buildlist(L);
    disp(L);
    _circle(L);
    // if (isCircle(L))
    //     cout << "A circle!" << endl;
    // else
    //     cout << "Not a circle!" << endl;
    lnode* p = FindLoopStart(L);
    if (p) {
        cout << "A circle!" << endl;
        cout << p->data << endl;
    } else
        cout << "Not a circle!" << endl;

    return 0;
}