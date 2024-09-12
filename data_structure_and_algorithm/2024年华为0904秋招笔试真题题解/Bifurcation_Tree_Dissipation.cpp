/*
给定原始二叉树和参照二叉树(输入的二叉树均为满二叉树，二叉树节点的值范围为[1,1000]，二叉树的深度不超过1000)，
现对原始二叉树和参照二叉树中相同层级目值相同的节点进行消除、
消除规则为原始叉树和参照二叉树中存在多个值相同的节点只能消除等数量的、消除后的节点变为无效节点，
请按节点值出现频率从高到低输出消除后原始二叉树中有效节点的值(如果原始二叉树消除后没有有效节点返回0)。
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 100001;
int n, m;
int origin[maxn], refer[maxn];
vector<int>sum(maxn, 0);

void dfs(int depth) {
    int start = pow(2, depth - 1), end = start + pow(2, depth - 1);
    if(start > n || start > m) return;
    map<int, int>mp1, mp2;
    for(int i = start; i < end; i++) {
        mp1[origin[i]]++;
        mp2[refer[i]]++;
    }
    for(auto i : mp1) {
        if(mp2[i.first] > i.second) sum[i.first] -= i.second;
        else sum[i.first] -= mp2[i.first];
        // cout << i.first << " " << sum[i.first] << endl;
    }
    mp1.clear();
    mp2.clear();
    dfs(depth + 1);
}

bool cmp(pair<int, int>a, pair<int, int> b) {
    if(a.second != b.second) return a.second > b.second;
    return a.first > b.first;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &origin[i]);
        sum[origin[i]]++;
    }
    scanf("%d", &m);
    for(int i = 1; i <= m; i++) scanf("%d", &refer[i]);

    dfs(1);

    // for(int i = 1; i <= n; i++) cout << sum[origin[i]] << " ";
    // cout << endl;

    vector<pair<int, int>>v;
    set<int>s;
    for(int i = 1; i <= n; i++) s.insert(origin[i]);
    for(auto i : s) v.push_back(make_pair(i, sum[i]));

    // for(auto i : s) cout << i << " " << sum[i] << " " << endl;

    sort(v.begin(), v.end(), cmp);
    bool flag = false;
    for(auto i : v) {
        if(i.second != 0) {
            flag = true;
            printf("%d", i.first);
        } 
        else break;
    }
    if(!flag) printf("0");

    return 0;
}
/*
15
5 8 8 8 7 7 7 6 6 9 9 7 7 5 6
7
5 6 6 7 7 8 8
*/