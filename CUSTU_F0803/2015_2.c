/*
任意输入一个三位正整数，十位上的数字不动，将个位和百位上的数字交换，
构成一个新的正整数后输出。（例如：486变为684）
*/
#include<stdio.h>
int turn(int n) {
    int ans = 0;
    while(n > 0) {
        ans = (ans * 10) + (n % 10);
        n /= 10;
    }
    return ans;
}
int main() {
    int x;
    scanf("%d", &x);
    printf("%d", turn(x));

    return 0;
}