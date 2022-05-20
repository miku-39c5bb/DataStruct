/*
从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删元素的值，
空出的位置由最后一个元素填补，若顺序表为空，则显示出错信息并退出运行
*/
#include <bits/stdc++.h>
using namespace std;
#define Max 50
typedef int ElemType;
struct SqList {
    ElemType data[Max] = {2, 3, 4, 5, 6, 7, 1, 8, 9};
    int length = 9;
};

bool DeleteMin(SqList& L, ElemType& value) {
    if (L.length == 0) {
        return false;
    }
    value = L.data[0];
    int pos = 0;
    for (int i = 0; i < L.length; ++i) {
        if (value > L.data[i]) {
            value = L.data[i];
            pos = i;
        }
    }
    L.data[pos] = L.data[L.length - 1];
    L.length--;
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

    cout << "------------------------------------------" << endl;

    int elem = 0;
    DeleteMin(L, elem);
    cout << elem << endl;
    showElem(L);

    cout << "------------------------------------------" << endl;

    return 0;
}