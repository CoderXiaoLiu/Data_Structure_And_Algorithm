#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int n, a[maxn], b[maxn];
vector<int>v;
bool mmin[maxn] = {false}, mmax[maxn] = {false};
int main() {
    scanf("%d", &n);
    int Max = -1, Min = INT_MAX;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if(Max < a[i]) mmin[i] = true;
        Max = max(a[i], Max);
    }
    for(int i = n - 1; i >= 0; i--) {
        if(Min > a[i]) mmax[i] = true;
        Min = min(a[i], Min);
        if(mmin[i] && mmax[i]) v.push_back(a[i]);
    }
    printf("%d\n", v.size());
    for(int i = v.size() - 1; i >= 0; i--) {
        if(i == 0) printf("%d", v[i]);
        else printf("%d ", v[i]);
    }
    puts("");
    return 0;
}