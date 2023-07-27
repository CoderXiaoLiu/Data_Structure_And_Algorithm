# 摩尔投票算法（Moore's Voting Algorithm）及例题

上午打力扣第 354 场周赛最后十五分钟用摩尔投票算法顺利 AC 第三题，以前没接触过摩尔投票算法，上午比赛的时候去学习了一下摩尔投票算法瞬间有了灵感，直接秒掉了第三题。

## 摩尔投票算法简介

摩尔投票算法最早由 Robert S. Boyer 和 J Strother Moore 在 1981 年的论文 "MJRTY—A Fast Majority Vote Algorithm" 中提出。这篇论文描述了摩尔投票算法的原理和证明，并展示了它在实际应用中的高效性。

论文的引用信息如下：

> Title: MJRTY—A Fast Majority Vote Algorithm 
>
> Authors: Robert S. Boyer, J Strother Moore 
>
> Year: 1981 Published in: Automated 
>
> Reasoning: Essays in Honor of Woody Bledsoe 
>
> Publisher: Springer-Verlag 
>
> Pages: 105-117

具体算法证明大家可以去查看论文：[MJRTYA Fast Majority Vote Algorithm](https://leetcode.cn/link/?target=https://www.cs.ou.edu/~rlpage/dmtools/mjrty.pdf)

## 摩尔投票算法算法思想

摩尔投票算法（Moore's Voting Algorithm）是一种用于在数组中寻找多数元素的有效方法。所谓多数元素，是指在数组中出现次数超过一半以上的元素。最经典的例子就是用于众数的寻找。

摩尔投票算法的基本思想很简单，它通过消除不同元素之间的对抗来找到可能的多数元素。算法遍历数组并维护两个变量：候选元素和其对应的票数。开始时，候选元素为空，票数为0。然后对于数组中的每个元素，执行以下步骤：

1. 如果票数为0，将当前元素设为候选元素，并将票数设置为1。
2. 如果当前元素等于候选元素，则票数加1。
3. 如果当前元素不等于候选元素，则票数减1。

**这样做的效果是，相同元素的票数会相互抵消，不同元素的对抗也会导致票数减少。由于多数元素的出现次数超过一半以上，所以最终留下的候选元素就很有可能是多数元素。**

遍历完整个数组后，候选元素即为多数元素的候选者。然后我们需要进一步验证候选元素是否真的是多数元素，因为可能存在没有多数元素的情况。我们再次遍历数组，统计候选元素的出现次数，如果发现它的出现次数超过了一半以上，则确认它为多数元素；否则，表示没有多数元素。

以下是摩尔投票算法的伪代码：

```python
function findMajorityElement(nums):
    candidate = None
    count = 0

    for num in nums:
        if count == 0:
            candidate = num
        if candidate == num:
            count += 1
        else:
            count -= 1

    # 进行第二次遍历，验证 candidate 是否为多数元素
    count = 0
    for num in nums:
        if num == candidate:
            count += 1

    if count > len(nums) / 2:
        return candidate
    else:
        return None
```

摩尔投票算法的时间复杂度为O(n)，空间复杂度为O(1)，是一种高效的寻找多数元素的算法。

## 摩尔投票算法经典题目

### 169. 多数元素

[169. 多数元素](https://leetcode.cn/problems/majority-element/)

给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

![image-20230716151822817](https://typorapic.oss-cn-shenzhen.aliyuncs.com/image-20230716151822817.png)

解题思路：

直接摩尔投票算法秒了

```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate, count = 0;
        for(auto num : nums) {
            if(count == 0) candidate = num;
            if(num == candidate) count++;
            else count--;
        }
        return candidate;
    }
};
```

### 229. 多数元素 II

[229. 多数元素 II](https://leetcode.cn/problems/majority-element-ii/)

给定一个大小为 *n* 的整数数组，找出其中所有出现超过 `⌊ n/3 ⌋` 次的元素。

![image-20230716162130453](https://typorapic.oss-cn-shenzhen.aliyuncs.com/image-20230716162130453.png)

解题思路：

与上面那道题不同的是，这道题可能会出现两个不同的多数元素，可以这样设想，这次需要投票选举出一位或者两位候选人，而每位候选人的票数只要大于总人数的三分之一即可。

基于摩尔投票算法的核心思想，这道题可以这么写：

+ 我们每次检测当前元素是否为第一个选中的元素或者第二个选中的元素。

+ 每次我们发现当前元素与已经选中的两个元素都不相同，则将两个候选元素都进行抵消一次，因为当三个元素互不相同时会被抵消，最终只剩下1个元素。

+ 如果存在最终选票大于 0 的元素，我们还需要再次统计已选中元素的次数,检查元素的次数是否大于$ \lfloor\frac{n}{3}\rfloor $。

```c++
class Solution {
public:
    static const int inf = INT_MAX;
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int candidate1 = 0, count1 = 0, candidate2 = inf, count2 = 0;
        for(auto num : nums) {  // 第一次遍历，寻找两个候选元素
            if(count1 == 0 && num != candidate2) candidate1 = num; // 设置第一个候选元素
            else if(count2 == 0 && num != candidate1) candidate2 = num; // 设置第二个候选元素
            if(num == candidate1) count1++; // 如果当前元素等于候选元素1，票数加1
            else if(num == candidate2) count2++; // 如果当前元素等于候选元素2，票数加1
            else { // 与候选元素1、2对抗，票数减1
                count1--;
                count2--;
            }
        }
        int sum1 = 0, sum2 = 0;
        for(auto i : nums) { // 第二次遍历，统计两个候选元素的出现次数
            if(candidate1 == i) sum1++;
            if(candidate2 == i) sum2++;
        }
        if(sum1 > nums.size() / 3) ans.push_back(candidate1);
        if(sum2 > nums.size() / 3) ans.push_back(candidate2);
        return ans;
    }
};
```

### 6927. 合法分割的最小下标

[6927. 合法分割的最小下标](https://leetcode.cn/problems/minimum-index-of-a-valid-split/)

如果元素 x 在长度为 m 的整数数组 arr 中满足 $freq(x) * 2 > m$ ，那么我们称 x 是 支配元素 。其中 $freq(x)$ 是 $x$ 在数组 arr 中出现的次数。注意，根据这个定义，数组 arr 最多 只会有 一个 支配元素。

给你一个下标从 0 开始长度为 n 的整数数组 nums ，数据保证它含有一个支配元素。

你需要在下标 i 处将 nums 分割成两个数组 nums[0, ..., i] 和 nums[i + 1, ..., n - 1] ，如果一个分割满足以下条件，我们称它是 合法 的：

+ 0 <= i < n - 1
+ nums[0, ..., i] 和 nums[i + 1, ..., n - 1] 的支配元素相同。

这里， nums[i, ..., j] 表示 nums 的一个子数组，它开始于下标 i ，结束于下标 j ，两个端点都包含在子数组内。特别地，如果 j < i ，那么 nums[i, ..., j] 表示一个空数组。

请你返回一个 合法分割 的 最小 下标。如果合法分割不存在，返回 -1 。

![image-20230716164409930](https://typorapic.oss-cn-shenzhen.aliyuncs.com/image-20230716164409930.png)

解题思路：

摩尔投票算法求解出整个数组的支配元素，然后遍历数组，找到下标i，使得从该下标分割数组让两个子数组的合法。

```c++
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        // 找到支配元素
        int count = 0, sum = 0;
        int candidate = 0;
        for (auto num : nums) {
            if (count == 0) candidate = num;
            count += (num == candidate) ? 1 : -1;
        }
        for(auto i : nums) if(i == candidate) sum++;
        // cout << candidate << endl;
        // 遍历找到分割点
        int leftcount = 0, rightcount = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == candidate) {
                leftcount++;
                rightcount = sum - leftcount;
                if(leftcount * 2 > i + 1 && rightcount * 2 > nums.size() - i - 1) {
                    // cout << leftcount << " " << rightcount << endl;
                    return i;
                }
            }
        }
        return -1;
    }
};
```

