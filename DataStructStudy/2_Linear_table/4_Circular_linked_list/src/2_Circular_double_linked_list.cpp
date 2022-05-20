/*** 
 * @Author: mikudouble
 * @Date: 2022-04-12 22:23:57
 * @LastEditTime: 2022-04-13 00:16:58
 * @LastEditors: mikudouble
 * @Description: 循环双链表
 * @FilePath: \Data Struct\2_Linear_table\4_Circular_linked_list\src\2_Circular_double_linked_list.cpp
 */

#include <bits/stdc++.h>

typedef int ElemType;
typedef struct DNode {
    ElemType* data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

bool InitList(DLinkList& L) {
    L = (DNode*)malloc(sizeof(DNode));
    if (L == NULL) {
        return false;
    }
    L->prior = L;  //头结点的prior指向头结点
    L->next = L;   //头结点的next指向头结点
    return true;
}

bool Empty(DLinkList L) {
    if (L->next == L) {
        return true;
    } else {
        return false;
    }
}

bool isTail(DLinkList L, DNode* p) {
    if (p->next == L) {
        return true;
    } else {
        return false;
    }
}

bool InsertNextDNode(DNode* p, DNode* s) {
    if (p == NULL || s == NULL) {
        return false;
    }
    s->next = p->next;
    p->next->prior = s;  // 注意这一步与普通双链表的区别
    s->prior = p;
    p->next = s;
    return true;
}

bool InsertFrontDNode(DNode* p, DNode* s) {
    DNode* prev = p->prior;
    if (prev == NULL) {
        return false;
    }
    return InsertNextDNode(prev, s);
}

bool DeleteNextDNode(DNode* p) {
    if (p == NULL) {
        return false;
    }
    DNode* q = p->next;
    if (q == NULL) {
        return false;
    }
    p->next = q->next;
    q->next->prior = p;  // 注意这一步与普通双链表的区别
    free(q);
    return true;
}

void testDLinkList() {
    DLinkList L;
    InitList(L);
}

int main(int argc, char** argv) {
    return 0;
}