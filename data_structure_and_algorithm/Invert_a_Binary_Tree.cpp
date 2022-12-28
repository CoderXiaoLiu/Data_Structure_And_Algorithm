#include<bits/stdc++.h>
using namespace std;
struct binary_tree
{
    int data;
    int lchild, rchild;
}node[15];
int n;
bool visited[15] = {false};
int build_tree() {
    scanf("%d", &n);
    char left, right;
    for(int i = 0; i < n; i++) {
        node[i].data = i;
        cin >> left >> right;
        if(left == '-') node[i].lchild = -1;
        else {
            node[i].lchild = (left - '0');
            visited[left - '0'] = true;
        }
        if(right == '-') node[i].rchild = -1;
        else {
            node[i].rchild = (right - '0');
            visited[right - '0'] = true;
        }
    }
    for(int i = 0; i < n; i++) { //返回根节点
        if(!visited[i]) return i;
    }
}
void invert(int k) { //递归地交换左、右子树
    if(k == -1) return;
    invert(node[k].lchild);
    invert(node[k].rchild);
    swap(node[k].lchild, node[k].rchild);
}
void levelorder(int root) { //层序遍历
    queue<binary_tree>q;
    q.push(node[root]); // 根节点入队
    vector<int> ans;
    while(!q.empty()) {
        binary_tree top = q.front();
        q.pop();
        ans.push_back(top.data);
        if(top.lchild != -1) q.push(node[top.lchild]);
        if(top.rchild != -1) q.push(node[top.rchild]);
    }
    printf("%d", ans[0]);
    for(int i = 1; i < ans.size(); i++) printf(" %d", ans[i]);
    puts("");
}
vector<int>inorder_ans; //为了保证输出最后一个节点时不输出额外的空格，先用数组把答案存下来
void inorder(int k) { //中序遍历
    if(k == -1) return;
    inorder(node[k].lchild);
    inorder_ans.push_back(node[k].data);
    inorder(node[k].rchild);
}
void print_inorder() { //打印中序遍历序列
    printf("%d", inorder_ans[0]);
    for(int i = 1; i < inorder_ans.size(); i++) printf(" %d", inorder_ans[i]);
}
int main() {
    int root = build_tree();
    // for(int i = 0; i < n; i++) {
    //     cout << node[i].lchild << " " << node[i].rchild << endl;
    // }
    // cout << endl;
    invert(root);
    // for(int i = 0; i < n; i++) {
    //     cout << node[i].lchild << " " << node[i].rchild << endl;
    // }
    levelorder(root);
    inorder(root);
    print_inorder();
    return 0;
}