#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

int a[maxn][3][2];
vector <int> graph[maxn];

void dfs(int u, int father) {
    for(auto v : graph[u]) {
        if(v == father) continue;
        dfs(v, u);
    }
    if(u != 1) {
        a[father][0][0] += a[u][0][0];
        a[father][1][0] += a[u][1][0];
        a[father][2][0] += a[u][2][0];
    }
}

void dfs2(int u, int father) {
    if(u != 1) {
        a[u][0][1] = a[1][0][0] - a[u][0][0];
        a[u][1][1] = a[1][1][0] - a[u][1][0];
        a[u][2][1] = a[1][2][0] - a[u][2][0];
    }
    for(auto v : graph[u]) {
        if(v == father) continue;
        dfs2(v, u);
    }
}

void solve() {
    int n, u, v;
    scanf("%d", &n);
    string s;
    cin >> s;
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= n; ++i) {
        if(s[i - 1] == 'r') a[i][0][0] = 1;
        if(s[i - 1] == 'g') a[i][1][0] = 1;
        if(s[i - 1] == 'b') a[i][2][0] = 1;
    }
    for(int i = 0; i < n - 1; ++i) {
        scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, 0);
    // for(int i = 1; i <= n; i++) {
    //     cout << a[i][0][0] << " " << a[i][1][0] << " " << a[i][2][0] << endl;
    // }
    dfs2(1, 0);
    int ans = 0;
    for(int i = 2; i <= n; i++) {
        if(a[i][0][0] && a[i][1][0] && a[i][2][0] && a[i][0][1] && a[i][1][1] && a[i][2][1])
            ans++;
    }
    printf("%d\n", ans);
}

int main() {
    solve();

    return 0;
}

/*
34
rrgrrgbbgrbgbgbgbrggrrbgbgrbgggbrr
14 15
11 7
13 4
2 9
8 7
1 3
16 5
11 3
6 2
4 12
1 16
2 14
2 4
1 2
15 10
16 17
17 18
18 19
19 20
20 21
21 22
22 23
23 24
24 25
25 26
26 27
27 28
28 29
29 30
30 31
31 32
32 33
33 34
*/