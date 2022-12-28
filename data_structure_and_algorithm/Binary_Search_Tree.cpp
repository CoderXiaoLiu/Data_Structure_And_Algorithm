#include<bits/stdc++.h>
using namespace std;
typedef struct BSTNode{
    int data;
    struct BSTNode *lchild, *rchild;
}BSTNode, *BiTree;
void BST_insert(BiTree &T, int k) {
    if(T == NULL) {
        T = (BiTree) malloc (sizeof(BSTNode));
        T -> data = k;
        T -> lchild = T -> rchild = NULL;
    }
    else if(k < T -> data) BST_insert(T->lchild, k);
    else BST_insert(T->rchild, k);
}
int n, t, a[20];
bool flag;
void judge(BiTree T1, BiTree T2) {
    if(T1 == NULL && T2 == NULL) return;
    if(!flag) return;
    else if(T1 == NULL || T2 == NULL) {
        flag = false;
        return;
    }
    if(T1 -> data != T2 -> data) {
        flag = false;
        return;
    }
    judge(T1 -> lchild, T2 -> lchild);
    judge(T1 -> rchild, T2 -> rchild);
}
int main() {
    while (cin >> n)
    {
        if(n == 0) break;
        scanf("%d", &t);
        BiTree T = NULL;
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            BST_insert(T, a[i]);
        }
        while (t--)
        {
            flag = true;
            BiTree T2 = NULL;
            int x;
            for(int i = 0; i < n; i++) {
                scanf("%d", &x);
                BST_insert(T2, x);
            }
            judge(T, T2);
            if(flag) puts("Yes");
            else puts("No");
        }
        
    }
    
    return 0;
}