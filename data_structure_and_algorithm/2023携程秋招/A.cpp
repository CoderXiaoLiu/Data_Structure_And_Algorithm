#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        string s;
        cin >> s;
        bool flag = false;
        int n = s.size();
        if((s[n - 1] - '0') % 2 == 0) {
            cout << s << "\n";
            continue;
        }
        for(int i = 0; i < n; i++) {
            if((s[i] - '0') % 2 == 0) {
                flag = true;
                swap(s[i], s[n - 1]);
                break;
            }
        }
        if(flag) {
            while(s[0] == '0') s.erase(s.begin());
            cout << s << "\n";
        }
        else cout << "-1\n"; 
    }

    return 0;
}