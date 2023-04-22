/*
首先将数组排序。

如果数组中全是非负数，则排序后最大的三个数相乘即为最大乘积；如果全是非正数，则最大的三个数相乘同样也为最大乘积。

如果数组中有正数有负数，则最大乘积既可能是三个最大正数的乘积，也可能是两个最小负数（即绝对值最大）与最大正数的乘积。

综上，我们在给数组排序后，分别求出三个最大正数的乘积，以及两个最小负数与最大正数的乘积，二者之间的最大值即为所求答案。
*/
#include<bits/stdc++.h>
using namespace std;
int maximumProduct(vector<int>& nums) {
    int len = nums.size();
    if(len == 3) return nums[0] * nums[1] * nums[2];
    sort(nums.begin(), nums.end());
    return max(nums[0] * nums[1] * nums[len-1], nums[len-1] * nums[len-2] * nums[len-3]);
}
int main() {
    int n, x;
    scanf("%d", &n);
    vector<int>v;
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        v.push_back(x);
    }
    printf("%d\n", maximumProduct(v));

    return 0;
}
/*
5
-8 -7 -2 10 20
*/