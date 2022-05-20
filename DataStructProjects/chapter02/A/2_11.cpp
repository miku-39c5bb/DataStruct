#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(s1+s2)
bool Merge(int a[], int s1, int b[], int s2, int c[]) {
    if (a == nullptr || b == nullptr || c == nullptr)
        return false;
    int i = 0, j = 0, k = 0;
    while (i < s1 && j < s2) {
        if (a[i] <= b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }
    while (i < s1) {
        c[k++] = a[i++];
    }
    while (j < s2) {
        c[k++] = b[j++];
    }
    return true;
}
int SearchMid(int a[], int s1, int b[], int s2) {
    int s3 = s1 + s2;
    int* c = new int[s3];
    if (c == nullptr) {
        cerr << "new failed" << endl;
        exit(-1);
    }
    if (!Merge(a, s1, b, s2, c)) {
        cerr << "Merge failed" << endl;
        exit(-1);
    }
    int res = c[(s3 - 1) / 2];  // 注意是(size-1)/2，用数组下标来算
    delete c;
    return res;
}

void test() {
    int s1[] = {11, 13, 15, 17, 19};
    int s2[] = {2, 4, 6, 8, 20};
    int sz1 = sizeof(s1) / sizeof(s1[0]);
    int sz2 = sizeof(s2) / sizeof(s2[0]);
    cout << SearchMid(s1, sz1, s2, sz2) << endl;
}
int main() {
    test();

    return 0;
}