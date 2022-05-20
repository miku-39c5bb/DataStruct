#include <bits/stdc++.h>
using namespace std;

// #define MaxSize 50
// typedef int ElemType;
// struct SNode {
//     ElemType data;
//     int next;
// };
// struct SNode a[MaxSize];

#define MaxSize 50
typedef int ElemType;
typedef struct SNode {
    ElemType data;
    int next;
} SLinkList[MaxSize];
// SLinkList是一个类型，这个类型表示一个有MaxSize个元素的数组，每个元素都是一个struct SNode

bool InitList(SLinkList& S) {
    for (auto i : S) {
        i.next = -2;
    }
    S[0].next = -1;
    return true;
}

int GetElem(SLinkList S, int i) {
    if (i < 0) {
        return -1;  // -1等价于NULL
    }
    int p = 0;  // 静态链表的表头为第一个结点的下标，即0
    int j = 0;
    while (p != -1 && j < i) {
        p = S[p].next;
        j++;
    }
    return p;
}

bool InsertNextNode(SLinkList& S, int p, ElemType e) {
    if (p < 0) {
        return false;
    }
    int space_node;
    for (int i = 0; i < MaxSize; ++i) {
        if (S[i].next == -2) {
            space_node = i;
        }
    }
    S[space_node].data = e;
    S[space_node].next = S[p].next;
    S[p].next = space_node;
    return true;
}

bool LineInsert(SLinkList& S, int i, ElemType e) {
    if (i < 0) {
        return false;
    }
    int p = GetElem(S, i - 1);

    return InsertNextNode(S, p, e);
}

void testSLinkList() {
    SLinkList a;
}

int main(int argc, char* argv[]) {
    return 0;
}