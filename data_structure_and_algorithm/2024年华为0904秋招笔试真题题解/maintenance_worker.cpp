/*
维修工要给n个客户更换设备，为每个用户更换一个设备。维修工背包内最多装k个设备，
如果背包里有设备可以直接前往下一个客户更换或回公司补充设备，没有则需要回公司取设备。
这些客户有优先级，维修工需要按照优先级给客户更换设备，优先级level用数字表示，数字小的优先级高。
维修工从公司出发，给n个客户更换设备，最后再返回公司。请计算维修工完成这项工作所需要经历的最短总距离是多少
*/
#include <bits/stdc++.h>
using namespace std;

// 计算距离
double calculate_distance(pair<int, int> point1, pair<int, int> point2) {
    double distance = sqrt(pow(point2.first - point1.first, 2) + pow(point2.second - point1.second, 2));
    return distance;
}

struct Point {
    int x, y, l;
    bool operator< (const Point& other) const { 
        return l < other.l; 
    }
};
double dp[2002][2002];
int main(){
    int n, k, x, y;
    cin >> n >> k;
    cin >> x >> y;
	for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=k; j++) dp[i][j] = -1;
    }
    vector<Point> points(n);
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y >> points[i].l;

    sort(points.begin(), points.end());  // 按照l字段排序

    function<double(int, int)> dfs = [&](int i, int j){
        if(dp[i][j] > 0) return dp[i][j];
        double dis = calculate_distance({points[i].x, points[i].y}, {x, y}); //当前点回到公司的距离
        double ans = numeric_limits<double>::max();
        if (i < n-1) { // 如果不是最后一个点
            ans = min(ans, dfs(i+1, k-1) + dis + calculate_distance({x,y}, {points[i+1].x, points[i+1].y}));
            if (j > 0)
                ans = min(ans, dfs(i+1, j-1) + calculate_distance({points[i].x, points[i].y}, {points[i+1].x, points[i+1].y}));
        } else ans = dis;
        dp[i][j] = ans;
        return ans;
    };

    double ans = dfs(0, k-1) + calculate_distance({x, y}, {points[0].x, points[0].y});
    printf("%.1f", ans);

    return 0;
}