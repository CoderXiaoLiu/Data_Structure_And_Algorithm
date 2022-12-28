#include<bits/stdc++.h>
using namespace std;
typedef struct Tree {
    int data;
    int level; // 结点所在的层数
    struct Tree *lchild, *rchild;
}bstnode, *bstree;
int n, a[1010];
int height = 0; //树高
int sum1 = 0, sum2 = 0;
void BST_insert(bstree &T, int k, int cnt) {
    height = max(height, cnt);
    if(T == NULL) {
        T = (bstree) malloc (sizeof(bstnode));
        T -> data = k;
        T -> level = cnt;
        T -> lchild = T -> rchild = NULL;
    }
    else if(k <= T -> data) BST_insert(T -> lchild, k, cnt + 1);
    else BST_insert(T -> rchild, k, cnt + 1);
}
void Create_BST(bstree &T) {
    T = NULL;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        BST_insert(T, a[i], 1);
    }
}
void inorder(bstree T) {
    if(T == NULL) return;
    inorder(T -> lchild);
    //cout << T -> data << " ";
    if(T -> level == height) sum1++;
    if(T -> level == height - 1) sum2++;
    inorder(T -> rchild);
}
int main() {
    bstree tree;
    Create_BST(tree);
    inorder(tree);
    printf("%d + %d = %d", sum1, sum2, sum1 + sum2);
    return 0;
}