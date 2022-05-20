#include <bits/stdc++.h>
using namespace std;

// 我写的-----------------------------------------------
bool isEffective(const char* c, int size) {
    int stack = 0;
    for (int i = 0; i < size; ++i) {
        if (c[i] == 'I')
            ++stack;
        else
            --stack;
        if (stack < 0)
            return false;
    }
    if (stack != 0)
        return false;
    return true;
}
// -----------------------------------------------

// 书上的答案-----------------------------------------------
bool Judge(const char A[]) {
    int i = 0;
    int j = 0, k = 0;
    while (A[i] != '\0') {
        switch (A[i]) {
            case 'I':
                j++;
                break;
            case 'O':
                k++;
                if (k > j) {
                    cout << "序列非法" << endl;
                    exit(0);
                }
                break;
        }
        i++;
    }
    if (j != k) {
        cout << "序列非法" << endl;
        return false;
    } else {
        cout << "序列合法" << endl;
        return true;
    }
}
// -----------------------------------------------

int main() {
    string s;
    cin >> s;
    const char* c = s.c_str();
    if (isEffective(c, 8))
        cout << "操作有效" << endl;
    else
        cout << "操作无效" << endl;
    Judge(c);
    return 0;
}
