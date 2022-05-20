#include <bits/stdc++.h>
using namespace std;

#define Max 50
typedef int ElemType;
struct SqList {
    ElemType data[Max] = {1, 1, 2, 3, 3, 3, 4, 5, 6, 6, 6, 6, 7, 8, 9, 10};
    int length = 16;
};

bool Del_Same(SqList& L) {
    if (L.length == 0) {
        return false;
    }

    int curVal = L.data[0];
    int k = 0;
    int i;
    for (i = 1; i < L.length; ++i) {
        if (curVal != L.data[i]) {
            L.data[k] = curVal;
            curVal = L.data[i];
            k++;
        }
    }
    if (L.data[k - 1] != curVal) {
        L.data[k] = curVal;
        k++;
    }
    L.length = k;
    return true;
}

bool Del_Same2(SqList& L) {
    if (L.length == 0) {
        return false;
    }
    int prev = L.data[0];
    int k = 0;
    for (int i = 1; i < L.length; i++) {
        if (L.data[i] == prev) {
            ++k;
        } else {
            L.data[i - k] = L.data[i];
            prev = L.data[i];
        }
    }
    L.length -= k;
    return true;
}

// 双指针法
bool Del_Same3(SqList& L) {
    if (L.length == 0)
        return false;
    int i = 0, j = 1;
    while (i < L.length && j < L.length) {
        if (L.data[i] == L.data[j]) {
            ++j;
        } else {
            L.data[i + 1] = L.data[j];
            ++i, ++j;
        }
    }
    L.length = i + 1;
    return true;
}
bool Del_Same4(SqList& L) {
    if (L.length == 0)
        return false;
    int i, j;
    for (i = 0, j = 1; j < L.length; ++j) {
        if (L.data[i] != L.data[j]) {
            // L.data[i + 1] = L.data[j];
            // ++i;
            L.data[++i] = L.data[j];
        }
    }
    L.length = i + 1;
    return true;
}

// black不同元素的个数，red工作指针
void deletelist(SqList& L) {
    int black = 1;
    for (int red = 1; red < L.length; red++) {
        if (L.data[red] != L.data[red - 1]) {
            L.data[black] = L.data[red];
            black++;
        }
    }
    L.length = black;
}

void showElem(const SqList& L) {
    for (int i = 0; i < L.length; i++) {
        cout << L.data[i] << "\t";
    }
    cout << endl;
}

void test() {
    SqList L;
    showElem(L);
    // Del_Same4(L);
    deletelist(L);
    showElem(L);
}

int main() {
    test();

    return 0;
}