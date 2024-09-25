#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        string s1, s2;
        cin >> s1 >> s2;
        map <char, int> mp;
        for(auto i : s2) mp[i]++;
        for(auto i : s1) {
            if(!mp[i]) {
                puts("false");
                break;
            }
            mp[i]--;
        }
        for(auto i : s1) {
            if(mp[i] != 0) {
                puts("false");
                break;
            }
        }
        puts("true");
    }

    return 0;
}