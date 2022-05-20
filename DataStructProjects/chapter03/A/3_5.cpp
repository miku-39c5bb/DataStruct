#include <bits/stdc++.h>
using namespace std;

#define MaxSize 50
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int top[2];
} ShStack;
void InitStack(ShStack& s) {
    s.top[0] = -1;
    s.top[1] = MaxSize;
}
bool Push(ShStack& s, int flag, ElemType x) {
    if (flag < 0 || flag > 1) {
        cout << "栈号不对" << endl;
        exit(0);
    }
    if (s.top[0] + 1 == s.top[1])
        return false;
    switch (flag) {
        case 0:
            s.data[++s.top[0]] = x;
            break;
        case 1:
            s.data[--s.top[1]] = x;
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
            if (s.top[0] == -1)
                return false;
            x = s.data[s.top[0]--];
            break;
        case 1:
            if (s.top[1] == MaxSize)
                return false;
            x = s.data[s.top[1]++];
    }
    return true;
}

int main() {
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
    return 0;
}