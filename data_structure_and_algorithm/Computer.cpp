/*
树形DP例题
http://acm.hdu.edu.cn/showproblem.php?pid=2196
dp[i][0] 表示结点i到子树的最长距离, dp[i][1]表示结点到子树的次长距离
dp[i][2] 表示结点i往上走的最长距离
*/
#include<bits/stdc++.h>
using namespace std;
struct Node {
    int id; // 子树结点编号
    int cost;
};
const int maxn = 10010;
int dp[maxn][3], n;
vector <Node> tree[maxn];
void init() { // 初始化和建树
    for(int i = 1; i <= n; i++) tree[i].clear();
    memset(dp, 0, sizeof(dp));
    int x, y;
    for(int i = 2; i <= n; i++) {
        scanf("%d%d", &x, &y);
        Node tmp;
        tmp.id = i;
        tmp.cost = y;
        tree[x].push_back(tmp);
    }
}
void dfs1(int father) { // 搜索以结点father为起点到子树的最长距离和次长距离
    int one = 0, two = 0; // one 记录father往下走的最长距离，two记录次长距离
    for(int i = 0; i < tree[father].size(); i++) { // 先处理子结点再处理父结点
        Node child = tree[father][i];
        dfs1(child.id); // 递归子结点，直到最底层
        int temp = child.cost + dp[child.id][0];
        if(temp >= one) {
            two = one;
            one = temp;
        }
        if(temp < one && temp > two) two = temp;
    }
    dp[father][0] = one; // 得到以father为起点的子树的最长距离
    dp[father][1] = two; // 得到以father为起点的子树的次长距离
}
void dfs2(int father) { // 先处理父结点再处理子结点
    for(int i = 0; i < tree[father].size(); i++) {
        Node child = tree[father][i];
        if(child.cost + dp[child.id][0] == dp[father][0]) // child在最长距离的子树上
            dp[child.id][2] = max(dp[father][1], dp[father][2]) + child.cost;
        else dp[child.id][2] = max(dp[father][0], dp[father][2]) + child.cost; //否则
        dfs2(child.id);
    }
}
int main() {
    while(~scanf("%d", &n)) {
        init();
        dfs1(1);
        dp[1][2] = 0;
        dfs2(1);
        for(int i = 1; i <= n; i++) {
            printf("%d\n", max(dp[i][0], dp[i][2]));
        }
    }
    return 0;
}