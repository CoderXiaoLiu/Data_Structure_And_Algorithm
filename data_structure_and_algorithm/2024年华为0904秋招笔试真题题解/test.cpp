#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int a[100005], b[100005], n, m;
map<int, int> depa[1005], depb[1005];
int dep1, dep2;
map<int, int> exist;
int cnt[1005];
vector<pair<int, int> >ans;

int bfs(int a[], int n, map<int, int> dep[]) {
    queue<int> q1, q2, q3;
    q1.push(0);
    int depth = 0;
    while (q1.size()) {
        depth++;
        while (q1.size()) {
            int cur = q1.front();
            q1.pop();
            if (cur * 2 <= n && cur * 2 > 0) {
                dep[depth][a[cur * 2]]++;
                q2.push(cur * 2);
            }
            if (cur * 2 + 1 <= n) {
                dep[depth][a[cur * 2 + 1]]++;
                q2.push(cur * 2 + 1);
            }
        }
        q1 = q2;
        q2 = q3;
    }
    return depth;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        exist[a[i]] = 1;
    }
    cin >> m;
    for (int i = 1; i <= m; i++) cin >> b[i];
    dep1 = bfs(a, n, depa);
    dep2 = bfs(b, m, depb);

    for (int i = 1; i <= dep1; i++) {
        for (auto it = depa[i].begin(); it!= depa[i].end(); ++it) {
            int v = it->first;
            int num = it->second;
            cnt[v] += max(0, num - depb[i][v]);
        }
    }

    for (int i = 1; i <= 1000; i++) {
        if (exist[i] == 1) ans.push_back(make_pair(-cnt[i], -i));
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << -ans[i].second;
    }

    return 0;
}