#include <bits/stdc++.h>
using namespace std;

#define Max 50
typedef int ElemType;
struct SqList {
    ElemType data[Max] = {3, 2, 6, 17, 8, 1, 16, 30, 13};
    int length = 9;
};

bool Del_s_t(SqList& L, int s, int t) {
    if (L.length == 0 || s >= t) {
        return false;
    }
    bool flag = false;
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] >= s) {
            flag = true;
            break;
        }
    }
    if (!flag) {
        return false;
    }

    int k = 0;
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] < s || L.data[i] > t) {
            L.data[k++] = L.data[i];
        }
    }
    L.length = k;
    return true;
}

bool Del_s_t2(SqList& L, int s, int t) {
    if (L.length == 0 || s >= t) {
        return false;
    }
    bool flag = false;
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] >= s) {
            flag = true;
            break;
        }
    }
    if (!flag) {
        return false;
    }

    int k = 0;
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] >= s && L.data[i] <= t) {
            ++k;
        } else {
            L.data[i - k] = L.data[i];
        }
    }
    L.length -= k;
    return true;
}

void showElem(const SqList& L) {
    for (int i = 0; i < L.length; i++) {
        cout << L.data[i] << "\t";
    }
    cout << endl;
}

int main() {
    SqList L;
    showElem(L);
    Del_s_t2(L, 3, 11);
    showElem(L);

    return 0;
}