#include <bits/stdc++.h>
#include "./include/Stack.h"
using namespace std;

// 我写的---------------------------------------
void sort(char*& str) {
    Stack S;
    InitStack(S);
    size_t len = strlen(str);
    char* ans = new char[len + 1];
    size_t j = 0;
    for (size_t i = 0; i < len; i++) {
        if (str[i] == 'H' || str[i] == 'h') {
            Push(S, str[i]);
        } else {
            ans[j++] = str[i];
        }
    }
    while (!StackEmpty(S)) {
        char c;
        Pop(S, c);
        ans[j++] = c;
    }
    ans[j] = '\0';
    str = ans;
}

void test() {
    string s;
    cin >> s;
    char* str = const_cast<char*>(s.c_str());
    sort(str);
    cout << str << endl;
    delete[] str;
}
// ---------------------------------------

// 书上的答案---------------------------------------
// ---------------------------------------

int main() {
    test();
    return 0;
}