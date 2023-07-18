/*
http://acm.hdu.edu.cn/showproblem.php?pid=2089
递推
dp[i][j] = for j in range(0, i) dp[i][j] += dp[j][k] (j!=4 && (j!=6 && k != 2))
*/
#include<bits/stdc++.h>
using namespace std;
const int len = 10;
long long dp[10][10] = {0}; // dp[i][j] 表示第一位为 j 的 i 位数的符合条件的数字数量
int digit[12]; // digit[i] 表示存第 i 位数
void init() {
    dp[0][0] = 1;
    for(int i = 1; i <= len; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = 0; k < 10; k++) {
                // if(j == 4) continue; // 排除数字 4
                // else if(j == 6 && k == 2) continue; // 排除62
                if(j != 4 && (j != 6 || k != 2))
                    dp[i][j] += dp[i - 1][k];
            }
        }
    }
}
int solve(int n) { // 计算[0, n)区间满足条件的数字个数
    memset(digit, 0, sizeof(digit));
    int ans = 0, len = 0;
    while(n > 0) {
        digit[++len] = n % 10;
        n /= 10;
    }
    for(int i = len; i > 0; i--) { // 从 n 的高位到低位
        for(int j = 0; j < digit[i]; j++) {
            if(j != 4 && !(digit[i+1]==6 && j==2))
                ans += dp[i][j];
        }
        if(digit[i] == 4) break; // 第 i 位是4，则第i位后面以4开头后面的数不要了
        if(digit[i + 1] == 6 && digit[i] == 2) break;
    }
    return ans;
}
int main() {
    init();
    int n, m;
    while(~scanf("%d%d", &n, &m)) {
        if(n == 0 && m == 0) break;
        printf("%d\n", solve(m + 1) - solve(n));
    }

    return 0;
}