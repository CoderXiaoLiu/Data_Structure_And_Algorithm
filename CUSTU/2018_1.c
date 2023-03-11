/*
一个整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多少
（数字晓宇100000）
*/
#include<stdio.h>
#include<math.h>
int judge(int x) {
    int cnt = sqrt(x);
    return cnt*cnt == x ? 1 : 0;
}
int main() {
    int i;
    for(i = 1; i <= 100000; i++) {
        if(judge(i+100) == 1 && judge(i + 268) == 1) printf("%d\n", i);
    }

    return 0;
}