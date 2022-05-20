/*
给定一个含n(n≥1)个整数的数组，
请设计一个在时间上尽可能高效的算法，找出数组中未出现的最小正整数。
例如，数组{-5,3,2,3}中未出现的最小正整数是1；
数组{1,2,3}中未出现的最小正整数是4
*/

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(size+2)
int find_min_positive(int a[], int size) {
    // 由于是找出最小的正整数，可以想出最小的正整数一定在1~size+1之间（左临界1，右临界n+1）
    // 所以bool数组大小要设为size+2的大小，有用的就是1~size+1的位置
    bool map[size + 2];
    memset(map, false, sizeof(bool) * (size + 2));
    // for (auto& n : map) {
    //     // 1~size+1 都设为false，当作1~size+1的正整数都没有出现过
    //     n = false;
    // }
    for (int i = 0; i < size; i++) {
        // 如果a的元素大于0，且小于等于size+1，那么将map对应下标设为true，表示这个正整数出现过
        if (a[i] > 0 && a[i] <= size + 1) {
            map[a[i]] = true;
        }
    }
    int i;
    // 在1~size+1，找到第一个没有出现(false)的正整数
    for (i = 1; i <= size + 1; i++) {
        if (!map[i]) {
            break;
        }
    }
    return i;
}

int find_min_positive2(int a[], int n) {
    int* b;
    // b = (int*)malloc(sizeof(int) * n);
    b = new int[n];
    memset(b, 0, sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        if (a[i] > 0 && a[i] <= n) {
            b[a[i] - 1] = 1;
        }
    }
    int i;
    for (i = 0; i < n; i++)
        if (b[i] == 0)
            break;
    // free(b);
    delete[] b;
    return i + 1;
}

void show(int a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << endl;
    }
}
void test() {
    int a[4] = {-5, 3, 2, 3};
    int b[3] = {1, 2, 3};
    int c[10] = {-21, 4, 1, 2, 43, 32, 4, 5, 2, 6};
    int d[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int e[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << find_min_positive(a, 4) << endl;
    cout << find_min_positive(b, 3) << endl;
    cout << find_min_positive(c, 10) << endl;
    cout << find_min_positive(d, 10) << endl;
    cout << find_min_positive(e, 10) << endl;
    cout << "---------------------------" << endl;
    cout << find_min_positive2(a, 4) << endl;
    cout << find_min_positive2(b, 3) << endl;
    cout << find_min_positive2(c, 10) << endl;
    cout << find_min_positive2(d, 10) << endl;
    cout << find_min_positive2(e, 10) << endl;
}
int main(int argc, char** argv) {
    test();
    return 0;
}