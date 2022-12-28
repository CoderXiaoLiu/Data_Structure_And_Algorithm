#include<bits/stdc++.h>
using namespace std;
int n, a[1010];
vector<int>v;
void dfs(int index) {
    if(index > n) return;
    if(index * 2 > n && index * 2 + 1 > n) {
        for(int i = 0; i < v.size() - 1; i++) printf("%d ", v[i]);
        printf("%d\n", v[v.size() - 1]);
    } else {
        v.push_back(a[index * 2 + 1]);
        dfs(index * 2 + 1);
        v.pop_back();
        v.push_back(a[index * 2]);
        dfs(index * 2);
        v.pop_back();
    }
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    v.push_back(a[1]);
    dfs(1);
    bool MaxHeap = true, MinHeap = true;
    for(int i = 1; i <= n / 2; i++) {
        if(i * 2 <= n) {
            if(a[i] > a[i * 2]) MinHeap = false;
            if(a[i] < a[i * 2]) MaxHeap = false;
        }
        if(i * 2 + 1 <= n) {
            if(a[i] > a[i * 2 + 1]) MinHeap = false;
            if(a[i] < a[i * 2 + 1]) MaxHeap = false;
        }
    }
    if(MaxHeap) puts("Max Heap");
    else if(MinHeap) puts("Min Heap");
    else puts("Not Heap");
    return 0;
}