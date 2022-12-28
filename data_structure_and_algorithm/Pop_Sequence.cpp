#include<bits/stdc++.h>
using namespace std;
int cnt, n, t;
void clear_stack(stack<int> &s) { //清空栈
    s = stack<int>(); 
}
int main() {
    scanf("%d%d%d", &cnt, &n, &t);
    stack<int>s;
    while(t--) {
        clear_stack(s);
        bool flag = true;
        int current = 1, a[n];
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        for(int i = 0; i < n; i++) {
            if(current <= a[i]) {
                while(current <= a[i]) {
                    s.push(current++);
                }
                if(s.size() > cnt) {
                    flag = false;
                    break;
                }
                s.pop();
            } else {
                int temp = s.top();
                if(temp == a[i]) s.pop();
                else {
                    flag = false;
                    break;
                }
            }
        }
        if(flag) puts("YES");
        else puts("NO");
    }
    return 0;
}