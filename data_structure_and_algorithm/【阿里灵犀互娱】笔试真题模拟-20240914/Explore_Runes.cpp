#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        string s1, s2;
        cin >> s1 >> s2;
        map <char, int> mp1, mp2;
        if(s1.size() > s2.size()) {
            puts("false");
            continue;
        }
        for(int i = 0; i < s1.size(); i++) {
            mp1[s1[i]]++;
            mp2[s2[i]]++;
        }
        if(mp1 == mp2) {
            puts("true");
            continue;
        }
        int left = 0, right = s1.size();
        bool flag = false;
        while(right < s2.size()) {
            mp2[s2[left]] --;
            if(mp2[s2[left]] == 0) mp2.erase(s2[left]);
            mp2[s2[right]] ++;
            if(mp1 == mp2) {
                flag = true;
                break;
            }
            left++, right++;
        }
        if(flag) puts("true");
        else puts("false");
    }

    return 0;
}