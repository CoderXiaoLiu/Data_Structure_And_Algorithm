/*
 有点像连续和那道题，可以照搬思路，但是数组存在负值，所以还要维护最小值。 
 申请二维dp数组，每个位置记录最大正值，最小负值。
*/
#include<bits/stdc++.h>
using namespace std;
int maxProduct(int* nums, int numsSize){
    int dp_min[20001] = {0}, dp_max[20001] = {0};
    dp_min[0] = nums[0], dp_max[0] = nums[0];
    int ans = nums[0], i;
    for(i = 1; i < numsSize; i++) {
        dp_max[i] = max(dp_max[i-1] * nums[i], max(dp_min[i-1] * nums[i], nums[i]));
        dp_min[i] = min(dp_max[i-1] * nums[i], min(dp_min[i-1] * nums[i], nums[i]));
        ans = max(ans, max(dp_max[i], dp_min[i]));
    }
    return ans;
}
int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("%d\n", maxProduct(a, n));
    return 0;
}
/*
4
2 3 -2 4
3
-2 3 -4
2
0 2
4
-3 0 1 -2
4
-1 -2 -3 0
*/