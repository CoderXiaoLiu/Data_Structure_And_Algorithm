/*
http://acm.hdu.edu.cn/showproblem.php?pid=1520
树形DP入门题
dp[i][0] 表示不选当前节点的最优解，dp[i][1] 表示选择当前节点的最优解
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 6010;
vector<int>tree[maxn];
int dp[maxn][2], father[maxn], value[maxn];
void dfs(int u) {
    dp[u][0] = 0; // 不参加party
    dp[u][1] = value[u]; // 参加party
    for(int i = 0; i < tree[u].size(); i++) {
        int son = tree[u][i];
        dfs(son); // 深搜子结点
        dp[u][0] += max(dp[son][0], dp[son][1]); // 父结点不选，子结点可选可不选
        dp[u][1] += dp[son][0]; // 父结点选择，子结点不能选
    }
}
int main() {
    int n, a, b;
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; i++) {
            scanf("%d", &value[i]);
            tree[i].clear();
            father[i] = -1;
        }
        memset(dp, 0, sizeof(dp));
        while(true) { // 建树
            scanf("%d%d", &a, &b);
            if(a == 0 && b == 0) break;
            tree[b].push_back(a);
            father[a] = b; // 父子关系，表示a的父亲是b
        }
        for(int i = 1; i <= n; i++) {
            if(father[i] == -1) { // 寻找父结点，从父结点开始深搜
                dfs(i);
                printf("%d\n", max(dp[i][0], dp[i][1]));
                break;
            }
        }
    }
    return 0;
}