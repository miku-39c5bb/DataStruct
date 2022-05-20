#include <stdio.h>
#include <stdlib.h>
#define InitSize 10  //默认的最大长度

typedef int ElemType;
typedef struct {
    ElemType* data;  //指示动态分配数组的指针
    int MaxSize;     //顺序表的最大容量
    int length;      //顺序表的当前长度
} SeqList;

void InitList(SeqList* L) {
    //用malloc函数申请一片连续的存储空间
    L->data = (ElemType*)malloc(InitSize * sizeof(ElemType));
    L->MaxSize = InitSize;
    L->length = 0;
}

//增加动态数组的长度
// 注：realloc函数也可实现，但建议初学者使用malloc和free，更能理解背后过程
void IncreaseSize(SeqList* L, int len) {
    ElemType* p = L->data;
    L->data = (ElemType*)malloc((L->MaxSize + len) * sizeof(ElemType));
    for (int i = 0; i < L->length; i++) {
        L->data[i] = p[i];  //将数据复制到新区域【时间开销大】
    }
    L->MaxSize += len;  //顺序表最大长度增加len
    free(p);            //释放原来的内存空间
}

int main() {
    SeqList L;
    InitList(&L);
    IncreaseSize(&L, 16);

    return 0;
}