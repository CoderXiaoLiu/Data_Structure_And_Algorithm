#include<bits/stdc++.h>
using namespace std;
void InsertSort(int a[], int n) {
    int i, j, low, high, mid, temp;
    for(i = 1; i < n; i++) {
        temp = a[i];
        low = 0, high = i - 1;
        while(low <= high) { //折半查找
            mid = (low + high) >> 1; // 取中间点
            if(a[mid] > temp) high = mid - 1; //查找左半子表
            else low = mid + 1; //查找右半子表
        }
        for(j = i - 1; j >= high + 1; j--) a[j+1] = a[j]; //统一后移元素，空出插入位置
        a[high+1] = temp; // 插入操作
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