#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    getchar(); // 去除换行符对getline的影响
    while(t--) {
        string s;
        getline(cin, s);

        stack <string> st;
        stringstream ss(s);//将字符串s复制到ss中去
        string a;
        while(ss >> a){
            // cout << a << endl;
            st.push(a);
        }

        while(!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        puts("");
    }

    return 0;
}