#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    int n;
    scanf("%d", &n);
    int a[n + 1];
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int m, p1, s1, s2;
    scanf("%d%d%d%d", &m, &p1, &s1, &s2);

    LL dragon = 0, tiger = 0;
    for(int i = 1; i < m; i++) dragon += (LL)(m - i) * a[i];
    for(int i = m + 1; i <= n; i++) tiger += (LL)(i - m) * a[i];
    if(p1 < m) dragon += (LL)(m - p1) * s1;
    else if(p1 > m) tiger += (LL)(p1 - m) * s1;
    //cout << dragon << " " << tiger;

    LL tmp = abs(tiger - dragon), ans = -1;
    for(int i = 1; i < m; i++) {
        LL cnt = dragon + (LL)(m - i) * s2;
        if(abs(cnt - tiger) < tmp) {
            tmp = abs(cnt - tiger);
            ans = i;
        }
    }
    for(int i = m + 1; i <= n; i++) {
        LL cnt = tiger + (LL)(i - m) * s2;
        if(abs(cnt - dragon) < tmp) {
            tmp = abs(cnt - dragon);
            ans = i;
        }
    }
    if(ans == -1) ans = m;
    printf("%d", ans);

    return 0;
}