/*
假设二叉树采用二叉链表作为存储结构，设计一个算法，求非空二叉树b的宽度
（即具有结点数最多的那一层的结点个数）
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
const int Maxsize = 100;
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
int max_width(BiTree bt) {
    if(bt == NULL) return 0; // 空树，最大宽度为0
    BiTree q[Maxsize];
    int front, rear;
    front = rear = -1;
    int queueLength = 0, last = 0, width = 0;
    // queueLength用于记录每一层的结点数，width记录二叉树的最大宽度
    // last记录每一层的最后一个结点
    q[++rear] = bt; // 根节点入队
    BitNode *p;
    while(front < rear) {
        p = q[++front];
        queueLength ++;
        if(p -> lchild != NULL) q[++rear] = p -> lchild;
        if(p -> rchild != NULL) q[++rear] = p -> rchild;
        if(front == last) {
            last = rear;
            if(queueLength > width) width = queueLength;
            queueLength = 0;
        }
    }
    return width;
}
int main() {
    BiTree T;
    build_tree(T);
    printf("%d\n", max_width(T));
    return 0;
}
/*
测试样例一：
ABD###CE##F##
        A
       / \
      B   C
     /   / \
    D   E   F
测试样例二：
ABDG##H###CE#I##F##
             A
            / \
           B   C
          /   / \
         D   E   F
        / \   \  
       G   H   I
*/