#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n;
    scanf("%d", &n);
    int a[n];
    LL l = 0, r = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        r += a[i];
    }
    int m;
    scanf("%d", &m);

    function <bool(LL)> judge = [&](LL w) {
        LL cnt = 0, sum = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] > w) return false;
            if(sum + a[i] <= w) sum += a[i];
            else {
                cnt++;
                sum = a[i];
            }
        }
        return cnt < m ? true : false;
    };

    LL ans = r;
    while(l <= r) {
        LL mid = (l + r) >> 1;
        if(judge(mid)) {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else l = mid + 1;
    }
    printf("%lld", ans);
}

int main() {
    solve();
    return 0;
}