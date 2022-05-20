/*
 * @Author: mikudouble
 * @Date: 2022-03-16 00:03:31
 * @Last Modified by: mikudouble
 * @Last Modified time: 2022-03-16 00:11:06
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
struct LNode {
    ElemType data;
    struct LNode* next;
};
typedef struct LNode LNode;
typedef struct LNode* LinkList;

bool InitList(LinkList* L) {
    *L = (LNode*)malloc(sizeof(LNode));
    if (*L == NULL) {
        return false;
    }
    (*L)->next = NULL;
    return true;
}

bool Empty(LinkList L) {
    if (L->next == NULL) {
        return true;
    } else {
        return false;
    }
}

bool ListInsert(LinkList* L, int i, ElemType e) {
    if (i < 1) {
        return false;
    }
    LNode* p = *L;
    int j = 0;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL) {
        return false;
    }

    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

void test() {
    LinkList L;
    InitList(&L);
    ListInsert(&L, 1, 3);
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