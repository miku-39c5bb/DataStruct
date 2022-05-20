/*
删除不带头结点的单链表L中所有值为x的结点，用递归实现
*/

#include <bits/stdc++.h>
using namespace std;

typedef int ElemType;
typedef struct SNode {
    ElemType data;
    struct SNode* next;
} SNode, *SqList;
bool InitList(SqList& L) {
    L = (SNode*)malloc(sizeof(SNode));  // 分配一个头结点
    if (L == NULL) {                    // 内存不足，分配失败
        return false;
    }
    L->next = NULL;  // 头结点之后暂时还没有节点
    return true;
}
bool List_Tail_Insert(SqList& L) {
    if (!L) {
        return false;
    }
    SNode* r = L;
    SNode* s;
    ElemType x;
    scanf("%d", &x);
    while (x != 9999) {
        s = (SNode*)malloc(sizeof(SNode));
        s->data = x;
        // s->next = NULL;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return true;
}
bool List_HeadInsert(SqList& L) {
    if (!L) {
        return false;
    }
    SNode* p;
    ElemType x;
    scanf("%d", &x);
    while (x != 9999) {
        p = (SNode*)malloc(sizeof(SNode));
        p->data = x;
        p->next = L->next;
        L->next = p;
        scanf("%d", &x);
    }
    return true;
}
void showList(const SqList& L) {
    SNode* p = L;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void del_x(SqList& L, ElemType x) {
    if (!L)  // L不能为空，否则退出函数
        return;
    SNode* p = L;                        // 设p指向第一个结点（当前结点）L，这是为了方便删除节点
    while (L != NULL && L->data == x) {  // 进行循环：如果当前结点不为空，且data==x，那么删除当前结点
        L = L->next;                     // L置为下一个位置
        free(p);                         // 释放该节点
        p = L;                           // p也置为L的位置
    }
    if (L == NULL)  // 如果当前节点L为空，退出函数
        return;
    del_x(L->next, x);  // 继续下一次递归
}

/*
递归 del(L, x)
终止条件：L == NULL
递归主体：若L->data==x，删除*L结点，且递归调用del(L,x)【如果没有这次调用，那么删一次就不会再调用了】
        若L->data!=x，递归del(L->next, x)
*/
void deletex(SqList& L, ElemType x) {
    if (L == NULL)
        return;
    SNode* p = L;
    if (L->data == x) {
        L = L->next;
        free(p);
        deletex(L, x);  // 如果没有这次调用，那么删一次就不会再删除了
    } else
        deletex(L->next, x);
}

int main() {
    SqList L;
    // 1 2 3 4 5 6 78 9 5 5 5 3 4 5 55 5 5 5 5 4 5 5 5 999 9999
    // 5 5 3 2 5 5 5 4 5 5 9999
    InitList(L);
    // List_HeadInsert(L);
    List_Tail_Insert(L);
    L = L->next;
    showList(L);
    // del_x(L, 5);
    deletex(L, 1);
    showList(L);

    return 0;
}