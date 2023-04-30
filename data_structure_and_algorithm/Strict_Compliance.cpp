#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    string s[n];
    for(int i = 0; i < n; i++) cin >> s[i];
    //unordered_map<string, int>mp;
    int ans = INT_MAX;
    bool flag = false;
    for(int i = 0; i < n; i++) {
        //mp[s[i]] = 0;
        int cnt = 0, res = 0;
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            int sum = 0;
            string str = s[j];
            if(str == s[i]) res++; 
            while(str != s[i]) {
                if(str == s[j] && sum != 0) break;
                str += str[0];
                str = str.erase(0, 1);
                sum++;
                if(str == s[i]) {
                    //mp[str] = sum;
                    res++; // res 用于记录能够经过移动能够和基准字符串s[i]相等的字符串个数
                    cnt += sum;
                }
            }
        }
        if(res == n - 1) {
            flag = true; // 存在解决方案
            ans = min(ans, cnt);
        }
    }
    if(flag) cout << ans;
    else cout << -1;
    return 0;
}
/*
3
abde
bdea
deab
*/