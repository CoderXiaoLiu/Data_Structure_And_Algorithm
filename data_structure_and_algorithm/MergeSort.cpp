#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+1;
int *b = (int *)malloc(maxn*sizeof(int)); //辅助数组b
void Merge(int a[], int low, int mid, int high) {
    //表a的两段a[low...mid]和a[mid+1...high]各自有序，将它们合并成一个有序表
    for(int k = low; k <= high; k++)
        b[k] = a[k]; // 将a中所有的元素复制到b中
    int i, j, k;
    for(i = low, j = mid + 1, k = i; i <= mid && j <= high; k++) {
        if(b[i] <= b[j]) a[k] = b[i++]; //比较b的左右两段中的元素，将较小值复制到a中
        else a[k] = b[j++];
    }
    while (i <= mid) a[k++] = b[i++]; //若第一个表未检测完，复制
    while (j <= high) a[k++] = b[j++]; //若第二个表未检测完，复制
    
}
void MergeSort(int a[], int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2; //从中间划分两个子序列
        MergeSort(a, low, mid); //对左侧子序列进行递归排序
        MergeSort(a, mid+1, high); //对右侧子序列进行递归排序
        Merge(a, low, mid, high); //归并
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int a[n + 10];
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    MergeSort(a, 1, n);
    for(int i = 1; i <= n; i++) printf("%d ", a[i]);
    return 0;
}
/*
7
32 17 45 78 65 53 9
*/