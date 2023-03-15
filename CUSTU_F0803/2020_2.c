/*
编写一个程序，找出最大素数。素数：只能被1和自身除尽的数
输入：取值范围
输出：范围内的最大素数
样例输入：100
样例输出：97
*/
#include<stdio.h>
int prime(int x) { // 判断是不是素数，是素数返回1，否则返回-1；
    if(x < 2) return -1;
    if(x == 2) return 1;
    if(x % 2 == 0) return -1;
    int i;
    for(i = 3; i * i <= x; i += 2) {
        if(x % i == 0) return -1;
    }
    return 1;
}
int main() {
    int n, i;
    scanf("%d", &n);
    for(i = n; i >= 2; i--) {
        if(prime(i) == 1) {
            printf("max prime: %d", i);
            break;
        }
    }

    return 0;
}