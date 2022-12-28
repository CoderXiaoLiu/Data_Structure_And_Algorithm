#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
const int MaxSize = 100; // 栈的最大容量
typedef struct{
    int data[MaxSize];
    int top;
}Stack;
void InitStack(Stack &S) { //初始化栈
    S.top = -1;
}
bool Push(Stack &S, int x) { // 入栈
    if(S.top == MaxSize - 1) return false; // 栈满，报错
    S.data[++S.top] = x;
    return true;
}
bool Pop(Stack &S, int &x) { // 出栈
    if(S.top == -1) return false; // 栈为空，报错
    x = S.data[S.top--];
    return true;
}
bool Empty(Stack S) { // 判栈空
    return S.top == -1;
}
int main() {
    int n;
    scanf("%d", &n);
    int x;
    Stack S;
    InitStack(S);
    while(n != 0) {
        Push(S, n % 8);
        n /= 8;
    }
    while(!Empty(S)) {
        Pop(S, x);
        printf("%d",x);
    }
    return 0;
}