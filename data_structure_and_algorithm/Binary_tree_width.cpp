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
int width1(BiTree bt) {
    if(bt == NULL) return 0;
    BiTree q[1000];
    int front, rear;
    front = rear = -1;
    int queuelength = 0, width = 1, last = 0;
    q[++rear] = bt;
    BitNode *p;
    while(front < rear) {
        p = q[++front];
        if(p -> lchild) {
            q[++rear] = p -> lchild;
            queuelength ++;
        }
        if(p -> rchild) {
            q[++rear] = p -> rchild;
            queuelength ++;
        }
        if(front == last) {
            width = max(width, queuelength);
            last = rear;
            queuelength = 0;
        }
    }
    return width;
}
int main() {
    BiTree T;
    create_tree(T);
    printf("%d", width1(T));
    
    return 0;
}