/*
Pell数列a 1, a 2, a 3, …的定义是这样的，a 1 = 1, a 2 = 2, … , a n = 2 * a n − 1 + a n - 2 (n > 2)。
给出一个正整数k，要求Pell数列的第k项模上32767是多少。
*/
#include<stdio.h>
const int MOD = 32767;
int main() {
    int a[51];
    a[1] = 1, a[2] = 2;
    int i;
    for(i = 3; i <= 50; i++) a[i] = ((a[i-1] * 2) % MOD + (a[i-2]) % MOD) % MOD;
    for(i = 1; i <= 50; i++) {
        printf("%d\n", a[i]);
    }

    return 0;
}