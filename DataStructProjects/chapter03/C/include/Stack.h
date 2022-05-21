#ifndef __STACK_H
#define __STACK_H

#include <iostream>

typedef char ElemType;
typedef struct SNode {
    ElemType data;
    struct SNode* next;
} * Stack;

void InitStack(Stack& S) {
    S = nullptr;
}

bool StackEmpty(Stack& S) {
    return S == nullptr;
}

bool Push(Stack& S, ElemType e) {
    SNode* s = new SNode;
    if (s == nullptr)
        return false;
    s->data = e;
    s->next = S;
    S = s;
    return true;
}

bool Pop(Stack& S, ElemType& e) {
    if (S == nullptr)
        return false;
    SNode* p = S;
    e = p->data;
    S = S->next;
    delete p;
    return true;
}

#endif  // ! __STACK_H