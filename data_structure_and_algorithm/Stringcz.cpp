/*
题目描述：
小可可和小多在研究数字串，他们在研究一个数字串的所有子串。
给定一个长为 N 的数字串（即由若干 0 ∼ 9 的数字构成的字符串），请你回答有 
多少连续子串（即从该串中选出连续的若干个数字，可以包括前导 0）是 4 或 5 的倍数 （如果同时是 4 和 5 的倍数，应当只被计算一次）。 
*/
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int maxn = 1e6 + 10;
LL dp_4[maxn] = {0}, dp_5[maxn] = {0};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    if((s[0] - '0') % 4 == 0) dp_4[0] = 1;
    for(LL i = 0; i < n; i++) {
        if((s[i] - '0') % 5 == 0) dp_5[i] = i + 1;
        if(i == 0) continue;
        int x = s[i] - '0', y = (s[i-1] - '0') * 10 + s[i] - '0';
        if(x % 4 == 0 && y % 4 == 0) dp_4[i] = i + 1;
        else if(y % 4 == 0) dp_4[i] = i; 
        else if(x % 4 == 0) dp_4[i] = 1;
    }
    LL ans = 0;
    for(int i = 0; i < n; i++) ans += max(dp_4[i], dp_5[i]);
    cout << ans;

    return 0;
}
/*
5
04321
*/