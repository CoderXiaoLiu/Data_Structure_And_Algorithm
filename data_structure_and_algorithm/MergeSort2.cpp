//归并排序非递归算法
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
void MergeSort(int a[], int n) {
    //step为组内元素个数，step / 2为左子区间元素个数
    for(int step = 2; step / 2 <= n; step *= 2) {
        //每step个元素一组，组内[i, min(i+step, n+1)] 进行排序
        for(int i = 1; i <= n; i += step) {
            int mid = i + step / 2 - 1; //左子区间元素个数为step / 2
            if(mid + 1 <= n) { //右子区间存在元素则合并
                //左子区间为[i, mid],右子区间为[mid+1, min(i+step-1, n)]
                Merge(a, i, mid, min(i + step - 1, n));
            }
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int a[n + 10];
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    MergeSort(a, n);
    for(int i = 1; i <= n; i++) printf("%d ", a[i]);
    return 0;
}
/*
7
32 17 45 78 65 53 9
*/