#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    int max_value = INT_MIN, pos = -1;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if(i > 0 && abs(a[i] - a[i - 1]) > max_value) {
            max_value = abs(a[i] - a[i - 1]);
            pos = i - 1;
        }
    }
    int tmp = INT_MIN;
    if(pos == n - 2) {
        for(int i = 0; i < n - 1; i ++) tmp = max(tmp, abs(a[i] - a[i - 1]));
    }
    if(pos == 0) {
        a[pos] = a[pos + 1];
    } else {
        a[pos] = (a[pos - 1] + a[pos + 1]) / 2;
    }
    int ans = INT_MIN;
    for(int i = 1; i < n; i++) {
        ans = max(ans, abs(a[i] - a[i - 1]));
    }
    if(pos == n - 2) ans = min(ans, tmp);
    printf("%d", ans);

    return 0;
}
/*
10
99999 2 3 4 5 6 7 8 9 -999
1008
*/