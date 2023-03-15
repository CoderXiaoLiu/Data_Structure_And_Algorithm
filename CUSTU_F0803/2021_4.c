/*
写程序，输入一行字符，分别统计出其中英文小写字母、大写字母、空格、数字和其他字符的个数
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
    char s[100];
    gets(s);
    int upper = 0, lower = 0, kongge = 0, digit = 0, else_sum = 0;
    int len = strlen(s), i;
    for(i = 0; i < len; i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') upper++;
        else if(s[i] >= 'a' && s[i] <= 'z') lower++;
        else if(s[i] == ' ') kongge++;
        else if(s[i] >= '0' && s[i] <= '9') digit++;
        else else_sum++;
    }
    printf("大写字母的总数为：%d\n", upper);
    printf("小写字母的总数为：%d\n", lower);
    printf("空格字符的总数为：%d\n", kongge);
    printf("数字字符的总数为：%d\n", digit);
    printf("其他字符的总数为：%d\n", else_sum);
    system("pause");
    return 0;
}