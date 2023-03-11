/*
用递归法将一个整数转化成字符串形式输出
*/
#include<stdio.h>
#include<string.h>
char s[15];
int k = 0;
void solve(int x) {
    if(x == 0) return;
    solve(x / 10);
    s[k++] = (x % 10) + '0';
}
int main() {
    int n;
    scanf("%d", &n);
    solve(n);
    printf("%s\n", s);
    return 0;
}