#include <stdbool.h>
#include <stdio.h>
#define MaxSize 10  //定义最大长度
typedef struct {
    int data[MaxSize];  //用静态的“数组”存放数据元素
    int length;         //顺序表的当前长度
} SqList;               //顺序表的类型定义

//基本操作一初始化一个顺序表
void InitList(SqList* L) {
    // for (int i = 0; i < MaxSize; i++) {
    //     L->data[i] = 0; //将所有数据元素设置为默认初始值【这个步骤可以省略】
    // }
    L->length = 0;  //顺序表初始长度为0，这一步是必须的
}

bool ListInsert(SqList* L, int i, int e) {
    if (i < 1 || i > L->length + 1) {
        return false;
    }
    if (L->length >= MaxSize) {
        return false;
    }

    for (int j = L->length; j >= i; j--) {
        L->data[j] = L->data[j - 1];
    }
    L->data[i - 1] = e;
    L->length++;

    return true;
}

bool ListDelete(SqList* L, int i, int* e) {
    if (i < 1 || i > L->length) {
        return false;
    }

    *e = L->data[i - 1];
    for (int j = i; j < L->length; j++) {
        L->data[j - 1] = L->data[j];
    }
    L->length--;

    return true;
}

int main() {
    SqList L;      //声明一个顺序表
    InitList(&L);  //初始化顺序表
    // ···未完待续，后续操作
    // for (int i = 0; i < MaxSize; i++) {
    // //这个操作是违规的，应该限制为L->length，但这样还是不够好，更好的做法是使用基本操作来访问各个数据元素
    //     printf("%d\n", L.data[i]);
    // }

    int e = -1;
    L.length = 5;
    if (ListInsert(&L, 3, 16)) {
        printf("在第3个位置上插入16\n");
    } else {
        printf("位序i不合法，或者线性表当前存储空间已满，插入失败\n");
    }

    if (ListDelete(&L, 3, &e)) {
        printf("已删除第3个元素，删除元素值=%d\n", e);
    } else {
        printf("位序i不合法，删除失败\n");
    }

    return 0;
}