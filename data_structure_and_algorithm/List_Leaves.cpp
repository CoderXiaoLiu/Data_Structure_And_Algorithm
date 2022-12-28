#include<bits/stdc++.h>
using namespace std;
struct List_Leaves {
    int data;
    int lchild, rchild;
}leaves[10];
int n;
bool book[10] = {false};
int build_tree() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        char a, b;
        cin >> a >> b;
        leaves[i].data = i;
        if(a != '-') {
            leaves[i].lchild = (a - '0');
            book[a - '0'] = true;
        }
        else leaves[i].lchild = -1;
        if(b != '-') {
            leaves[i].rchild = (b - '0');
            book[b - '0'] = true;
        }
        else leaves[i].rchild = -1;
    }
    for(int i = 0; i < n; i++) if(!book[i]) return i;
}
vector<int>ans;
void levelorder(int root) {
    queue<List_Leaves>q;
    q.push(leaves[root]);
    while(!q.empty()) {
        List_Leaves top = q.front();
        q.pop();
        if(top.lchild == -1 && top.rchild == -1) ans.push_back(top.data);
        if(top.lchild != -1) q.push(leaves[top.lchild]);
        if(top.rchild != -1) q.push(leaves[top.rchild]);
    }
}
int main() {
    int root = build_tree();
    //for(int i = 0; i < n; i++) cout << leaves[i].lchild << " " << leaves[i].rchild << endl;
    levelorder(root);
    for(int i = 0; i< ans.size(); i++) {
        if(i != ans.size() - 1) printf("%d ", ans[i]);
        else printf("%d", ans[i]);
    }
    return 0;
}