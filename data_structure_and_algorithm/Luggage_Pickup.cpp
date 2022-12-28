#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    queue<int>q;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        q.push(a[i]);
    }
    int top, time = 0, i = 1;
    double alltime = 0;
    while(i <= n) {
        top = q.front();
        q.pop();
        if(top == i) {
            time++;
            alltime += time;
            i++;
        } else {
            q.push(top);
            time++;
        }
    }
    cout << time << " ";
    cout << fixed << setprecision(1) << alltime / n;

    return 0;
}