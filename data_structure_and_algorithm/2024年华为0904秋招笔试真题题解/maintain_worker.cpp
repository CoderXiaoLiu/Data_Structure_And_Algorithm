#include<bits/stdc++.h>
using namespace std;

double cal_dis(int x1, int y1, int x2, int y2) {
    return (double)sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

const int maxn = 2001;
int n, k, cx, cy;

struct customer
{
    int x, y, level;
    bool operator < (const customer& other) const { 
        return level < other.level; 
    }
}p[maxn];

/*
记忆化搜索，假设memo[i][j]表示维修完第i个客户，并且背包中还剩下j个设备。
*/
vector <vector<double>> memo(maxn, vector<double>(maxn, 0)); 

double dfs(int i, int j) {
    if(memo[i][j] > 0) return memo[i][j];
    double dis = cal_dis(p[i].x, p[i].y, cx, cy);
    double ans = 99999999999.0;
    if(i < n - 1) {
        ans = min(ans, dfs(i + 1, k - 1) + dis + cal_dis(p[i + 1]. x, p[i + 1].y, cx, cy));
        // cout << dis + cal_dis(p[i + 1]. x, p[i + 1].y, cx, cy) << endl;
        if(j > 0) {
            ans = min(ans, dfs(i + 1, j - 1) + cal_dis(p[i + 1].x, p[i + 1].y, p[i].x, p[i].y));
            // cout <<  cal_dis(p[i + 1].x, p[i + 1].y, p[i].x, p[i].y) << endl;
        }
    } else { // 如果是最后一家，则修完直接回公司
        ans = dis;
    }
    return memo[i][j] = ans;
}

int main() {
    scanf("%d%d", &n, &k);
    scanf("%d%d", &cx, &cy);
    for(int i = 0; i < n; i++) scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].level);
    sort(p, p + n);

    dfs(0, k);

    double ans = dfs(0, k - 1) + cal_dis(p[0].x, p[0].y, cx, cy);
    printf("%.1f", ans);

    return 0;
}