#include<bits/stdc++.h>
using namespace std;
const int maxn = 110;
int merg[maxn], insert[maxn], b[maxn], n;
bool judge(int a[]) {
    for(int i = 0; i < n; i++) {
        if(a[i] != b[i]) return false;
    }
    return true;
}
bool InsertSort(int a[]) {
    for(int i = 1; i < n; i++) {
        if(a[i] < a[i-1]) {
            int temp = a[i], j;
            for(j = i - 1; temp < a[j]; j--) a[j+1] = a[j];
            a[j+1] = temp; 
        }
        if(judge(a)) {
            puts("Insertion Sort");
            int temp = a[++i], j;
            for(j = i - 1; temp < a[j]; j--) a[j+1] = a[j];
            a[j+1] = temp;
            printf("%d", a[0]);
            for(int i = 1; i < n; i++) printf(" %d", a[i]);
            return true;
        }
    }
    return false;
}
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &insert[i]);
        merg[i] = insert[i];
    }
    for(int i = 0; i < n; i++) scanf("%d", &b[i]);
    if(InsertSort(insert)) return 0;
    puts("Merge Sort");
    bool flag = false;
    int len = 2;
    while(!flag) {
        if(judge(merg)) flag = true;
        for(int i = 0; i < n; i+=len) {
            sort(merg + i, merg + min(i + len, n));
        }
        len *=2;
    }
    printf("%d", merg[0]);
    for(int i = 1; i < n; i++) printf(" %d", merg[i]);
    return 0;
}