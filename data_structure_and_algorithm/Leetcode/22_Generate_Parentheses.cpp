#include<bits/stdc++.h>
using namespace std;
vector<string> generateParenthesis(int n) {
    string s = "";
    for(int i = 0; i < n; i++) s += "(";
    for(int i = 0; i < n; i++) s += ")";
    vector<string>ans;
    ans.push_back(s);
    function<bool(string)> judge = [&](string s) {
        stack <char> st;
        for(auto i : s) {
            if(i == '(') st.push(i);
            else {
                if(st.empty() || st.top() != '(') return false;
                st.pop();
            }
        }
        return st.empty();
    };
    while(next_permutation(s.begin(), s.end())) {
        if(judge(s)) ans.push_back(s);
    }
    return ans;
}
int main() {
    vector<string>ans;
    for(int i = 1; i <= 8; i++) {
        ans = generateParenthesis(i);
        for(auto s : ans) cout << s << " ";
        cout << endl;
    }
    return 0;
}