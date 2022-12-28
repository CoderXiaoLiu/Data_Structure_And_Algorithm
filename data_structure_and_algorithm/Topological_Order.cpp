#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
vector<int>a[maxn];
int ind[maxn] = {0}, indegree[maxn] = {0}, b[maxn] = {0};
int main() {
    int n, t;
    scanf("%d%d", &n, &t);
    while (t--)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u].push_back(v);
        ind[v]++;
    }
    // for(int i = 1; i <= n; i++) cout << ind[i] << " ";
    // cout << endl;
    int q;
    scanf("%d", &q);
    vector<int>ans;
    for(int k = 0; k < q; k++)
    {
        copy(ind, ind + n + 1, indegree);
        // for(int i = 1; i <= n; i++) cout << indegree[i] << " ";
        // cout << endl;
        for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
        for(int i = 1; i <= n; i++) {
            if(indegree[b[i]] == 0) {
                for(auto &j: a[b[i]]) indegree[j]--;
            } else {
                ans.push_back(k);
                break;
            }
        }
    }
    printf("%d", ans[0]);
    for(int i = 1; i < ans.size(); i++) printf(" %d", ans[i]);
    return 0;
}