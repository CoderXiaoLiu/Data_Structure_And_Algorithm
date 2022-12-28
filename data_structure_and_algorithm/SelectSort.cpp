#include<bits/stdc++.h>
using namespace std;
void SelectSort(int a[], int n) {
    for(int i = 0; i < n - 1; i++) { // 一共进行n-1趟
        int min = i; // 记录最小元素的位置
        for(int j = i + 1; j < n; j++) { //在a[i..n-1]中选择最小元素
            if(a[j] < a[min]) min = j; //更新最小元素的位置
        }
        if(min != i)swap(a[min], a[i]); //swap函数共移动元素三次
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    SelectSort(a, n);
    for(auto &i: a) printf("%d ", i);
    return 0;
}