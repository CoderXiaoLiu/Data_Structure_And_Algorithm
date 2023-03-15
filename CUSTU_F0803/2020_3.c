/*
编写程序计算 1!+2!+3!+.....+n!的值，其中n是键盘读入
*/
#include<stdio.h>
int cal(int n) {
    int sum = 1, i;
    for(i = 2; i <= n; i++) {
        sum *= i;
    }
    return sum;
}
int main() {
    int n;
    scanf("%d", &n);
    int ans = 1, i;
    for(i = 2; i <= n; i++) {
        ans += cal(i);
    }
    printf("%d", ans);
    return 0;
}