/*
使用C语言编写程序打印出输出10000以内的完全数
（各个小于它的约数（真约数, 列出某数的约数， 掉该数本身， 剩下的就是它的真约数）的和等于它本身的自然数叫做完全数）
*/
#include<stdio.h>
int judge(int x) {
    if(x == 1) return 0;
    int num = 1, i;
    for(i = 2; i * i <= x; i++) {
        if(x % i == 0) {
            num += i;
            num += (x / i);
        }
    }
    return num == x ? 1 : 0;
}
int main() {
    int i;
    for(i = 2; i <= 10000; i++) {
        if(judge(i)) printf("%d, ", i);
    }

    return 0;
}