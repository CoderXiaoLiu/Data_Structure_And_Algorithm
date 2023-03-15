/*
根据输入的三角形的三条边判断三角形的类型,并输出它的面积和类型。
提示：首先判断所给的三条边是否能组成三角形，若可以构成三角形，则判断该三角形是什么类型，并求三角形面积。
*/
#include<stdio.h>
#include<math.h>
int judge(int a, int b, int c){
    if(a * a + b * b == c * c) return 1;
    else if(b * b + c * c == a * a) return 1;
    else if(a * a + c * c == b * b) return 1;
    return 0;
}
int main() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    if((a + b) <= c || (a + c) <= b || (b + c) <= a) {
        puts("Cannot form a triangle!!");
        return 0;
    }
    if(a == b && b == c) puts("Equilateral triangle");
    else if((a == b && b != c) || (a == c && b != c) || (c == b && a != c)) puts("an isosceles triangle");
    else if(judge(a, b, c)) puts("right triangle");
    else puts("other triangle");
    double s, area;
    s = (a + b + c) / 2;
    area = sqrt(s * (s - a) * (s - b) * (s - c));
    printf("%.3f", area);

    return 0;
}