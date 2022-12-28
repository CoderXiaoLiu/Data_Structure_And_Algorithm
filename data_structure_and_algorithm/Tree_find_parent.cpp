#include<bits/stdc++.h>
using namespace std;
typedef struct BitNode {
    char data;
    struct BitNode *lchild, *rchild;
}BitNode, *BiTree;
void create_tree(BiTree &bt) {
    char ch;
    scanf("%c", &ch);
    if(ch == '#') bt = NULL;
    else {
        bt = (BiTree) malloc (sizeof(BitNode));
        bt -> data = ch;
        create_tree(bt -> lchild);
        create_tree(bt -> rchild);
    }
}
bool flag = false;
char parent = '#';
void find_parent(BiTree bt, char x) {
    if(bt == NULL || flag) return;
    if(bt -> lchild && bt -> lchild -> data == x) {
        parent = bt -> data;
        flag = true;
        return;
    }
    if(bt -> rchild && bt -> rchild -> data == x) {
        parent = bt -> data;
        flag = true;
        return;
    }
    find_parent(bt -> lchild, x);
    find_parent(bt -> rchild, x);
}
int main() {
    BiTree T;
    create_tree(T);
    char x;
    cin >> x;
    //flag = false, parent = '#';
    find_parent(T, x);
    printf("%c", parent);
    system("pause");
    return 0;
}