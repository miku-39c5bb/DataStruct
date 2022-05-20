/*
逆置线性表
*/
#include <bits/stdc++.h>
using namespace std;
#define Max 10
typedef int ElemType;
struct SqList {
    ElemType data[Max] = {1, 6, 2, 5, 2, 0};
    int length = 6;
};

void Reverse(SqList& L) {
    int left = 0, right = L.length - 1;
    ElemType temp;
    while (left < right) {
        temp = L.data[left];
        L.data[left] = L.data[right];
        L.data[right] = temp;
        left++;
        right--;
    }
}

void ShowElem(const SqList& L) {
    for (int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

int main() {
    SqList L;
    ShowElem(L);
    Reverse(L);
    ShowElem(L);

    return 0;
}