// 共享栈   ——  两个栈共享一个空间
// 栈满条件 ——  top0+1 == top1
#include <bits/stdc++.h>
using namespace std;

#define MaxSize 10
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int top0;
    int top1;
} ShStack;
void InitStack(ShStack& S) {
    S.top0 = -1;
    S.top1 = MaxSize;
}
bool Push(ShStack& s, int flag, ElemType x) {
    if (flag < 0 || flag > 1) {
        cout << "栈号不对" << endl;
        exit(0);
    }
    if (s.top0 + 1 == s.top1)
        return false;
    switch (flag) {
        case 0:
            s.data[++s.top0] = x;
            break;
        case 1:
            s.data[--s.top1] = x;
            break;
    }
    return true;
}
bool Pop(ShStack& s, int flag, ElemType& x) {
    if (flag < 0 || flag > 1) {
        cout << "栈号不对" << endl;
        exit(0);
    }
    switch (flag) {
        case 0:
            if (s.top0 == -1)
                return false;
            x = s.data[s.top0--];
            break;
        case 1:
            if (s.top1 == MaxSize)
                return false;
            x = s.data[s.top1++];
    }
    return true;
}

void test() {
    ShStack s;
    InitStack(s);
    ElemType x;
    cin >> x;
    while (x != 999) {
        Push(s, 0, x);
        cin >> x;
    }
    while (Pop(s, 0, x)) {
        cout << x << " ";
    }
    cout << endl;
    cin >> x;
    while (x != 999) {
        Push(s, 1, x);
        cin >> x;
    }
    while (Pop(s, 1, x)) {
        cout << x << " ";
    }
}

int main() {
    test();
    return 0;
}