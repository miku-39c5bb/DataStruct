#include <stdio.h>
#define MaxSize 10  //定义最大长度
typedef struct {
    int data[MaxSize];  //用静态的“数组”存放数据元素
    int length;         //顺序表的当前长度
} SqList;               //顺序表的类型定义

//基本操作 —— 初始化一个顺序表
void InitList(SqList& L) {
    // for (int i = 0; i < MaxSize; i++) {
    //     L.data[i] = 0; //将所有数据元素设置为默认初始值【这个步骤可以省略】
    // }
    L.length = 0;  //顺序表初始长度为0，这一步是必须的
}

//基本操作 —— 在L的位序ⅰ处插入元素e
bool ListInsert(SqList& L, int i, int e) {
    if (i < 1 || i > L.length + 1) {  //判断i的范围是否有效
        return false;
    }
    if (L.length >= MaxSize) {  //当前存储空间已满，不能插入
        return false;
    }

    for (int j = L.length; j >= i; j--) {  //将第i个元素及之后的元素后移
        L.data[j] =
            L.data[j - 1];  //注意位序、数组下标的关系，并从后面的元素依次移动
    }
    L.data[i - 1] = e;  //在位置i处放入e
    L.length++;         //长度加1

    return true;
}

//基本操作 —— 删除表L中第i个位置的元素，并用e返回删除元素的值
bool ListDelete(SqList& L, int i, int& e) {
    if (i < 1 || i > L.length) {  //判断i的范围是否有效
        return false;
    }

    e = L.data[i - 1];                    //将被删除的元素赋值给e
    for (int j = i; j < L.length; j++) {  //将第i个位置后的元素前移
        L.data[j - 1] = L.data[j];
    }
    L.length--;  //线性表长度减1

    return true;
}

//基本操作 —— 按位查找，获取表L中第i个位置的元素的值。
int GetElem(SqList L, int i) {
    return L.data[i - 1];
}

//基本操作 —— 按值查找，在表L中查找具有给定关键字值的元素
int LocateElem(SqList L, int e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i + 1;  //数组下标为i的元素值等于e，返回其位序i+1
        }
    }
    return 0;  //退出循环，说明查找失败
}

int main() {
    SqList L;     //声明一个顺序表
    InitList(L);  //初始化顺序表
    // ···未完待续，后续操作

    // for (int i = 0; i < MaxSize; i++) {
    // //这个操作是违规的，应该限制为L.length，但这样还是不够好，更好的做法是使用基本操作来访问各个数据元素
    //     printf("%d\n", L.data[i]);
    // }

    L.length = 5;
    if (ListInsert(L, 3, 16)) {
        printf("在第3个位置上插入16\n");
    } else {
        printf("位序i不合法，或者线性表当前存储空间已满，插入失败\n");
    }

    printf("16的位置是%d\n", LocateElem(L, 16));

    int e = -1;
    if (ListDelete(L, 3, e)) {
        printf("已删除第3个元素，删除元素值=%d\n", e);
    } else {
        printf("位序i不合法，删除失败\n");
    }

    return 0;
}