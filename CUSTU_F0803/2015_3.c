/*
编写自定义函数prime(int x)，判断 x 是否为素数。
利用此函数编写程序找出100~2000中所有素数，并输出素数的个数
*/
#include<stdio.h>
#include<stdbool.h>
bool prime(int x) {
    if(x < 2) return false;
    if(x == 2) return true;
    if(x % 2 == 0) return false;
    int i;
    for(i = 3; i * i <= x; i += 2) {
        if(x % i == 0) return false;
    }
    return true;
}   
int main() {
    int i;
    for(i = 100; i<= 2000; i++) {
        if(prime(i)) printf("%d ", i);
    }
    return 0;
}