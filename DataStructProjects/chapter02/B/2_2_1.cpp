/*
删除带头结点的单链表L中所有值为x的结点
*/

#include <bits/stdc++.h>
using namespace std;

typedef int ElemType;
typedef struct SNode {
    ElemType data;
    struct SNode* next;
} SNode, *SqList;

bool InitList(SqList& L) {
    L = (SqList)malloc(sizeof(SNode));
    if (!L) {
        return false;
    }
    L->next = NULL;
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
void showList(const SqList& L) {
    SNode* p = L->next;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 递归
void del_x(SqList& L, int x) {
    if (L == NULL) {  // L不能为空
        return;
    }
    // 由于第一个结点也可能会被删除，所以声明p指向表头（第一个结点的前一个位置，方便删除）
    SNode* p = L;
    // 使用循环：如果p的下一个结点值为x，则删除
    while (p->next != NULL && p->next->data == x) {
        SNode* q = p->next;
        p->next = q->next;
        free(q);
    }  // 循环结束后，p的下一个结点值就不为x了，或者p就是尾结点
    // 如果p是最后一个结点，则退出  // 实际上，这个if可以省略
    if (p->next == NULL) {
        return;
    }
    // 执行下一次递归，第一个参数要变为p的下一个结点
    del_x(p->next, x);
}
// 更简洁的递归
void del_x1(SqList& L, int x) {
    if (L == NULL || L->next == NULL)
        return;
    SNode* p = L->next;
    if (p->data == x) {
        L->next = p->next;
        free(p);
        del_x1(L, x);
    } else
        del_x1(L->next, x);
}

// 非递归
void del_x2(SqList& L, int x) {
    if (!L)  // L不能为NULL
        return;
    // 由于第一个结点也可能会被删除，所以声明p指向表头（第一个结点的前一个位置），这样就可以比较方便地删除p的下一个位置的结点
    SNode* p = L;
    // 使用循环，直到p的下一个位置为NULL
    while (p->next != NULL) {
        if (p->next->data == x) {  // 如果p的下一个结点值为x，则删除
            SNode* q = p->next;
            p->next = q->next;
            free(q);
        } else {  // p的下一个结点值不为x，p可以往后移一位
            p = p->next;
        }
    }
}

// Time Complexity: O(n)
// Space Complexity: O(1)
void deletex_1(SqList& L, int x) {
    SNode *pre = L, *p = L->next, *q;
    while (p) {
        if (p->data == x) {
            q = p;
            p = p->next;
            pre->next = p;
            free(q);
        } else {
            pre = p;
            p = p->next;
        }
    }
}
// Time Complexity: O(n)
// Space Complexity: O(1)
void deletex_2(SqList& L, int x) {
    SNode *p = L->next, *r = L, *q;
    while (p) {
        if (p->data != x) {
            r->next = p;
            r = p;
            p = p->next;
        } else {
            q = p;
            p = p->next;
            free(q);
        }
    }
    r->next = NULL;
}

int main() {
    SqList L;
    InitList(L);
    // 1 2 3 4 5 6 78 9 5 5 5 3 4 5 55 5 5 5 5 4 5 5 5 999 9999
    // 5 5 3 2 5 5 5 4 5 5 9999
    List_Tail_Insert(L);
    showList(L);
    showList(L);
    // del_x(L, 5);
    del_x2(L, 5);
    // del_x2(L, 5);
    showList(L);

    return 0;
}