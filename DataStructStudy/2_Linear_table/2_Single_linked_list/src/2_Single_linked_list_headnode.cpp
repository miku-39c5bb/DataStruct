/*
 * 带头结点，写代码更方便，用过都说好
 */

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode* next;
} LNode, *LinkList;

bool InitList(LinkList& L) {
    L = (LNode*)malloc(sizeof(LNode));  // 分配一个头结点
    if (L == NULL) {                    // 内存不足，分配失败
        return false;
    }
    L->next = NULL;  // 头结点之后暂时还没有节点
    return true;
}

// 头插法——逆序建立单链表
// 头插法的重要应用——链表的逆置
LinkList List_HeadInsert(LinkList& L) {
    L = (LinkList)malloc(sizeof(LNode));
    // 初始化为空链表，养成好习惯，只要是初始化单链表，都先把头指针指向NULL
    L->next = NULL;

    LNode* s;
    ElemType x;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

// 尾插法
LinkList List_TailInsert(LinkList& L) {
    L = (LinkList)malloc(sizeof(LNode));  // 建立头结点，初始化空表
    L->next = NULL;
    LNode *s, *r = L;  // r为表尾指针
    ElemType x;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;  // r指向新的表尾结点
        scanf("%d", &x);
    }
    r->next = NULL;  // 表尾结点指针置空
    return L;
}

bool Empty(LinkList L) {
    if (L->next == NULL) {
        return true;
    } else {
        return false;
    }
}

// 按位查找操作：获取表L中第i个位置的元素的值
LNode* GetElem(LinkList L, int i) {
    if (i < 0) {
        return NULL;
    }
    LNode* p = L;                 //指针p指向当前扫描到的结点
    int j = 0;                    // 当前p指向的是第几个结点
    while (p != NULL && j < i) {  //循环找到第i个结点
        p = p->next;
        j++;
    }
    return p;
}

// 按值查找，找到数据域==e的结点
LNode* LocateElem(LinkList L, ElemType e) {
    LNode* p = L->next;
    while (p != NULL && p->data != e) {
        p = p->next;
    }
    return p;  // 找到后返回该结点指针，否则返回NULL
}

int Length(LinkList L) {
    int len = 0;
    LNode* p = L;
    while (p->next != NULL) {
        p = p->next;
        len++;
    }
    return len;
}

// 按值查找操作：在表L中查找具有给定关键字值的元素

// 前插操作：在p结点之前插入元素e
// 1、传入头指针，O(n)
// bool InsertPriorNode(LinkList L, LNode* p, ElemType e) {}
// 2、交换结点的值O(1)
bool InserPriorNode(LNode* p, ElemType e) {
    if (p == NULL) {
        return false;
    }
    LNode* s = (LNode*)malloc(sizeof(LNode));
    if (s == NULL) {
        return false;
    }
    s->next = p->next;
    p->next = s;        //新结点S连到p之后
    s->data = p->data;  //将p中元素复制到s中
    p->data = e;        // p中元素覆盖为e
    return true;
}

// 后插操作：在p结点之后插入元素e
bool InsertNextNode(LNode* p, ElemType e) {
    if (p == NULL) {  // 考虑到非法情况，健壮性
        return false;
    }
    LNode* s = (LNode*)malloc(sizeof(LNode));
    if (s == NULL) {  // 内存分配失败
        return false;
    }
    s->data = e;
    s->next = p->next;
    p->next = s;  // 将结点s连到p之后
    return true;
}

bool ListInsert(LinkList& L, int i, ElemType e) {
    if (i < 1) {  // 位序不合法
        return false;
    }
    // LNode* p;  // 指针p指向当前扫描到的结点
    // int j = 0;  // 当前p指向的是第几个结点，头结点对应的位序应该是0
    // p = L;  // L指向头结点，头结点是第0个结点（不存数据）
    // while (p != NULL && j < i - 1) {  // 循环找到第1-1个结点
    //     p = p->next;
    //     j++;
    // }
    LNode* p = GetElem(L, i - 1);

    // if (p == NULL) {  // 位序i不合法
    //     return false;
    // }
    // LNode* s = (LNode*)malloc(sizeof(LNode));
    // s->data = e;
    // s->next = p->next;
    // p->next = s;  //将结点s连到p之后
    // return true;  //插入成功
    return InsertNextNode(p, e);
}

// 删除指定结点p
// 如果p是最后一个结点，p->next == NULL 怎么办
// (只能从表头开始一次查找，直到找到p的前驱)
// 因此这个函数有问题
bool DeleteNode(LNode* p) {
    if (p == NULL) {
        return false;
    }
    LNode* q = p->next;       //令q指向*p的后继结点
    p->data = p->next->data;  //和后继结点交换数据域
    p->next = q->next;        //将*q结点从链中“断开”
    free(q);                  //释放后继结点的存储空间
    return true;
}

bool ListDelete(LinkList& L, int i, ElemType& e) {
    if (i < 1) {
        return false;
    }
    // LNode* p = L;
    // int j = 0;
    // while (p != NULL && j < i - 1) {
    //     p = p->next;
    //     j++;
    // }
    LNode* p = GetElem(L, i - 1);
    if (p == NULL) {  // i值不合法
        return false;
    }
    if (p->next == NULL) {  // 第i-1个结点之后已无其他结点
        return false;
    }

    LNode* q = p->next;  // 令q指向被删除结点
    e = q->data;         // 用e返回元素的值
    p->next = q->next;   // 将*q结点从链中“断开”
    free(q);             // 释放结点的存储空间
    return true;         // 删除成功
}

void test() {
    LinkList L;
    InitList(L);
    ListInsert(L, 1, 3);
    if (Empty(L)) {
        printf("Empty\n");
    } else {
        printf("No empty\n");
    }
}

int main() {
    test();

    return 0;
}