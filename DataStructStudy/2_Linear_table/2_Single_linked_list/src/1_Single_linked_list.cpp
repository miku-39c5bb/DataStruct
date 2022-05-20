/*
 * 不带头结点，写代码更麻烦
 * 对第一个数据结点和后续数据结点的处理需要用不同的代码逻辑
 * 对空表和非空表的处理需要用不同的代码逻辑
 */

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
struct LNode {
    ElemType data;
    struct LNode* next;
};
typedef struct LNode LNode;
typedef struct LNode* LinkList;

// 初始化一个空的单链表
bool InitList(LinkList& L) {
    L = NULL;  // 空表，暂时还没有任何结点【防止脏数据】
    return true;
}

// 判断单链表是否为空
bool Empty(LinkList L) {
    if (L == NULL) {
        return true;
    } else {
        return false;
    }
}

bool InsertNextNode(LNode* p, ElemType e) {
    if (p == NULL) {
        return false;
    }
    LNode* s = (LNode*)malloc(sizeof(LNode));
    if (s == NULL) {
        return false;
    }
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool ListInsert(LinkList& L, int i, ElemType e) {
    if (i < 1) {
        return false;
    }
    if (i == 1) {
        LNode* s = (LNode*)malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L = s;  // 头指针指向新结点
        return true;
    }
    LNode* p = L;                     // 指针p指向当前扫描到的结点
    int j = 0;                        // 当前p指向的是第几结点
    while (p != NULL && j < i - 1) {  // 循环找到第 i-1 个结点
        p = p->next;
        j++;
    }
    if (p == NULL) {  // i值不合法
        return false;
    }
    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

void test() {
    LinkList L;  // 声明一个指向单链表的指针【注意，此处并没有创建一个结点】
    InitList(L);  // 初始化一个空表
}

int main() {
    test();

    return 0;
}