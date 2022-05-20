// 顺序栈   后进先出(LIFO)  top指向栈顶元素
// 缺点：顺序栈的大小不可改变
// 销？ ——  清空（top=-1）、回收空间（这里是自动回收）
#define MaxSize 3
typedef int ElemType;
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
bool StackOverflow(SqStack S) {
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
