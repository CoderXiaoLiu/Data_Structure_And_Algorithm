#include<bits/stdc++.h>
using namespace std;
const int MaxSize = 100; //栈的大小
typedef struct { // 顺序栈
    char data[MaxSize];
    int top;
}Stack;
void InitStack(Stack &S) { // 栈的初始化
    S.top = -1;
}
bool Push(Stack &S, char x) { // 进栈
    if(S.top == MaxSize - 1) return false; // 栈满，报错
    S.data[++S.top] = x;
    return true;
}
bool Pop(Stack &S, char &x) {
    if(S.top == -1) return false; // 栈空，报错
    x = S.data[S.top--];
    return true;
}
bool Empty(Stack S) { // 判栈空
    if(S.top == -1) return true;
    else return false;
}
//链队列
typedef struct LinkNode{
    int data;
    struct LinkNode *next;
} LinkNode;
typedef struct{
    LinkNode *front, *rear;
}LinkQueue;
void InitQueue(LinkQueue &Q) { // 初始化链队
    Q.front = Q.rear = (LinkNode *) malloc (sizeof(LinkNode));
    Q.front -> next = NULL;
}
void EnQueue(LinkQueue &Q, char x) { // 入队
    LinkNode *s;
    s = (LinkNode *) malloc (sizeof(LinkNode));
    s -> data = x;
    s -> next = NULL;
    Q.rear -> next = s;
    Q.rear = s;
}
bool DeQueue(LinkQueue &Q, char &x) { // 出队
    if(Q.front == Q.rear) return false; // 队列为空，报错
    LinkNode *p = Q.front -> next;
    x = p -> data;
    Q.front -> next = p -> next;
    if(Q.rear == p) { // 若原队列中只有一个结点，删除后变为空
        Q.rear = Q.front;
    }
    free(p);
    return true;
}
bool Empty(LinkQueue Q) { // 判队空
    if(Q.front == Q.rear) return true;
    else return false;
}
int main() {
    char str[100];
    scanf("%s", str);
    Stack S;
    LinkQueue Q;
    InitStack(S);
    InitQueue(Q);
    char a, b;
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        Push(S, str[i]);
        EnQueue(Q, str[i]);
    }
    bool flag = true;
    while(!Empty(S) && !Empty(Q)) {
        Pop(S, a);
        DeQueue(Q, b);
        if(a != b) { // a 不等于 b 则不是回文
            flag = false;
            break;
        }
    }
    if(flag) puts("yes");
    else puts("no");
    return 0;
}
/*
测试样例一：
CSUSTSUSC
测试样例二：
SHUSIISHKSJHS
*/