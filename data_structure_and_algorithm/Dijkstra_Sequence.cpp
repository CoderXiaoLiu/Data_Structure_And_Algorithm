#include<bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const int maxn = 1e3+5;
int G[maxn][maxn];
int d[maxn],n,m;
int a[maxn];
bool dijistra(int x) {
	fill(d, d + maxn, INF);
    bool visited[maxn] = {false};
	d[x] = 0;
	for(int i = 1; i <= n; i++) {
		int u = -1, MIN = INF;
		for(int j = 1; j <= n; j++) {
			if(visited[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
        if(d[a[i]] == MIN) u = a[i];
		else return false;
		visited[u] = true;
		for(int v = 1; v <= n; v++) {
			if(visited[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]) 
				d[v] = d[u] + G[u][v];
		}
	}
    return true;
} 
int main() {
	fill(G[0], G[0] + maxn * maxn, INF);
	scanf("%d%d", &n, &m);
	while(m--) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		G[v][u] = G[u][v] = min(G[u][v], w);
	}
    int q;
    scanf("%d", &q);
    while(q--) {
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        if(dijistra(a[1])) puts("Yes");
        else puts("No");
    }
	return 0;
}
