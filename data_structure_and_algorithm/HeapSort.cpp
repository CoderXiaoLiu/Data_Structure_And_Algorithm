#include<bits/stdc++.h>
using namespace std;
void HeapAdjust(int a[], int k, int len) {
    // 函数HeapAdjust将元素k为根的子树进行调整
    a[0] = a[k]; //a[0]暂存子树的根节点
    for(int i = 2 * k; i <= len; i *= 2) {
        if(i < len && a[i] < a[i+1]) i++; //取key值较大的子结点的下标
        if(a[0] >= a[i]) break; //筛选结束
        else {
            a[k] = a[i]; //将a[i]调整到双亲结点上
            k = i; //修改k值，以便继续向下筛选
        }
    }
    a[k] = a[0]; //被筛选结点的值放入最终位置
}
void BuildMaxHeap(int a[], int len) {
    for(int i = len / 2; i > 0; i--) //从i=[n/2] ~ 1反复调整堆
        HeapAdjust(a, i, len); 
}
void HeapSort(int a[], int len) {
    BuildMaxHeap(a, len); //初始建堆
    for(int i = len; i > 1; i--) { //n-1趟的交换和建堆过程
        swap(a[i], a[1]); //输出堆顶元素（和堆底元素交换）
        HeapAdjust(a, 1, i - 1);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int a[n + 10];
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    HeapSort(a, n);
    for(int i = 1; i <= n; i++) printf("%d ", a[i]);
    return 0;
}
/*
7
32 17 45 78 65 53 9
*/