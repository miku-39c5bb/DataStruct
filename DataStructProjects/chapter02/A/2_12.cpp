/*
找出主元素
*/

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
int FindMainElem1(int arr[], int size) {
    int c = arr[0], k = 1;
    for (int i = 1; i < size; i++) {  // 第一次扫描，找出可能的主元素c
        if (c == arr[i])
            ++k;
        else {
            if (k > 0)
                --k;
            else {
                c = arr[i];
                k = 1;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < size; ++i)  // 第二次扫描，判断c是否为真正的主元素
        if (c == arr[i])
            ++count;
    if (count > size / 2)
        return count;
    return -1;
}

// 键值对（HashMap）
int FindMainElem2(int arr[], int size) {
    // map<int, int> mp;
    // for (int i = 0; i < size; ++i) {
    //     if (++mp[arr[i]] > size / 2) {
    //         return arr[i];
    //     }
    // }
    // return -1;

    map<int, int> mp;
    for (int i = 0; i < size; ++i)
        mp[arr[i]]++;
    int c, count = 0;
    for (auto v : mp) {
        if (v.second > count) {
            c = v.first;
            count = v.second;
        }
    }
    if (count > size / 2)
        return c;
    return -1;
}

// 用数组代替HashMap（因为0 <= ai < n，0 <= i < n，所以才可以这么用）
// Time Complexity: O(n)
// Space Complexity: O(1)
int FindMainElem3(int arr[], int size) {
    int hash[size] = {0};
    for (int i = 0; i < size; i++) {
        if (++hash[arr[i]] > size / 2) {
            return arr[i];
        }
    }
    return -1;
}

void test() {
    int a[8] = {0, 5, 5, 3, 5, 7, 5, 5};
    int b[8] = {0, 5, 5, 3, 5, 1, 5, 7};
    int c[9] = {0, 5, 5, 3, 5, 1, 5, 7, 6};
    int d[9] = {0, 5, 5, 3, 5, 1, 5, 7, 5};
    cout << "--------------------------------" << endl;
    cout << FindMainElem1(a, 8) << endl;
    cout << FindMainElem1(b, 8) << endl;
    cout << FindMainElem1(c, 9) << endl;
    cout << FindMainElem1(d, 9) << endl;
    cout << "--------------------------------" << endl;
    cout << FindMainElem2(a, 8) << endl;
    cout << FindMainElem2(b, 8) << endl;
    cout << FindMainElem2(c, 9) << endl;
    cout << FindMainElem2(d, 9) << endl;
    cout << "--------------------------------" << endl;
    cout << FindMainElem3(a, 8) << endl;
    cout << FindMainElem3(b, 8) << endl;
    cout << FindMainElem3(c, 9) << endl;
    cout << FindMainElem3(d, 9) << endl;
}
int main(int argc, char** argv) {
    test();

    return 0;
}