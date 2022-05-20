/*** 
 * @Author: mikudouble
 * @Date: 2022-04-12 21:59:27
 * @LastEditTime: 2022-04-12 22:25:57
 * @LastEditors: mikudouble
 * @Description: 循环单链表
 * @FilePath: \Data Struct\2_Linear_table\4_Circular_linked_list\my_test\1.cpp
 */

#include <bits/stdc++.h>
using namespace std;

typedef int ElemType;
typedef struct LNode {
    ElemType* data;
    struct LNode* next;
} LNode, *LinkList;

bool InitList(LinkList& L) {
    L = (LNode*)malloc(sizeof(LNode));
    if (L == NULL) {
        return false;
    }
    L->next = L;  // 头结点next指向头结点
    return true;
}

bool Empty(LinkList L) {
    if (L->next == L) {
        return true;
    } else {
        return false;
    }
}

bool isTail(LinkList L, LNode* p) {
    if (p->next == L) {
        return true;
    } else {
        return false;
    }
}

/***
 * 从头结点找到尾部，时间复杂度为O(n)
 * 从尾部找到头部，时间复杂度为O(1)
 * 很多时候对链表的操作都是在 **头部** 或 **尾部**
 * 可以让 **L指向表尾元素** （插入、删除时可能需要修改L）
 */

int main(int argc, char** argv) {
    return 0;
}