#include<bits/stdc++.h>
using namespace std;
void ShellSort(int a[], int n) {
    // a[0]只是暂存单元，不是哨兵，当j<=0时，插入位置已满
    int j;
    for(int dk = n / 2; dk >= 1; dk /= 2) { //步长变化
        for(int i = dk + 1; i <= n; i++) {
            if(a[i] < a[i-dk]) { //需将a[i]插入有序增量子表
                a[0] = a[i]; //暂存在a[0]
                for(j = i -dk; j > 0 && a[0] < a[j]; j-= dk) 
                    a[j+dk] = a[j]; //记录后移，查找插入的位置
                a[j+dk] = a[0]; //插入
            }
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int a[n+5];
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    ShellSort(a, n);
    for(int i = 1; i <= n; i++) printf("%d ", a[i]);
    return 0;
}
/*
8
49 38 65 97 76 13 27 49
*/