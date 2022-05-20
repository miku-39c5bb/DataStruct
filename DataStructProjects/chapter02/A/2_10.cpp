#include <bits/stdc++.h>
using namespace std;

// TODO
// Time Complexity: O(n)
// Sapce Complexity: O(1)
// void reverse(int (&a)[], int left, int right) {
void reverse(int a[], int left, int right) {
    if (left >= right)
        return;
    while (left < right) {
        int t = a[left];
        a[left] = a[right];
        a[right] = t;
        left++, right--;
    }
}
// void change(int (&a)[], int n, int p) {
void change(int a[], int n, int p) {
    reverse(a, 0, n - 1);
    reverse(a, 0, n - p - 1);
    reverse(a, n - p, n - 1);
}

void prin(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}
void test() {
    int a[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 13, 16};
    prin(a, 12);
    change(a, 12, 5);
    prin(a, 12);
}
int main() {
    test();

    return 0;
}