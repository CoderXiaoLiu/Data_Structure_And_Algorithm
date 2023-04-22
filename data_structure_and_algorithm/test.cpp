
#include<bits/stdc++.h>
using namespace std;
string decodeString(string s) {
    stack<string>st_string;
    stack<int>st_num;
    string ans = "", temp = "";
    int num = 0;
    for(int i = 0; i < s.size(); i++) {
        if(isdigit(s[i])) {
            while(s[i] != '[') num = num * 10 + (s[i++] - '0');
            st_num.push(num);
            num = 0;
        } 
        if(isalpha(s[i])) {
            if(i > 0 && s[i-1] != '[') {
                while(isalpha(s[i])) ans = ans + s[i++];
            } else {
                while(isalpha(s[i])) temp = temp + s[i++];
                st_string.push(temp);
                temp = "";
            }
        }
        if(s[i] == ']') {
            int topn = st_num.top();
            st_num.pop(); // 出栈
            string tops = st_string.top();
            st_string.pop();
            string res = "";
            for(int j = 0; j < topn; j++) res = res + tops;
            if(!st_string.empty()) {
                tops = st_string.top();
                st_string.pop();
                tops = tops + res;
                st_string.push(tops);
            } else {
                ans = ans + res;
            }
        }
    }
    return ans;
}
int main() {
    string s;
    cin >> s;
    cout << decodeString(s);
    system("pause");
    return 0;
}
/*
3[a2[c]]
*/