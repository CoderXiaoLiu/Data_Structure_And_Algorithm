/*
输入一个长度为10的数组，输出连续整数之和的最大值。例如：
输入：2, -3, 5, -3, 2, 4, -6, 3, 1, 1
输出：8 (因为5 + (-3) + 2 + 4 = 8)
*/
#include<stdio.h>
int max(int a, int b){
    return a > b ? a : b;
}
int main() {
    int n;
    scanf("%d", &n);
    int a[n], i;
    for(i = 0; i < n; i++) scanf("%d", &a[i]);
    int ans = 0, cnt = a[0];
    for(i = 1; i < n; i++) {
        cnt = max(cnt + a[i], a[i]);
        ans = max(ans, cnt);
    }
    printf("%d", ans);
    return 0;
}