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
    string str;
    cin >> str;
    char* c = (char*)str.c_str();
    int i = 0;
    while (c[i] != '\0') {
        s = new lnode;
        s->data = c[i];
        r->next = s;
        r = s;
        ++i;
    }
    r->next = NULL;
}
void disp(linklist L) {
    lnode* p = L->next;
    while (p) {
        cout << p->data;
        p = p->next;
    }
    cout << endl;
}

#define Max 50
typedef struct {
    char data[Max];
    int top;
} Stack;
void InitStack(Stack& s) {
    s.top = -1;
}
bool StackEmpty(Stack s) {
    return s.top == -1;
}
bool StackFull(Stack s) {
    return s.top == Max - 1;
}
bool Push(Stack& s, char c) {
    if (s.top == Max - 1)
        return false;
    s.data[++s.top] = c;
    return true;
}
bool Pop(Stack& s, char& c) {
    if (s.top == -1)
        return false;
    c = s.data[s.top--];
    return true;
}
bool GetTop(Stack s, char& c) {
    if (s.top == -1)
        return false;
    c = s.data[s.top];
    return true;
}

int get_len(linklist L) {
    lnode* p = L->next;
    int res = 0;
    while (p) {
        res++;
        p = p->next;
    }
    return res;
}

// 我写的-----------------------------------------------
bool isDuiChen(linklist L) {
    int len = get_len(L);
    bool is_odd = len % 2 ? true : false;
    len /= 2;
    lnode* p = L->next;
    Stack s;
    InitStack(s);
    for (int i = 0; i < len; ++i) {
        Push(s, p->data);
        p = p->next;
    }
    if (is_odd)
        p = p->next;
    for (int i = 0; i < len; ++i) {
        char c;
        Pop(s, c);
        if (c != p->data)
            return false;
        p = p->next;
    }
    return true;
}
// -----------------------------------------------

// 书上的答案-----------------------------------------------
int dc(linklist L, int n) {
    int i;
    char s[n / 2];
    lnode* p = L->next;
    for (i = 0; i < n / 2; i++) {
        s[i] = p->data;
        p = p->next;
    }
    i--;
    if (n % 2 == 1)
        p = p->next;
    while (p && s[i] == p->data) {
        i--;
        p = p->next;
    }
    if (i == -1)
        return 1;
    else
        return 0;
}
// -----------------------------------------------

int main() {
    linklist L;
    buildlist(L);
    disp(L);
    int len = get_len(L);
    // if (isDuiChen(L))
    if (dc(L, len))
        cout << "是对称的" << endl;
    else
        cout << "不是对称的" << endl;
    return 0;
}
