/*
以字符串的形式输入，然后将各位数字相加得到一个新的数字，看这个新的数字是不是3的倍数
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    int sum = 0;
    for(auto i : s) sum += (i - '0');
    if(sum % 3 != 0) puts("NO");
    else puts("YES");

    return 0;
}