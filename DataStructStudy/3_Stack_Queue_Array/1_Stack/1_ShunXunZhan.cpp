// 顺序栈   后进先出(LIFO)  top指向栈顶元素
// 缺点：顺序栈的大小不可改变
// 销？ ——  清空（top=-1）、回收空间（这里是自动回收）
#include <bits/stdc++.h>
using namespace std;

#define MaxSize 50
typedef char ElemType;
typedef struct {
    ElemType data[MaxSize];
    int top;  // 指向栈顶元素
} SqStack;
void InitStack(SqStack& S) {
    S.top = -1;
}
bool StackEmpty(SqStack S) {
    return S.top == -1;
}
bool StackFull(SqStack S) {
    return S.top == MaxSize - 1;
}
bool Push(SqStack& S, ElemType elem) {
    if (S.top == MaxSize - 1)  // 栈满
        return false;
    else {
        S.data[++S.top] = elem;
        return true;
    }
}
bool Pop(SqStack& S, ElemType& elem) {
    if (S.top == -1)  // 栈空
        return false;
    else {
        elem = S.data[S.top--];
        return true;
    }
}
bool GetTop(SqStack S, ElemType& elem) {
    if (S.top == -1)  // 栈空
        return false;
    else {
        elem = S.data[S.top];
        return true;
    }
}

int main() {
    SqStack s;
    InitStack(s);
    for (char i = 'a'; i <= 'e'; i++) {
        Push(s, i);
    }
    ElemType c;
    while (Pop(s, c)) {
        cout << c << " ";
    }
    cout << endl;
    cout << StackEmpty(s) << endl;
    return 0;
}

/*----------------------------------------------------------------
// 顺序栈   后进先出(LIFO)  top指向栈顶元素的下一个位置
#include <bits/stdc++.h>
using namespace std;

#define MaxSize 50
typedef char ElemType;
typedef struct {
    ElemType data[MaxSize];
    int top;  // 指向栈顶元素
} SqStack;
void InitStack(SqStack& S) {
    S.top = 0;
}
bool StackEmpty(SqStack S) {
    return S.top == 0;
}
bool StackFull(SqStack S) {
    return S.top == MaxSize;
}
bool Push(SqStack& S, ElemType elem) {
    if (S.top == MaxSize)  // 栈满
        return false;
    else {
        S.data[S.top++] = elem;
        return true;
    }
}
bool Pop(SqStack& S, ElemType& elem) {
    if (S.top == 0)  // 栈空
        return false;
    else {
        elem = S.data[--S.top];
        return true;
    }
}
bool GetTop(SqStack S, ElemType& elem) {
    if (S.top == 0)  // 栈空
        return false;
    else {
        elem = S.data[S.top-1];
        return true;
    }
}

int main() {
    SqStack s;
    InitStack(s);
    for (char i = 'a'; i <= 'e'; i++) {
        Push(s, i);
    }
    ElemType c;
    while (Pop(s, c)) {
        cout << c << " ";
    }
    cout << endl;
    cout << StackEmpty(s) << endl;
    return 0;
}
*/