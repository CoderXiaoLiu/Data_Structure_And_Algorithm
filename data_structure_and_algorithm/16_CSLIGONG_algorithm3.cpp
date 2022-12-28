#include<bits/stdc++.h>
using namespace std;
const int maxn = 80000;
const int mod = 80000;
void HeapAdjust(int a[], int k, int len) { // 将元素k为根的子树进行调整
    a[0] = a[k]; // a[0] 暂存子树根节点
    for(int i = k*2; i <= len; i *= 2) {
        if(i < len && a[i] > a[i+1]) i++; // 沿着key较小的子结点向下筛选
        if(a[0] <= a[i]) break;
        else {
            a[k] = a[i]; // 将a[i] 调整到双亲上
            k = i; // 修改k值，以便继续向下筛选
        }
    }
    a[k] = a[0]; // 被筛选的结点的值放入最终位置
}
void build_Min_Heap(int a[], int len) { // 建立小根堆
    for(int i = len / 2; i >= 1; i--) {
        HeapAdjust(a, i, len);
    }
}
/*
void solve(int test[], int a[]) {
    // 假设test为已建立的顺序表, a为小根堆
    for(int i = 1; i <= 10; i++) a[i] = test[i];
    build_Min_Heap(a, 10); // 建立小根堆
    for(int i = 11; i <= 80000; i++) {
        if(test[i] > a[1]) { // 如果大于堆的根节点，则替换根节点，并调整堆
            a[1] = test[i];
            HeapAdjust(a, 1, 10); 
        }
    }
    // 遍历完所有结点之后，小根堆里面的十个数即最大的十个数
    for(int i = 1; i <= 10; i++) printf("%d ", a[i]);
}
*/
bool judge(int test[], int a[]) { 
    // judge函数用于判断此时a数组里面的数是否是80000个整数里面最大的10个整数
    sort(test + 1, test + maxn + 1, greater<int>()); // 将 test数组从大到小排序
    sort(a + 1, a + 10 + 1, greater<int>()); // 将a数组从小到大排序
    for(int i = 1; i <= 10; i++) cout << a[i] << " ";
    cout << endl;
    for(int i = 1; i <= 10; i++) cout << test[i] << " ";
    cout << endl;
    for(int i = 1; i <= 10; i++) { // 判断堆里面的十个数是不是80000个数里面最大的10个数
        if(a[i] != test[i]) return false;
    }
    return true;
}
int a[11]; // 小根堆
int test[maxn+10]; // test数组用于记录输入的80000个数
int main() {
    srand((unsigned)time(NULL));
    int n;
    for(int i = 1; i <= 10; i++) { 
        n = rand() % mod;
        //n= i;
        a[i] = n;
        test[i] = a[i];
    }
    build_Min_Heap(a, 10); // 先将前面输入的前十个数建立好小根堆
    for(int i = 11; i <= maxn; i++) {
        n = rand() % mod;
        //n=i;
        test[i] = n;
        if(n > a[1]) { // 如果大于堆的根节点，则替换根节点，并调整堆
            a[1] = n;
            HeapAdjust(a, 1, 10);
        }
    }
    for(int i = 1; i <= 10; i++) cout << a[i] << " ";
    cout << endl;
    // sort(test+1, test+maxn+1);
    // for(int i =1; i <= maxn; i++) cout << test[i] << " ";
    //cout << endl;
    if(judge(test, a)) cout << "yes";
    else cout << "no";
    return 0;
}