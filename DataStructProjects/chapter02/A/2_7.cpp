#include <bits/stdc++.h>
using namespace std;

#define Max 50
typedef int ElemType;
struct SqList {
    ElemType data[Max] = {1, 2, 3, 3, 3, 4, 5, 6, 6, 6, 6, 7, 8, 9, 10};
    int length = 15;
    int maxSize = Max;
};

bool Merge(const SqList& A, const SqList& B, SqList& C) {
    if (A.length + B.length > C.maxSize) {
        return false;
    }
    C.length = 0;
    int i = 0, j = 0, k = 0;
    while (i < A.length && j < B.length) {
        if (A.data[i] <= B.data[j]) {
            C.data[k++] = A.data[i++];
        } else {
            C.data[k++] = B.data[j++];
        }
    }
    while (i < A.length) {  // TODO 还剩一个没有比较完的顺序表
        C.data[k++] = A.data[i++];
    }
    while (j < B.length) {
        C.data[k++] = B.data[j++];
    }
    C.length = k;
    return true;
}

void showElem(const SqList& L) {
    for (int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

void test() {
    SqList a = {{2, 3, 4, 6, 7}, 5};
    showElem(a);
    SqList b = {{3, 4, 4}, 3};
    showElem(b);
    SqList c;
    Merge(a, b, c);
    showElem(c);
}

int main() {
    test();

    return 0;
}