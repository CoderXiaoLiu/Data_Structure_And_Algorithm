/*
写程序，输入两个数组 A 和 B，输出两个数组的公共元素（重复的公共元素只输出一次）。
例如：输入A=1,2,3,4,5, B=2,3,7,6。输出结果为：2 3
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m; // 数组 A 和 B 的长度
    scanf("%d%d", &n, &m);
    int A[n], B[m];
    int i;
    for(i = 0; i < n; i++) scanf("%d", &A[i]);
    for(i = 0; i < m; i++) scanf("%d", &B[i]);
    set<int>s;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(A[i] == B[j]) s.insert(A[i]);
        }
    }
    for(auto i : s) printf("%d ", i);
    return 0;
}