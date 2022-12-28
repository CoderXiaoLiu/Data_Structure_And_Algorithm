#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;
typedef struct BSTNode
{
    int data;
    struct BSTNode *lchild, *rchild;  
}BSTNode, *BiTree;
int n, a[maxn];
void BST_Insert(BiTree &T, int k) {
    if(T == NULL) {
        T = (BiTree) malloc (sizeof(BSTNode));
        T -> data = k;
        T -> lchild = T -> rchild = NULL;
    }
    else if(k < T->data) BST_Insert(T -> lchild, k);
    else BST_Insert(T -> rchild, k);
}
int cnt1 = 0, cnt2 = 0;
bool flag_pre = true, flag_mirror = true;
bool visit(int a, int b) {
    return a == b;
}
void build_tree(BiTree &T) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        BST_Insert(T, a[i]);
    }
}
void preorder(BiTree T) {
    if(T != NULL && flag_pre) {
        flag_pre = visit(T -> data, a[cnt1++]);
        //cout << T -> data << " ";
        preorder(T -> lchild);
        preorder(T -> rchild);
    }
}
void preorder_mirror(BiTree T) {
    if(T != NULL && flag_mirror) {
        flag_mirror = visit(T -> data, a[cnt2++]);
        //cout << T -> data << " ";
        preorder_mirror(T -> rchild);
        preorder_mirror(T -> lchild);
    }
}
vector<int>ans;
void postorder(BiTree T) {
    if(T == NULL) return;
    postorder(T -> lchild);
    postorder(T -> rchild);
    ans.push_back(T -> data);
}
void postorder_mirror(BiTree T) {
    if(T == NULL) return;
    postorder_mirror(T -> rchild);
    postorder_mirror(T -> lchild);
    ans.push_back(T -> data);
}
void print() {
    printf("%d", ans[0]);
    int i = 1;
    while(i < ans.size()) printf(" %d", ans[i++]);
}
int main() {
    BiTree tree = NULL;
    build_tree(tree);
    preorder(tree);
    if(flag_pre) {
        puts("YES");
        postorder(tree);
        print();
        return 0;
    }
    preorder_mirror(tree);
    if(flag_mirror) {
        puts("YES");
        postorder_mirror(tree);
        print();
    }
    else puts("NO");
    return 0;
}