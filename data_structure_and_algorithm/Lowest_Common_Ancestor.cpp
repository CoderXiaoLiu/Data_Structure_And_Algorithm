//TLE
#include<bits/stdc++.h>
using namespace std;
const int maxn = 10010;
typedef struct BSTNode
{
    int data;
    struct BSTNode *lchild, *rchild;
}*BiTree, BSTNode;
void BST_insert(BiTree &T, int k) {
    if(T == NULL) {
        T = (BiTree) malloc (sizeof(BSTNode));
        T -> data = k;
        T -> lchild = T -> rchild = NULL;
    }
    else if(k < T->data) BST_insert(T -> lchild, k);
    else BST_insert(T -> rchild, k);
}
int n, t, a[maxn], LCA = -1, cnt = 0;
void build_tree(BiTree &T) {
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        BST_insert(T, a[i]);
    }
}
vector<int>path;
bool BST_Search_first(BiTree T, int key) {
    while (T != NULL && key != T->data) {
        path.push_back(T -> data);
        if(key < T->data) T = T -> lchild;
        else T = T -> rchild;
    }
    if(T == NULL) return false;
    else {
        path.push_back(T -> data);
        return true;
    }
}
bool BST_Search_second(BiTree T, int key) {
    while (T != NULL && key != T -> data)
    {
        if(cnt < path.size() && T -> data == path[cnt]) LCA = path[cnt++];
        if(key < T -> data) T = T -> lchild;
        else T = T -> rchild;
    }
    
    if(T == NULL) return false;
    else {
        if(cnt < path.size() && T -> data == path[cnt]) LCA = path[cnt++];
        return true;
    }
}
int main() {
    scanf("%d%d", &t, &n);
    BiTree tree = NULL;
    build_tree(tree);
    while(t--) {
        path.clear();
        cnt = 0;
        int a, b;
        scanf("%d%d", &a, &b);
        if(!BST_Search_first(tree, a) && !BST_Search_second(tree, b))
            printf("ERROR: %d and %d are not found.\n", a, b);
        else if(!BST_Search_first(tree, a)) 
            printf("ERROR: %d is not found.\n", a);
        else if(!BST_Search_second(tree, b))
            printf("ERROR: %d is not found.\n", b);
        else if(LCA == a)
            printf("%d is an ancestor of %d.\n", a, b);
        else if(LCA == b)
            printf("%d is an ancestor of %d.\n", b, a);
        else printf("LCA of %d and %d is %d.\n", a, b, LCA);
    }
    return 0;
}