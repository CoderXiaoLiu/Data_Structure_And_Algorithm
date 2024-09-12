/*
你正在为一个社交网络平台开发好友推荐功能。
平台上有N个用户(每个用户使用1到N的整数编号)，同时系统中维护了用户之间的好友关系。
为了推荐新朋友，平台决定采用“共同好友数量"作为衡量两个用户之间相似度的标准。
系统根据输入用户编号K，输出与此用户K相似度最高的前L个用户ID来推荐给用户K。
相似度定义:两个用户非好友，两个用户的相似度为拥有的共同好友数(例如用户A和用户B，只有共同好友C和D，相似度=2)
*/
#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second) return a.second > b.second;
    return a.first < b.first;
}
int main() {
    int N, M, K, L;
    scanf("%d %d %d %d", &N, &M, &K, &L);
    int x, y;
    int isf[1025][1025] = {0};
    for(int i = 0; i < M; i++) {
        scanf("%d%d", &x, &y);
        isf[x][y] = isf[y][x] = 1;
    }

    vector < pair<int, int> > sim;

    for(int i = 1; i <= N; i++) {
        if(i == K) continue;
        if(isf[K][i] != 1) {
            int cnt = 0;
            for(int j = 1; j <= N; j++) {
                if(i == j) continue;
                if(isf[K][j] == 1 && isf[i][j] == 1) cnt++;
            }
            sim.push_back(make_pair(i, cnt));
        }
    }

    sort(sim.begin(), sim.end(), cmp);
    int sum = 0;
    for(auto i : sim) {
        printf("%d ", i.first);
        sum++;
    }
    if(sum < L) {
        for(int i = sum; i < L; i++) printf("0 ");
    }

    return 0;
}
