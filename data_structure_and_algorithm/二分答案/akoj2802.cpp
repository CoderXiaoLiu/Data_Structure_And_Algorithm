#include<bits/stdc++.h>
using namespace std;

using LL = long long;

void solve() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        int a[n];
        LL l = 0, r = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            r += a[i];
        }

        function <bool(LL)> check = [&](LL x) {
            LL cnt = 0, sum = 0;
            for(int i = 0; i < n; i++) {
                sum += a[i];
                if(sum >= x) {
                    cnt++;
                    sum = 0;
                }
            }
            return cnt == m ? true : false;
        };

        LL ans = r;
        while(l <= r) {
            LL mid = (l + r) >> 1;
            if(check(mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        printf("%d\n", ans);
    }
}

int main() {
    solve();
    return 0;
}