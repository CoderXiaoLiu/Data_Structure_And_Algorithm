#include<bits/stdc++.h>
using namespace std;
typedef struct LNode { //定义单链表结点类型
    int data;
    struct LNode *next;
}LNode, *LinkList;
int n, a[10010] = {0};
LinkList L1, L2; //L1为不带头结点的链表，L2为带头结点的链表
LinkList create_link1(LinkList &L) { //采用尾插法创建一个不带头结点单链表
    L = (LinkList) malloc (sizeof(LNode));
    LNode *s, *r = L;
    scanf("%d", &a[0]);
    L -> data = a[0];
    for(int i = 1; i < n; i++) {
        scanf("%d", &a[i]);
        s = (LNode *) malloc (sizeof(LNode));
        s -> data = a[i];
        r -> next = s;
        r = s;
    }
    r -> next = NULL;
    return L;
}
LinkList create_link2(LinkList &L) { //采用尾插法创建一个带头结点单链表
    L = (LinkList) malloc (sizeof(LNode));
    LNode *s, *r = L;
    for(int i = 0; i < n; i++) {
        s = (LNode *) malloc (sizeof(LNode));
        s -> data = a[i];
        r -> next = s;
        r = s;
    }
    r -> next = NULL;
    return L;
}
LinkList Swap1(LinkList &L) { //对不带头结点的链表进行操作
    LNode * s, *pre = L, *p = L -> next;
    if(p -> data % 2 == 1 && pre -> data% 2 == 0) {
        swap(p -> data, pre -> data); //如果前两个元素奇数结点在第二个位置，直接交换两结点data值即可
    }
    while (p != NULL)
    {
        if(p -> data % 2 == 0) {
            p = p -> next;
            pre = pre -> next;
        } else {
            pre -> next = p -> next; //修改该奇数结点的前一个结点的后继结点
            s = p;
            s -> next = L;
            L = s; //将奇数结点移动到链表的第一个位置
            //cout << L -> data << endl;
            p = pre -> next;
            //cout << pre -> data << endl;
        }
    }
    return L;
}
LinkList Swap2(LinkList &L) { //对带头结点的链表进行操作
    LNode *s, *r, *pre = L -> next, *p = pre -> next;
    if(p -> data % 2 == 1 && pre -> data% 2 == 0) {
        swap(p -> data, pre -> data); //如果前两个元素奇数结点在第二个位置，直接交换两结点data值即可
    }
    while (p != NULL)
    {
        if(p -> data % 2 == 0) {
            p = p -> next;
            pre = pre -> next;
        } else {
            pre -> next = p -> next; //修改该奇数结点的前一个结点的后继结点
            s = p;
            r = L -> next;
            s -> next = r;
            L -> next = s; //将奇数结点移动到链表的第一个位置
            //cout << L -> data << endl;
            p = pre -> next;
            //cout << pre -> data << endl;
        }
    }
    return L;
}
int main() {
    scanf("%d", &n);
    L1 = create_link1(L1);
    L2 = create_link2(L2);
    L1 = Swap1(L1);
    L2 = Swap2(L2);
    while (L1 != NULL)
    {
        cout << L1 -> data << " ";
        L1 = L1 -> next;
    }
    cout << endl;
    L2 = L2 -> next;
    while (L2 != NULL)
    {
        cout << L2 -> data << " ";
        L2 = L2 -> next;
    }
    return 0;
}
/*
测试样例1：
10
1 2 3 4 5 6 7 8 9 10
测试样例2：
15
8 99 21 12 445 55 123 456 78 12 22 31 488 1537 16
测试样例3：
10
1 3 5 7 9 2 4 8 8 10
测试样例4：
10
98 46 264 4544 152 159 795 13 1577 15795
*/