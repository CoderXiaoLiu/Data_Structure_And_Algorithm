/*
编写程序完成求和，s=1-(1/2)+(1/3)-(1/4)+…+(1/n)，其中n=10
*/
#include<stdio.h>
#include<stdlib.h>
int main() { 
    double ans = 1;
    int i;
    for(i = 2; i < 10; i++) {
        if(i % 2 == 0) ans -= (1.0 / i);
        else ans += (1.0 / i);
    }
    printf("%.3f\n", ans);
    return 0;
}