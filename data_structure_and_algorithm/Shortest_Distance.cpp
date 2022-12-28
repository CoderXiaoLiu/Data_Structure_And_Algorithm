#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    int sum = 0, d[n+1] = {0};
    for(int i = 2; i <= n; i++) {
        scanf("%d", &d[i]);
        sum += d[i];
        d[i] += d[i-1];
    }
    int last;
    scanf("%d", &last);
    sum += last;
    int t;
    scanf("%d", &t);
    while(t--) {
        int u, v;
        scanf("%d%d", &u, &v);
        cout << min(abs(d[u]-d[v]), sum - abs(d[u]-d[v])) << "\n";
    }
    return 0;
}