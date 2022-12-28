#include<bits/stdc++.h>
using namespace std;
struct Infix_Expression
{
    string data;
    int lchild, rchild;
}node[25];
int n, root;
bool visited[25] = {false};
int build_tree() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        cin >> node[i].data >> node[i].lchild >> node[i].rchild;
        if(node[i].lchild != -1) visited[node[i].lchild] = true;
        if(node[i].rchild != -1) visited[node[i].rchild] = true;
    }
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) return i;
    }
}
void inorder(int k) {
    if(k == -1) return;
    if(k != root && (node[k].lchild != -1 || node[k].rchild != -1)) cout << "(";
    inorder(node[k].lchild);
    cout << node[k].data;
    //cout << node[k].data << " ";
    inorder(node[k].rchild);
    if(k != root && (node[k].lchild != -1 || node[k].rchild != -1)) cout << ")";
}
int main() {
    root = build_tree();
    //for(int i = 1; i <= n; i++) cout << node[i].lchild << " " << node[i].rchild << endl;
    //for(int i = 1; i <= n; i++) cout << visited[i] << endl;
    inorder(root);
    return 0;
}