/*
三元组最短距离
定义三元组(a,b,c)(a、b、c均为正数)的距离D= |a-b|+|b-c|+|c-d|。
给定3个非空整数集合S1、S2和S3，按升序分别存储在3个数组中。
请设计一个尽可能高效的算法，计算并输出所有可能的三元组(a,b,c)(a∈S1,b∈S2,c∈S3)中的最小距离。
例如S={-1,0,9},S2={-25,-10,10,11},S={2,9,17,30,41},则最小
距离为2，相应的三元组为(9,10,9)。
*/

#include <bits/stdc++.h>
using namespace std;

#define Max 0x7fffffff
int abss(int a) {
    return a > 0 ? a : -a;
}
bool minn(int a, int b, int c) {
    if (min(a, min(b, c)) == a)
        return true;
    else
        return false;
}
int findd(int a[], int b[], int c[], int na, int nb, int nc) {
    int i = 0, j = 0, k = 0, ans = Max;
    while (i < na && j < nb && k < nc && ans >= 0) {
        int v = abss(a[i] - b[j]) + abss(b[j] - c[k]) + abss(c[k] - a[i]);  // 取得当前的三元组的距离
        if (v < ans)                                                        // 更新ans
            ans = v;
        if (minn(a[i], b[j], c[k]))  // 更新a，找出最小的，哪个最小，就把它往后移，逼近最大的(a<b<c)
            i++;
        else if (minn(b[j], a[i], c[k]))
            j++;
        else
            k++;
    }
    return ans;
}

int main() {
    int a[3] = {-1, 0, 9}, b[4] = {-25, -10, 10, 11}, c[5] = {2, 9, 17, 30, 41};
    cout << findd(a, b, c, 3, 4, 5) << endl;
    return 0;
}