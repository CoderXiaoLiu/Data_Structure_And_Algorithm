#include<bits/stdc++.h>
using namespace std;
const int maxn = 30002;
int father[maxn];
int sum[maxn];
void init() {
    for(int i= 0; i < maxn; i++) {
        father[i] = i;
        sum[i] = 1;
    }
}
int findFather(int v) {
    if(v == father[v]) return v;
    return findFather(father[v]);
}
void merge(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB) {
        father[faA] = faB;
        sum[faB] += sum[faA];
    }
}
int main() {
    init();
    int t;
    scanf("%d", &t);
    while(t--) {
        char op;
        cin >> op;
        int x, y;
        if(op == 'M') {
            scanf("%d%d", &x, &y);
            merge(x, y);
        } else {
            scanf("%d", &x);
            int fx = findFather(x);
            printf("%d\n", sum[fx] - sum[x]);
        }
    }
    return 0;
}
/*
6
M 1 6
C 1
M 2 4
M 2 6
C 3
C 4
*/