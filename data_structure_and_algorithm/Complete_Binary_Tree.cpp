#include<bits/stdc++.h>
using namespace std;
struct Complete_Binary_Tree
{
    int data;
    int lchild, rchild;
}node[25];
int n;
bool visited[25] = {false};
int turn(string s) {
    int sum = 0;
    for(auto &i:s) sum = sum * 10 + (i - '0');
    return sum;
}
int build_tree() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        string left, right;
        cin >> left >> right;
        node[i].data = i;
        if(left == "-") node[i].lchild = -1;
        else {
            node[i].lchild = turn(left);
            visited[node[i].lchild] = true;
        }
        if(right == "-") node[i].rchild = -1;
        else {
            node[i].rchild = turn(right);
            visited[node[i].rchild] = true;
        }
    }
    for(int i = 0; i < n; i++) {
        if(!visited[i]) return i;//返回根节点
    }
}
int last_node = 0;
bool iscomplete(int root) {
    queue<int>q;
    if(n == 0) return true; // 空树为满二叉树
    q.push(root);
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        if(top != -1) last_node = top;
        if(top != -1) {
            q.push(node[top].lchild);
            q.push(node[top].rchild);
        } else { // 结点为空，检查其后是否有非空结点
            while(!q.empty()) {
                int temp = q.front();
                q.pop();
                if(temp != -1) return false; // 结点非空，则二叉树为非完全二叉树
            }
        }
    }
    return true;
}
int main() {
    int root = build_tree();
    // for(int i = 0; i < n; i++) cout << node[i].lchild << " " << node[i].rchild << endl;
    // cout << root << endl;
    if(iscomplete(root)) printf("YES %d", last_node);
    else printf("NO %d", root);
    return 0;
}