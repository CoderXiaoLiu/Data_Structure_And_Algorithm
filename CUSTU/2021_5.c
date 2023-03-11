/*
写程序，输入一个只含有+1和-1的序列，输出和最大的子序列的和。
例如：序列+1 -1 -1 +1 +1 -1 +1 +1 -1 -1 +1的最大子序列之和为3（最大子序列为+1 +1 -1 +1 +1） 
*/
#include<stdio.h>
int max(int a, int b) {
    return a > b ? a : b;
}
int main() {
    int n, i;
    scanf("%d", &n);
    int a[n], dp[n];
    for(i = 0; i < n; i++) scanf("%d", &a[i]); // 读入序列
    dp[0] = a[0];
    int ans = a[0];
    for(i = 1; i < n; i++) {
        dp[i] = max(dp[i-1] + a[i], a[i]);
        ans = max(ans, dp[i]);
    }
    printf("%d", ans);
    return 0;
}