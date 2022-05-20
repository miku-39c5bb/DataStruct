/*** 
 * @Author: mikudouble
 * @Date: 2022-03-28 17:13:20
 * @LastEditTime: 2022-04-12 22:49:01
 * @LastEditors: mikudouble
 * @Description: 双链表
 * @FilePath: \Data Struct\2_Linear_table\3_Double_linked_list\src\1_Double_linked_list.cpp
 */
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct DNode {
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

// 初始化双链表
bool InitDLinkList(DLinkList& L) {
    L = (DNode*)malloc(sizeof(DNode));
    if (L == NULL) {
        return false;
    }
    L->prior = NULL;  //头结点的prior永远指向NULL
    L->next = NULL;   //头结点之后暂时还没有节
    return true;
}

bool Empty(DLinkList L) {
    if (L->next == NULL) {
        return true;
    } else {
        return false;
    }
}

// 在p结点之后插入s结点
bool InsertNextDNode(DNode* p, DNode* s) {
    if (p == NULL || s == NULL) {  // 非法参数
        return false;
    }
    s->next = p->next;
    if (p->next != NULL) {  // 如果p结点有后继结点
        p->next->prior = s;
    }
    s->prior = p;
    p->next = s;
    return true;
}

// 在p结点之前插入s结点
bool InsertFrontDNode(DNode* p, DNode* s) {
    DNode* prev = p->prior;  // 找到*p的前一个结点*prev
    if (prev == NULL) {      // 如果*prev不存在，返回false
        return false;
    }
    return InsertNextDNode(prev, s);  // 对*prev执行后插法
}

bool DeleteNextDNode(DNode* p) {
    if (p == NULL) {  // 非法参数
        return false;
    }
    DNode* q = p->next;  // 找到p的后继结点
    if (q == NULL) {     // p没有后继结点，无法删除结点
        return false;
    }
    p->next = q->next;
    if (q->next != NULL) {  // q不是最后一个结点
        q->next->prior = p;
    }
    free(q);  // 释放结点空间
    return true;
}

void DestoryList(DLinkList& L) {
    // 循环释放各个数据结点，每次都删除头结点的后继节点
    while (L->next != NULL) {
        DeleteNextDNode(L);
    }
    free(L);   // 释放头结点
    L = NULL;  // 头指针指向NULL
}

void Traversal(DNode* p) {
    // 后向遍历
    while (p != NULL) {
        // 对结点p做相应处理，如打印
        p = p->next;
    }

    // 前向遍历
    while (p != NULL) {
        // 对结点p做相应处理
        p = p->prior;
    }

    // 前序遍历（跳过头结点）
    while (p->prior != NULL) {
        // 对结点p做相应处理
        p = p->prior;
    }
}

void testDLinkList() {
    DLinkList L;
    InitDLinkList(L);
}

int main() {
    return 0;
}