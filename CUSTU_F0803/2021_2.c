/*
写程序，求区间[200, 3000]中所有包含数字k(k为输入，0<=k<=9)的回文数
*/
#include<stdio.h>
#include<stdlib.h>
int judge(int x, int k) {
    int flag = -1, res = 0, cnt = x;
    while(cnt > 0) {
        if(cnt % 10 == k) flag = 1;
        res = res * 10 + (cnt % 10);
        cnt /= 10;
    }
    if(flag == 1 && x == res) return 1;
    return -1;
}
int main() {
    int i, k;
    scanf("%d", &k);
    for(i = 200; i <= 3000; i++) {
        if(judge(i, k) == 1) printf("%d\n", i);
    }
    return 0;
}