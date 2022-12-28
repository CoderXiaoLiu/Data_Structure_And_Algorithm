#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int n, a[maxn], b[maxn];
vector<int>v;
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(a, a + n);
    int Max = -1;
    for(int i = 0; i < n; i++) {
        if(a[i] == b[i] && b[i] > Max) v.push_back(a[i]);
        Max = max(Max, b[i]);
    }
    printf("%d\n", v.size());
    for(int i = 0; i < v.size(); i++) {
        if(i == v.size() - 1) printf("%d", v[i]);
        else printf("%d ", v[i]);
    }
    puts("");
    return 0;
}