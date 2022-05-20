#include <bits/stdc++.h>
using namespace std;

#define MaxSize 50
typedef char ElemType;
typedef struct {
    ElemType data[MaxSize];
    int top;
} Stack;
void InitStack(Stack& S) {
    S.top = -1;
}
bool StackEmpty(Stack S) {
    return S.top == -1;
}
bool StackOverflow(Stack S) {
    return S.top == MaxSize - 1;
}
bool Push(Stack& S, ElemType e) {
    if (S.top == MaxSize - 1)
        return false;
    S.data[++S.top] = e;
    return true;
}
bool Pop(Stack& S, ElemType& e) {
    if (S.top == -1)
        return false;
    e = S.data[S.top--];
    return true;
}

bool bracketCheck(char str[], int length) {
    Stack S;
    InitStack(S);
    for (std::size_t i = 0; i < length; ++i) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            Push(S, str[i]);
        } else {
            if (StackEmpty(S)) {  // 右括号进行匹配，但是栈空（没有左括号了）
                return false;
            } else {
                ElemType topElem;
                Pop(S, topElem);
                if (topElem == '(' && str[i] != ')') {  // 左括号和右括号不匹配
                    return false;
                } else if (topElem == '[' && str[i] != ']') {
                    return false;
                } else if (topElem == '{' && str[i] != '}') {
                    return false;
                }
            }
        }
    }
    if (!StackEmpty(S)) {  // 括号都扫描完了，但是栈中还有元素（有左括号没有匹配）
        return false;
    }
    return true;
}

bool _bracketCheck(char str[], int length) {
    Stack S;
    InitStack(S);
    for (size_t i = 0; i < length; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            Push(S, str[i]);
        else {
            if (StackEmpty(S))
                return false;
            else {
                ElemType topElem;
                Pop(S, topElem);
                if (topElem == '(' && str[i] != ')')
                    return false;
                else if (topElem == '[' && str[i] != ']')
                    return false;
                else if (topElem == '{' && str[i] != '}')
                    return false;
            }
        }
    }
    return StackEmpty(S);
}

void test() {
    string s;
    cin >> s;
    char* str = const_cast<char*>(s.c_str());
    if (_bracketCheck(str, s.size())) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
int main() {
    test();
    return 0;
}