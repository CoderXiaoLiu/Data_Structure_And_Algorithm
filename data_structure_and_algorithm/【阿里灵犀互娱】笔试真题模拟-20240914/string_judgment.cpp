#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        string a, b;
        cin >> a >> b;
        int n = a.size(), m = b.size();
        if(n < m) {
            puts("NO");
            continue;
        }
        int i = 0, j = 0;
        while(i < n && j < m) {
            if(toupper(a[i]) == b[j] || a[i] == b[j]) {
                j++, i++;
                continue;
            }
            if(isupper(a[i])) break;
            else i++;
        }
        if(j == m) puts("YES");
        else puts("NO");
    }

    return 0;
}
/*
3
DaBcd
ABC
daBcd
ABC
AbcDE
AFDE
*/