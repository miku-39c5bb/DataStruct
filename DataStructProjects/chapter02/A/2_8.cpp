#include <bits/stdc++.h>
using namespace std;

#define Max 50
typedef int ElemType;
struct SqList {
    ElemType data[Max] = {1, 2, 3, 4, 5, 6, 7};
    int length = 7;
};

/*
reverse     0   m+n-1
reverse     0   n-1
reverse     n   m+n-1
*/
void reverse(SqList& L, int left, int right) {
    if (left >= right || right >= L.length) {
        return;
    }
    while (left < right) {
        ElemType tmp = L.data[left];
        L.data[left++] = L.data[right];
        L.data[right--] = tmp;
    }
}
// void reverse(SqList& L, int left, int right) {
//     if (left >= right || right >= L.length) {
//         return;
//     }
//     for (int i = left; i <= (left + right) / 2; i++) {
//         ElemType t = L.data[i];
//         L.data[i] = L.data[right + left - i];
//         L.data[right + left - i] = t;
//     }
// }
// void reverse(SqList& L, int left, int right) {
//     if (left >= right || right >= L.length) {
//         return;
//     }
//     int mid = (left + right) / 2;
//     for (int i = 0; i <= mid - left; i++) {
//         ElemType tmp = L.data[left + i];
//         L.data[left + i] = L.data[right - i];
//         L.data[right - i] = tmp;
//     }
// }
void prin(SqList& L) {
    for (int i = 0; i < L.length; ++i) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}
void change(SqList& L, int m, int n) {
    cout << "整个逆置：" << endl;
    reverse(L, 0, m + n - 1);
    prin(L);
    cout << "前n个逆置：" << endl;
    reverse(L, 0, n - 1);
    prin(L);
    cout << "后m个逆置：" << endl;
    reverse(L, n, m + n - 1);
    prin(L);
}

void test() {
    SqList L;
    change(L, 3, 4);  // m 123    n 4567
}

int main(int argc, char** argv) {
    test();

    return 0;
}