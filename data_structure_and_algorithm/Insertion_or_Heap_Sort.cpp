#include<bits/stdc++.h>
using namespace std;
const int maxn = 150;
int insert[maxn], heap[maxn], a[maxn], b[maxn], n;
bool judge(int a[], int b[]) {
    for(int i = 1; i <= n; i++) {
        if(a[i] != b[i]) return false;
    }
    return true;
}
void print(int a[]) {
    printf("%d", a[1]);
    for(int i = 2; i <= n; i++) printf(" %d", a[i]);
}
bool insertsort(int a[]) {
    for(int i = 2; i <= n; i++) {
        if(a[i-1] > a[i]) {
            int temp = a[i], j;
            for(j = i-1; temp < a[j]; j--) a[j+1] = a[j];
            a[j+1] = temp;
        }
        if(judge(a, b)) {
            puts("Insertion Sort");
            i++;
            if(a[i-1] > a[i]) {
                int temp = a[i], j;
                for(j = i-1; temp < a[j]; j--) a[j+1] = a[j];
                a[j+1] = temp;
            }
            print(a);
            return true;
        }
    }
    return false;
}
void HeapAdjust(int a[], int k, int len) {
    a[0] = a[k];
    for(int i = k * 2; i <= len; i *= 2) {
        if(i < len && a[i] < a[i + 1]) i++;
        if(a[0] > a[i]) break;
        else {
            a[k] = a[i];
            k = i;
        }
    }
    a[k] = a[0];
}
void BuildMaxHeap(int a[]) {
    for(int i = n / 2; i > 0; i--) 
        HeapAdjust(a, i, n);
}
void heapsort(int a[]) {
    BuildMaxHeap(a);
    for(int i = n; i > 1; i--) {
        swap(a[1], a[i]);
        HeapAdjust(a, 1, i - 1);
        if(judge(a, b)) {
            puts("Heap Sort");
            swap(a[1], a[--i]);
            HeapAdjust(a, 1, i-1);
            print(a);
        }
    }
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        insert[i] = heap[i] = a[i];
    }
    for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
    if(insertsort(insert)) return 0;
    heapsort(heap);
    return 0;
}