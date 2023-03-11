/*
二分法求函数零点
有函数：f(x) = x^5 - 15 * x^4+ 85 * x^3- 225 * x^2+ 274 * x - 121
已知 f(1.5) > 0 , f(2.4) < 0 且方程 f(x) = 0 在区间 [1.5,2.4] 有且只有一个根，请用二分法求出该根。
*/
#include<stdio.h>
#include<math.h>
double f(double x) {
    return pow(x, 5) - 15 * pow(x, 4) + 85 * pow(x, 3) - 225 * pow(x, 2) + 274 * x - 121;
}
int main() {
    double left = 1.5, right = 2.4, mid;
    int flag = 0;
    while(right - left >= 0.000001) {
        mid = (left + right) / 2;
        if(f(mid) == 0) {
            printf("%.6f\n", mid);
            flag = 1;
            break;
        }
        else if(f(mid) * f(right) < 0) left = mid;
        else right = mid;
    }
    if(!flag) printf("%.6f\n", right);
    return 0;
}