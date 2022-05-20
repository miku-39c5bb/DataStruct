#include <bits/stdc++.h>
#include "test.h"
using namespace std;

// miku 中缀表达式转后缀表达式（机算）
/***
 * 初始化一个栈，用于保存暂时还不能确定运算顺序的运算符。
 * 从左到右处理各个元素，直到末尾。可能遇到三种情况：
 * ①遇到操作数。直接加入后缀表达式。
 * ②遇到界限符。遇到“(”直接入栈；遇到“)”则依次弹出栈内运算符并加入后缀表达式，直到弹出“（”为止。
 *      注意：“（”不加入后缀表达式。
 * ③遇到运算符。依次弹出栈中优先级高于或等于当前运算符的所有运算符，并加入后缀表达式，
 *      若碰到“（”或栈空则停止。之后再把当前运算符入栈。
 * 
 * 按上述方法处理完所有字符后，将栈中剩余运算符依次弹出，并加入后缀表达式。
 */

typedef int ElemType;
typedef struct SNode{
    ElemType data;
    struct SNode*next;
}*Stack;
void InitStack(Stack&S){
    S = nullptr;
}
bool StackEmpty(Stack S){
    return S==nullptr;
}
bool Push(Stack &S, ElemType e){
    SNode *s = new SNode;
    if(s==nullptr) { return false; }
    s->data = e;
    s->next = S;
    S = s;
    return true;
}
bool Pop(Stack &S, ElemType &e) {
    if(S== nullptr) { return false; }
    e = S->data;
    SNode* p = S;
    S = S->next;
    delete p;
    return true;
}

void test() {
    Stack S;
    InitStack(S);

    if(StackEmpty(S)) { cout<<"栈空" << endl; }
    else { cout<<"栈未空"<<endl; }

    ElemType x;
    cin >> x;
    while(x!=999) {
        Push(S,x);
        cin >> x;
    }
    if(StackEmpty(S)) { cout<<"栈空" << endl; }
    else { cout<<"栈未空"<<endl; }

    SNode *p = S;
    while(p!=nullptr) {
        cout << p->data << " ";
        p=p->next;
    }
    cout << endl;
    if(StackEmpty(S)) { cout<<"栈空" << endl; }
    else { cout<<"栈未空"<<endl; }

    while(Pop(S,x)) {
        cout << x << " ";
    }
    cout << endl;
    if(StackEmpty(S)) { cout<<"栈空" << endl; }
    else { cout<<"栈未空"<<endl; }
}

int main() {
    test();
    return 0;
}