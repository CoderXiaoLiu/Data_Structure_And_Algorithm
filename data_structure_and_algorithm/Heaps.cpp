#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;
int t, n;
int a[maxn];
bool isMinHeap(int a[]) {
    if(n % 2 == 0) { //长度为偶数，有一个单分支结点
        if(a[n] < a[n/2]) return false; // 判断单分支结点
        for(int i = n / 2 - 1; i >= 1; i--) { //判断所有双分支结点
            if(a[i] > a[i * 2] || a[i] > a[i*2+1]) return false;
        }
    } else { // n为奇数时，没有单分支结点 
        for(int i = n / 2; i >= 1; i--) { //判断所有双分支结点
            if(a[i] > a[i * 2] || a[i] > a[i*2+1]) return false;
        }
    }
    return true;
}
bool isMaxHeap(int a[]) {
    if(n % 2 == 0) {
        if(a[n] > a[n/2]) return false;
        for(int i = n / 2 - 1; i >= 1; i--) {
            if(a[i] < a[i * 2] || a[i] < a[i*2+1]) return false;
        }
    } else {
        for(int i = n / 2; i >= 1; i--) {
            if(a[i] < a[i * 2] || a[i] < a[i*2+1]) return false;
        }
    }
    return true;
}
int cnt;
void postorder(int k) {
    if(k > n) return;
    postorder(k * 2);
    postorder(k * 2 + 1);
    if(cnt != n-1) {
        printf("%d ", a[k]);
        cnt++;
    }
    else printf("%d\n", a[k]);
}
int main() {
    scanf("%d%d", &t, &n);
    while (t--)
    {
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        cnt = 0;
        if(isMaxHeap(a)) {
            puts("Max Heap");
            postorder(1);
        } else if(isMinHeap(a)) {
            puts("Min Heap");
            postorder(1);
        } else {
            puts("Not Heap");
            postorder(1);
        }
    }
    return 0;
}