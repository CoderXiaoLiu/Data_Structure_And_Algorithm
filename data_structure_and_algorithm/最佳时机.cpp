/*
首先定义变量 Max 和 Min，分别表示当前可获得的最大收益和记录前 i 天的最低价。
通过一个 for 循环遍历数组 prices 中的元素，更新 Max 和 Min 的值。
如果当前价格大于前 i 天中的最低价，则可以计算出当前可获得的最大收益，并将其与之前的最大收益 Max 取较大值。
否则，将 Min 更新为当前价格，因为当前价格可能成为接下来几天的最低价。
最后返回 Max 的值，如果所有价格都是递减的，则 Max 为 -1，需要特判一下，将其转为 0 返回。
*/
#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices) {
    int Max = -1, Min = prices[0];
    for(int i = 1; i < prices.size(); i++) {
        if(prices[i] > Min) Max = max(Max, prices[i] - Min);
        else Min = prices[i];
    }
    return max(Max, 0);
}
int main() {
    int n, x;
    scanf("%d", &n);
    vector<int>v;
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        v.push_back(x);
    }
    printf("%d", maxProfit(v));
    return 0;
}
/*
6
7 1 5 3 6 4
*/