#include <bits/stdc++.h>
using namespace std;

#define Max 50
typedef int ElemType;
struct SqList {
    ElemType data[Max] = {1, 2, 2, 4, 1, 1, 3, 32, 32, 1, 1, 14, 6, 77, 1, 4};
    int length = 16;
};

void del_x_1(SqList& L, ElemType x) {
    int k = 0;
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] != x) {  // 用k记录L中不等于x的元素个数
            L.data[k] = L.data[i];
            ++k;
        }
    }
    L.length = k;
}

void del_x_2(SqList& L, ElemType x) {
    int k = 0;
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] == x) {  // 用k记录L中等于x的元素个数
            ++k;
        } else {
            L.data[i - k] = L.data[i];
        }
    }
    L.length -= k;
}

void ShowELem(const SqList& L) {
    for (int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

int main() {
    SqList L;
    ShowELem(L);
    del_x_1(L, 1);
    ShowELem(L);

    return 0;
}