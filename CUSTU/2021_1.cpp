// 写程序，输入数组a[n]，输出a[0]!+a[1]!+....+a[n-1]!的值
#include<bits/stdc++.h>
using namespace std;
int cal(int x) {
    int sum = 1;
    for(int i = 2; i <= x; i++) sum *= i;
    return sum;
}
int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i ++) scanf("%d", &a[i]);
    int ans = 0;
    for(auto i : a) ans += cal(i);
    printf("%d", ans);
    return 0;
}