#include <bits/stdc++.h>
using namespace std;

#define Max 50
typedef int ElemType;
struct SqList {
    ElemType data[Max] = {1, 2, 3, 6, 8, 13, 16, 17, 30};
    int length = 9;
};

bool Del_s_t2(SqList& L, ElemType s, ElemType t) {
    if (s >= t || L.length == 0) {
        return false;
    }
    int ss = 0;
    bool flag = false;
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] >= s) {
            ss = i;
            flag = true;
            break;
        }
    }
    if (!flag) {  // s大于L中的所有数据
        return false;
    }
    int vv = 0;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] > t) {
            vv = i;
            break;
        }
    }
    for (; vv < L.length; ss++, vv++) {
        L.data[ss] = L.data[vv];
    }
    // L.length = L.length - (vv - ss);
    L.length = ss;
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
    Del_s_t2(L, 5, 10);
    showElem(L);

    return 0;
}