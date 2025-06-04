#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int ans = 0, res = min(a, min(b, c));
        ans += (res * 2);
        b -= res;
        ans += max(0, b - 1);
        printf("%d\n", ans);
    }
    return 0;
}