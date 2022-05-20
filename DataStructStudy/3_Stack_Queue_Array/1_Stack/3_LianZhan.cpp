// 链栈 —— 实质上就是一个单链表，不过只能在单链表的一端【一般是左端】进行删除和插入操作
// 可以分为 带头结点 和 不带头结点 的情况
// 推荐不带头结点

#include <bits/stdc++.h>
using namespace std;

typedef int ElemType;
typedef struct Linknode {  // 未带头结点
    ElemType data;
    struct Linknode* next;
} * LiStack;

void InitStack(LiStack& s) {
    if (s != NULL)
        free(s);
    s = NULL;
}
bool StackEmpty(LiStack s) {
    return s == NULL;
}
bool StackFull(LiStack s) {
    struct Linknode* p = (struct Linknode*)malloc(sizeof(struct Linknode));
    if (p == NULL)
        return true;
    else {
        free(p);
        return false;
    }
}
bool Push(LiStack& s, ElemType e) {
    struct Linknode* p = (struct Linknode*)malloc(sizeof(struct Linknode));
    if (p == NULL)
        return false;
    p->data = e;
    p->next = s;
    s = p;
    return true;
}
bool Pop(LiStack& s, ElemType& e) {
    if (s == NULL)
        return false;
    struct Linknode* r;
    r = s->next;
    e = s->data;
    free(s);
    s = r;
    return true;
}
bool GetTop(LiStack s, ElemType& e) {
    if (s == NULL)
        return false;
    e = s->data;
    return true;
}

int main() {
    // LiStack s;
    // buildStack(s);
    // disp(s);
    LiStack s;
    InitStack(s);
    int x;
    cin >> x;
    while (x != 999) {
        Push(s, x);
        cin >> x;
    }
    if (StackEmpty(s))
        cout << "栈空" << endl;
    else
        cout << "栈未空" << endl;
    while (Pop(s, x))
        cout << x << " ";
    cout << endl;
    if (StackEmpty(s))
        cout << "栈空" << endl;
    else
        cout << "栈未空" << endl;
    return 0;
}