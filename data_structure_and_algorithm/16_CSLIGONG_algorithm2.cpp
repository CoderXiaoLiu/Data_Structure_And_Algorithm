#include<bits/stdc++.h>
using namespace std;
typedef struct BitNode{
    char data;
    struct BitNode *lchild, *rchild;
}BitNode, *BiTree;
void build_tree(BiTree &bt) { // 建树,用先序遍历的思想建立二叉树
    char ch;
    scanf("%c", &ch);
    if(ch == '#') {
        bt = NULL;
    } else {
        bt = (BitNode *) malloc (sizeof(BitNode));
        bt -> data = ch;
        build_tree(bt -> lchild);
        build_tree(bt -> rchild);
    }
}
void preorder(BiTree bt) { // 先序遍历
    if(bt == NULL) return;
    printf("%c", bt->data);
    preorder(bt->lchild);
    preorder(bt->rchild);
}
void inorder(BiTree bt) { // 中序遍历
    if(bt == NULL) return;
    inorder(bt->lchild);
    printf("%c", bt->data);
    inorder(bt->rchild);
}
void postorder(BiTree bt) { // 后序遍历
    if(bt == NULL) return;
    postorder(bt->lchild);
    postorder(bt->rchild);
    printf("%c", bt->data);
}
void freeTree(BiTree bt) { // 销毁二叉树
    if(bt == NULL) return;
    freeTree(bt->lchild);
    freeTree(bt->rchild);
    free(bt);
}
int main() {
    BiTree T;
    build_tree(T);
    preorder(T);
    cout << endl;
    inorder(T);
    cout << endl;
    postorder(T);
    cout << endl;
    freeTree(T);
    return 0;
}
/*
测试样例：
ABD###CE##F##
        A
       / \
      B   C
     /   / \
    D   E   F
*/