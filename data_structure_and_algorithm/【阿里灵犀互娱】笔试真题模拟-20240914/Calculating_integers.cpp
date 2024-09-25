#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int x, y;
        scanf("%d%d", &x, &y);
        unsigned long long ans = 0;
        for (int i = 31; i >= 0; i--) {
            ans = (ans << 1) | ((x >> i) & 1); // 先放x的第i位
            ans = (ans << 1) | ((y >> i) & 1); // 再放y的第i位
        }
        printf("%llu\n", ans);
    }

    return 0;
}