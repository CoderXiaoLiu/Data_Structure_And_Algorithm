#include<bits/stdc++.h>
using namespace std;
int Partition(int a[], int low, int high) { //一趟划分
    int piovt = a[low]; //将当前表中第一个元素设为枢轴，对表进行划分
    while(low < high) { //循环跳出条件
        while(low < high && a[high] >= piovt) high--;
        a[low] = a[high]; //将比枢轴小的元素移动到左端
        while(low < high && a[low] <= piovt) low++;
        a[high] = a[low]; // 将比枢轴大的元素移动到右端
    }
    a[low] = piovt; //枢轴元素存放到最终位置
    return low; // 返回存放枢轴的最终位置
}
void QuickSort(int a[], int low, int high) {
    if(low < high) { // 递归跳出的条件
    //Partition()就是划分操作，将表A[low...high]划分为满足上述条件的两个子表
        int piovtpos = Partition(a, low, high); //划分
        QuickSort(a, low, piovtpos - 1); // 依次对两个子表进行递归排序
        QuickSort(a, piovtpos + 1, high);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    QuickSort(a, 0, n - 1);
    for(auto &i: a) printf("%d ", i);
    return 0;
}
/*
8
49 38 65 97 76 13 27 49
*/