/*
输入2个正整数 m 和 n （1<=m,n<=1000)，输出m和n之间所有满足各位数字的立方和等于它本身的数。
*/
#include<stdio.h>
int cal(int x) {
    int ans = 0, k = 0;
    while (x > 0) {
        k = x % 10;
        ans += (k * k *k);
        x /= 10;
    }
    return ans;
}
int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    int i;
    for(i = m; i <= n; i++) {
        if(cal(i) == i) printf("%d ", i);
    }

    return 0;
}