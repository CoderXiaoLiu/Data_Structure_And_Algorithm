/*
假设黑白图像由二维举证表示，行数为M<5，列数为N<5，值分别用0或1表示。
输入两幅相同大小的黑白图像表示，求它们的相似度。
说明：若两幅图像在相同位置上的像素点颜色相同，则称它们在该位置具有相同的
像素点。两幅图像的相似度定义为相同像素点数占总像素点数的百分比。
*/
#include<stdio.h>
int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    int a[m][n], b[m][n];
    int i, j;
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
           scanf("%d", &a[i][j]); 
        }
    }
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
           scanf("%d", &b[i][j]); 
        }
    }
    double sum = 0, ans = 0;
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            if(a[i][j] == b[i][j]) sum++;
        }
    }
    printf("%.2f %%", sum / (m*n) * 100);

    return 0;
}
/*
3 4
1 0 1 0
1 1 0 0
0 0 1 0
1 1 1 0
0 1 0 1
1 0 1 1
*/