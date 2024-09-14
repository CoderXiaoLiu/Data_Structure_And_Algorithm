/*
桌子上放了一排石头，有n个，每块石头的颜色可以是红色，绿色或蓝色。
现在要从这排石头取出数个石头，以便剩余的石头里面，任何两颗相邻的石头具有不同的颜色的(取出1块石头后，就认为两边的石头是相邻的)。
请根据输入的石头数量、排序和颜色，计算最少要取出几块石头?
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, ans = 0; 
    scanf("%d", &n);
    string s;
    cin >> s;
    for(int i = 1; i < n; i++) {
        if(s[i] == s[i - 1]) ans++;
    }
    printf("%d", ans);

    return 0;
}