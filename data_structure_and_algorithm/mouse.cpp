#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    int l, r;
    map <int, int> mp;
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &l, &r);
        mp[l]++, mp[r+1]--;
    }
    int ans = 0, cur = 0;
    for(auto &i:mp) {
        cur += i.second;
        ans = max(ans, cur);
    }
    printf("%d", ans);
    return 0;
}