/*
计算n！是一个非常难的任务，
事实上n=20时，计算机的长整型就存放不了这么大的数了，
但是，我们可以编写程序来算出n！的最后一位非0的数。
*/
#include<stdio.h>
#include<math.h>
typedef long long LL;
int main() {
    int n;
    scanf("%d", &n);
    LL cnt = 1;
    int i;
    for(i = 2; i <= n; i++) {
        cnt *= i;
        while(cnt % 10 == 0) cnt /= 10;
        cnt %= 1000000; // 对一个大于等于1000的数取模，不然会出问题
    }
    printf("%d\n", cnt % 10);

    return 0;
}