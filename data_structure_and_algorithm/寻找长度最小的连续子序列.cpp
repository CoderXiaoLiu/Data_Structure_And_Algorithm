/*
滑动窗口
首先定义变量 len 来记录数组 nums 的长度，以及 left、right、sum、ans 四个变量来记录当前子数组的左右端点、元素和、最小长度。
通过一个 for 循环遍历数组 nums 中的元素，不断更新 sum 和 ans 的值。
如果当前子数组的和小于目标值 target，则将 right 指针右移并将 nums[right] 的值加到 sum 上。
如果当前子数组的和大于等于目标值 target，则计算当前子数组的长度，并将 ans 更新为当前长度和之前最小长度的较小值。
然后将 left 指针右移并将 nums[left] 的值从 sum 中减去，此时子数组的和即为原来的值减去 nums[left]。
重复以上步骤，直到 right 超出数组范围或者找到了符合要求的子数组。
如果 ans 的值没有被更新过，即不存在符合要求的子数组，则返回 0；否则返回 ans。
*/
#include<bits/stdc++.h>
using namespace std;
int minSubArrayLen(int target, vector<int>& nums) {
    int len = nums.size();
    int left = 0, right = 0, sum = 0, ans = INT_MAX;
    for(left = 0, right = 0; right < len;) {
        if(sum < target) sum += nums[right];
        else {
            ans = min(ans, right - left + 1);
            //cout << left << " " << right << " " << sum << endl;
            sum -= nums[left++];
        }
        if(sum < target) right++;
    }
    if(ans == INT_MAX) return 0;
    return ans;
}
int main() {
    int n, x, target;
    scanf("%d", &n);
    vector<int>v;
    for(int i = 0; i < n; i ++) {
        scanf("%d", &x);
        v.push_back(x);
    }
    scanf("%d", &target);
    printf("%d\n", minSubArrayLen(target, v));

    return 0;
}
/*
6
2 3 1 2 4 3
7
*/