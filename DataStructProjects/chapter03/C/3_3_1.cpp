#include <bits/stdc++.h>
#include "./include/Stack.h"
using namespace std;

// 我写的---------------------------------------
bool bracketCheck(const char* str) {
    Stack S;
    InitStack(S);
    for (size_t i = 0; str[i] != '\0'; ++i) {
        if ('(' == str[i] || '[' == str[i] || '{' == str[i]) {
            Push(S, str[i]);
        } else {
            if (StackEmpty(S)) {
                return false;
            } else {
                char c;
                Pop(S, c);
                if ('(' == c && ')' != str[i]) {
                    return false;
                } else if ('[' == c && ']' != str[i]) {
                    return false;
                } else if ('{' == c && '}' != str[i]) {
                    return false;
                }
            }
        }
    }
    if (!StackEmpty(S)) {
        return false;
    } else {
        return true;
    }
}

void test() {
    string s;
    cin >> s;
    const char* str = s.c_str();
    if (bracketCheck(str)) {
        cout << "括号匹配成功" << endl;
    } else {
        cout << "括号匹配不成功" << endl;
    }
}
// ---------------------------------------

// 书上的答案---------------------------------------
// ---------------------------------------


int main() {
    test();
    return 0;
}