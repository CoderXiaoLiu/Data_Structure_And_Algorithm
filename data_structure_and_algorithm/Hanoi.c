/*
解法：如果柱子标为ABC，要由A搬至C，在只有一个盘子时，就将它直接搬至C，当有两个盘子，就将B当
做辅助柱。如果盘数超过2个，将第三个以下的盘子折起来，就很简单了，每次处理两个盘子，也就是：
A->B、A->C、B->C这三个步骤，而被遮住的部分，其实就是进入程序的递归处理。事实上，若有n个盘子，
则移动完毕所需之次数为2^n-1。
*/
#include<stdio.h>
#include<stdlib.h>
void hanoi(int n, char A, char B, char C) {
    if(n == 1) {
        printf("移动圆盘:%d从盘%c到盘%c\n", n, A, C);
    } else {
        hanoi(n - 1, A, C, B);
        printf("移动圆盘:%d从盘%c到盘%c\n", n, A, C);
        hanoi(n - 1, B, A, C);
    }
}
int pow(int n, int a) {
    int sum = 1;
    for(int i = 1; i <= a; i++) sum *= n;
    return sum;
}
int main() {
    int n;
    scanf("%d", &n);
    hanoi(n, 'a', 'b', 'c');
    printf("%d\n", pow(2, n) - 1);
    system("pause") ;
    return 0;
}