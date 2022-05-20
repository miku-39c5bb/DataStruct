#include <bits/stdc++.h>
#include "test.h"
using namespace std;

// miku ��׺���ʽת��׺���ʽ�����㣩
/***
 * ��ʼ��һ��ջ�����ڱ�����ʱ������ȷ������˳����������
 * �����Ҵ������Ԫ�أ�ֱ��ĩβ�������������������
 * ��������������ֱ�Ӽ����׺���ʽ��
 * ���������޷���������(��ֱ����ջ��������)�������ε���ջ��������������׺���ʽ��ֱ������������Ϊֹ��
 *      ע�⣺�������������׺���ʽ��
 * ����������������ε���ջ�����ȼ����ڻ���ڵ�ǰ�������������������������׺���ʽ��
 *      ��������������ջ����ֹͣ��֮���ٰѵ�ǰ�������ջ��
 * 
 * ���������������������ַ��󣬽�ջ��ʣ����������ε������������׺���ʽ��
 */

typedef int ElemType;
typedef struct SNode{
    ElemType data;
    struct SNode*next;
}*Stack;
void InitStack(Stack&S){
    S = nullptr;
}
bool StackEmpty(Stack S){
    return S==nullptr;
}
bool Push(Stack &S, ElemType e){
    SNode *s = new SNode;
    if(s==nullptr) { return false; }
    s->data = e;
    s->next = S;
    S = s;
    return true;
}
bool Pop(Stack &S, ElemType &e) {
    if(S== nullptr) { return false; }
    e = S->data;
    SNode* p = S;
    S = S->next;
    delete p;
    return true;
}

void test() {
    Stack S;
    InitStack(S);

    if(StackEmpty(S)) { cout<<"ջ��" << endl; }
    else { cout<<"ջδ��"<<endl; }

    ElemType x;
    cin >> x;
    while(x!=999) {
        Push(S,x);
        cin >> x;
    }
    if(StackEmpty(S)) { cout<<"ջ��" << endl; }
    else { cout<<"ջδ��"<<endl; }

    SNode *p = S;
    while(p!=nullptr) {
        cout << p->data << " ";
        p=p->next;
    }
    cout << endl;
    if(StackEmpty(S)) { cout<<"ջ��" << endl; }
    else { cout<<"ջδ��"<<endl; }

    while(Pop(S,x)) {
        cout << x << " ";
    }
    cout << endl;
    if(StackEmpty(S)) { cout<<"ջ��" << endl; }
    else { cout<<"ջδ��"<<endl; }
}

int main() {
    test();
    return 0;
}