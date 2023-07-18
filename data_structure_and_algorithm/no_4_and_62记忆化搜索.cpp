#include<bits/stdc++.h>
using namespace std;
const int maxn = 12;
int dp[maxn][2];
int digit[10] = {0};
int dfs(int len, int pre, int state, bool ismax) { // ismax为数位上界变量  
    if(len == 0) return 1; // 已经递归到 0 位数，返回
    if(!ismax && dp[len][state] != -1) return dp[len][state]; // 记忆化搜索
    int ans = 0, maxx = ismax ? digit[len] : 9;
    for(int i = 0; i <= maxx; i++) {
        if(i == 4) continue;
        if(pre == 6 && i == 2) continue; // 排除62
        ans += dfs(len - 1, i, i == 6, ismax && i == maxx);
    }
    if(!ismax) dp[len][state] = ans;
    return ans;
}

int solve(int n) {
    fill(digit, digit + 10, 0);
    int len = 0;
    while(n > 0) {
        digit[++len] = n % 10;
        n /= 10;
    }
    return dfs(len, -1, 0, true);
}
int main() {
    int m, n, len;
    while(~scanf("%d%d", &m, &n)) {
        if(m == 0 && n == 0) break;
        memset(dp, -1, sizeof(dp));
        printf("%d\n", solve(n) - solve(m - 1));
    }
    return 0;
}