#include<bits/stdc++.h>
using namespace std;
void InsertSort(int a[], int n) {
    int temp, i, j;
    for(i = 1; i < n; i++) { // 依次将a[1]~a[n-1]插入前面已经排序序列
        if(a[i] < a[i-1]) { //若a[i]关键码小于其前驱，将a[i]插入有序表
            temp = a[i];
            for(j = i - 1;temp < a[j]; j--) a[j + 1] = a[j]; //从后往前查找待插入位置并向后挪位
            a[j+1] = temp;  //复制到插入位置
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    InsertSort(a, n);
    for(auto &i: a) printf("%d ", i);
    return 0;
}
/*
8
49 38 65 97 76 13 27 49
*/