#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    int n, pos = 0;
    scanf("%d", &n);
    vector<int>a(n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    LL ans = 0;
    for(int i = 1; i < n; i++) ans += (a[0] + a[i]);
    printf("%lld\n", ans);

    return 0;
}
/*
4
9 5 5 7
*/