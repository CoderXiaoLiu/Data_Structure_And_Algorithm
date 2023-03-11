/*
求出10到1000之内能同时被2、3、7整除的数，并输出
*/
#include<stdio.h>
int main() {
    int i;
    for(i = 10; i <= 1000; i++) {
        if(i % 2 == 0 && i % 3 == 0 && i % 7 == 0) printf("%d ", i);
    }

    return 0;
}