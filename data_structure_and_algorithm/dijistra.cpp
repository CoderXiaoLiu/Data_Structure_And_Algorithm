#include<bits/stdc++.h>
using namespace std;
const int maxn = 1001;
const int INF = INT_MAX;
int n, m, G[maxn][maxn];
int d[maxn];
bool visited[maxn] = {false};
void dijistra(int s) {
    fill(d, d + maxn, INF);
    d[s] = 0;
    for(int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for(int j = 1; j <= n; j++) {
            if(!visited[j] && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;
        visited[u] = true;
        for(int v = 1; v <= n; v++) {
            if(!visited[v] && G[u][v] != INF && d[u] + G[u][v] < d[v])
                d[v] = d[u] + G[u][v];
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i != j) G[i][j] = INF;
            else G[i][j] = 0;
        }
    }
    while(m--) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u][v] = G[v][u] = min(G[u][v], w);
    }
    int t;
    scanf("%d", &t);
    dijistra(1);
    while(t--) {
        int x;
        scanf("%d", &x);
        printf("%d\n", d[x]);
    }
    return 0;
}