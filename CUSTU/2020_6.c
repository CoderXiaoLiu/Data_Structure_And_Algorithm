/*
实现两个升序数组的合并
*/
#include<stdio.h>
#include<stdlib.h>
int *merge(int *data1, int *data2, int length1, int length2) {
    int k = 0, i = 0, j = 0;
    int *a;
    a = (int *) malloc (sizeof(a) * (length1+ length2));
    while(i < length1 && j < length2) {
        if(data1[i] < data2[j]) a[k++] = data1[i++];
        else a[k++] = data2[j++];
    }
    while(i < length1) a[k++] = data1[i++];
    while(j < length2) a[k++] = data2[j++];
    return a;
}
int main() {
    int length1, length2, i;
    scanf("%d%d", &length1, &length2);
    int data1[length1], data2[length2];
    for(i = 0; i < length1; i++) scanf("%d", &data1[i]);
    for(i = 0; i < length2; i++) scanf("%d", &data2[i]);
    int *ans = merge(data1, data2, length1, length2);
    for(i = 0; i < length1 + length2; i++) printf("%d ", ans[i]);

    return 0;
}