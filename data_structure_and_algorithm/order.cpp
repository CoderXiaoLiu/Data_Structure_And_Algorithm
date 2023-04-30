#include<bits/stdc++.h>
using namespace std;
using LL = long long;
LL binaryPow(LL a, LL b, LL m) {
    LL ans = 1;
    while(b > 0) {
        if(b & 1) ans = ans * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return ans;
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int p, x, cnt = 1;
        scanf("%d%d", &p, &x);
        LL res = 1;
        while(cnt < p) {
            res = binaryPow(x, cnt, p);
            if(res % p == 1) {
                printf("%d\n", cnt);
                break;
            }
            cnt++;
            res %= p;
        }
    }

    return 0;
}