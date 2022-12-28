#include<bits/stdc++.h>
using namespace std;
struct tree
{
    string data;
    int lchild, rchild;
}a[25];
int n;
bool visited[25] = {false};
int buidl_tree() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        cin >> a[i].data >> a[i].lchild >> a[i].rchild;
        if(a[i].lchild != -1) visited[a[i].lchild] = true;
        if(a[i].rchild != -1) visited[a[i].rchild] = true;
    }
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) return i;//返回根节点
    }
}
void postorder(int node) {
    if(node == -1) return;
    if(a[node].lchild == -1 || a[node].rchild == -1) { //如果左子树或者右子树为空则先输出根节点
        cout << "(" << a[node].data;
        postorder(a[node].lchild);
        postorder(a[node].rchild);
        cout << ")";
    } else {
        cout << "(";
        postorder(a[node].lchild);
        postorder(a[node].rchild);
        cout << a[node].data << ")";
    }
}
int main() {
    int root = buidl_tree();
    postorder(root);
    return 0;
}