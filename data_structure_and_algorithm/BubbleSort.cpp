#include<bits/stdc++.h>
using namespace std;
void BubbleSort(int a[], int n) {
    bool flag;
    for(int i = 0; i < n - 1; i++) {
        flag = false; // 表示本趟冒泡是否发生交换的标志
        for(int j = n - 1; j > i; j--) { //一趟冒泡过程
            if(a[j] < a[j - 1]) { // 若为逆序
                swap(a[j], a[j-1]); //交换
                flag = true;
            }
        }
        if(!flag) return; //本趟遍历后没有发生交换，说明表
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    BubbleSort(a, n);
    for(auto &i: a) printf("%d ", i);
    return 0;
}
/*
8
49 38 65 97 76 13 27 49
*/