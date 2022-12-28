#include<bits/stdc++.h>
using namespace std;
int n;
struct Node
{
    int data;
    int lchild, rchild;
}node[120];
int mp[120] = {0}, cnt = 0;
void build_tree() {
    int a, b;
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        node[i].lchild = a;
        node[i].rchild = b;
    }
}
void inorder(int k) {//中序遍历
    if(k == -1) return;
    inorder(node[k].lchild);
    mp[cnt++] = k;
    inorder(node[k].rchild);
}
void levelorder(int sum) {//层序遍历
    queue<Node>q;
    q.push(node[0]);//根节点入队
    while (!q.empty()) {
        Node qu = q.front();
        q.pop();
        if(sum < n - 1)printf("%d ", qu.data);
        else printf("%d", qu.data);
        if(qu.lchild != -1) q.push(node[qu.lchild]);
        if(qu.rchild != -1) q.push(node[qu.rchild]);
        sum++;
    }
}
int main() {
    scanf("%d", &n);
    build_tree();
    inorder(0);
    // for(int i = 0; i < n; i++) cout << mp[i] << " ";
    // cout << endl;
    int num[n+1];
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);
    sort(num, num + n);
    for(int i = 0; i < n; i++) {
        node[mp[i]].data = num[i];
    }
    levelorder(0);
    return 0;
}