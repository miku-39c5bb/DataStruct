typedef int ElemType;
typedef struct Linknode {  // 未带头结点
    ElemType data;
    struct Linknode* next;
} * LiStack;

void InitStack(LiStack& s) {
    if (s != NULL)
        free(s);
    s = NULL;
}
bool StackEmpty(LiStack s) {
    return s == NULL;
}
bool StackFull(LiStack s) {
    struct Linknode* p = (struct Linknode*)malloc(sizeof(struct Linknode));
    if (p == NULL)
        return true;
    else {
        free(p);
        return false;
    }
}
bool Push(LiStack& s, ElemType e) {
    struct Linknode* p = (struct Linknode*)malloc(sizeof(struct Linknode));
    if (p == NULL)
        return false;
    p->data = e;
    p->next = s;
    s = p;
    return true;
}
bool Pop(LiStack& s, ElemType& e) {
    if (s == NULL)
        return false;
    struct Linknode* r;
    r = s->next;
    e = s->data;
    free(s);
    s = r;
    return true;
}
bool GetTop(LiStack s, ElemType& e) {
    if (s == NULL)
        return false;
    e = s->data;
    return true;
}