/*
TODO
二分查找
*/
#include <bits/stdc++.h>
using namespace std;

#define Max 50
typedef int ElemType;
struct SqList {
    ElemType data[Max];
    int length;
};

// void find_ins(SqList& L, ElemType x) {
//     int low = 0, high = L.length-1, mid;
//     while(low <= high) {
//         mid = (low + high)/2;
//         if(L.data[mid] == x) break;
//         else if(L.data[mid] > x) high = mid-1;
//         else low = mid+1;
//     }
//     if(L.data[mid] == x && mid != L.length-1) {
//         ElemType tmp = L.data[mid];
//         L.data[mid] = L.data[mid+1];
//         L.data[mid+1] = tmp;
//     }
//     if(low > high) {
//         for(int i=L.length-1; i>high; --i) L.data[i+1] = L.data[i];
//         L.data[low]=x;
//     }
// }

// 闭区间
bool find_ins(SqList& L, ElemType x) {
    int left = 0, right = L.length - 1;
    int mid;
    // int flag = false;
    while (left <= right) {
        mid = left + (right - left) / 2;
        ElemType target = L.data[mid];
        if (target > x) {
            right = mid - 1;
        } else if (target < x) {
            left = mid + 1;
        } else {
            // flag = true;
            break;
        }
    }
    if (L.data[mid] == x) {
        if (mid < L.length - 1) {
            ElemType tmp = L.data[mid];
            L.data[mid] = L.data[mid + 1];
            L.data[mid + 1] = tmp;
            return true;
        } else if (mid = L.length - 1) {
            L.data[mid + 1] = L.data[mid];
            L.data[mid] = 0;
            L.length++;
            return true;
        }
    }
    if (left > right) {
        for (int i = L.length - 1; i >= mid; --i) {
            L.data[i + 1] = L.data[i];
        }
        L.data[mid] = x;
        L.length++;
    }
    cout << mid << " " << endl;
    return false;
}

// 左闭右开
// bool find_ins(SqList& L, ElemType x) {
//     int left = 0, right = L.length;
//     int mid;
//     bool flag = false;
//     while (left < right) {
//         mid = left + (right - left) / 2;
//         ElemType target = L.data[mid];
//         if (target > x) {
//             right = mid;
//         } else if (target < x) {
//             left = mid + 1;
//         } else {
//             flag = true;
//             break;
//         }
//     }
//     if (flag) {
//         if (mid < L.length - 1) {
//             ElemType tmp = L.data[mid];
//             L.data[mid] = L.data[mid + 1];
//             L.data[mid + 1] = tmp;
//             return true;
//         } else if (mid = L.length - 1) {
//             L.length++;
//             L.data[mid + 1] = L.data[mid];
//             L.data[mid] = 0;
//             return true;
//         }
//     } else {
//         for (int i = L.length - 1; i >= mid + 1; --i) {
//             L.data[i + 1] = L.data[i];
//         }
//         L.data[mid + 1] = x;
//         L.length++;
//     }
//     return false;
// }

void prin(const SqList& L) {
    for (int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}
void test() {
    SqList L = {{2, 3, 4, 5, 6, 8, 10, 13, 16, 20, 25, 26, 30}, 13};
    prin(L);
    if (find_ins(L, 22)) {
        prin(L);
    }
    prin(L);
}

int main() {
    test();

    return 0;
}