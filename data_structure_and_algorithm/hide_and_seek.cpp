/*
可以将每个区间[i,j]看作一个点，然后连接两个点需要的边的边权为区间中Cij的最小值，
因为只要知道奇偶性，最小值已经足够了。
然后求出这个图的最小生成树即可，最小生成树的权值和就是最少需要使用的纪念币个数。
因为通过这种方式得到的最小生成树保证了所有房间的人数奇偶性都可以通过询问得到。
*/
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int maxn = (2010 * 2000) / 2;
int n;
struct edge {
    int u, v; // 边的两个端点编号
    int cost; // 边权
} E[maxn];
bool cmp(edge &a, edge &b) {
    return a.cost < b.cost;
}

// 并查集部分
int father[maxn];
int findFather(int x) {
    int a = x;
    while(x != father[x]) x = father[x];
    // 路径压缩
    while(a != father[a]) {
        int z =  a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

LL kruskal(int n, int m) { // n为顶点数，m为图的边数
    LL ans = 0, Num_Edge = 0;
    for(int i = 0; i <= n; i++) father[i] = i;
    sort(E, E + m, cmp);
    for(int i = 0; i < m; i++) {
        int faU = findFather(E[i].u);
        int faV = findFather(E[i].v);
        if(faU != faV) {
            father[faU] = faV;
            ans += E[i].cost;
            Num_Edge++; // 当前生成树的边数加一
            if(Num_Edge == n) break; 
        }
    }
    return ans;
}
int main() {
    scanf("%d", &n);
    int m = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            E[m].u = i - 1, E[m].v = j;
            scanf("%d", &E[m].cost);
            m++;
        }
    }
    printf("%lld", kruskal(n, m));
    return 0;
}
/*
5
1 2 3 4 5
4 3 2 1
3 4 5
2 1
5
*/