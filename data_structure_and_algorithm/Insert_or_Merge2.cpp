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
int temp[maxn] = {0};
void merge(int a[], int low, int mid, int high) {
    for(int i = 0; i < n; i++) temp[i] = merg[i];
    int i, j, k;
    for(i = k = low, j = mid+1; i <= mid && j <= high; k++) {
        if(temp[i] <= temp[j]) a[k] = temp[i++];
        else a[k] = temp[j++];
    }
    while(i <= mid) a[k++] = temp[i++];
    while(j <= high) a[k++] = temp[j++];
}
void MergeSort(int a[]) {
    for(int step = 2; step / 2 < n; step *= 2) {
        for(int i = 0; i < n; i += step) {
            int mid = i + step / 2 - 1;
            if(mid + 1 <= n - 1) { //如果有右子区间则归并
                merge(a, i, mid, min(i + step - 1, n - 1));
            }
        }
        if(judge(a)) {
            puts("Merge Sort");
            step *= 2;
            for(int i = 0; i < n; i += step) {
                int mid = i + step / 2 - 1;
                if(mid + 1 <= n - 1) {
                    merge(a, i, mid, min(i + step - 1, n - 1));
                }
            }
            printf("%d", merg[0]);
            for(int i = 1; i < n; i++) printf(" %d", merg[i]);
            return;
        }
    }
}
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &insert[i]);
        merg[i] = insert[i];
    }
    for(int i = 0; i < n; i++) scanf("%d", &b[i]);
    if(InsertSort(insert)) return 0;
    MergeSort(merg);
    
    return 0;
}