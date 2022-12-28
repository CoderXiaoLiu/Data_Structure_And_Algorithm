#include<bits/stdc++.h>
using namespace std;
const int MaxVertexNum = 100; // 图中顶点数目的最大值
typedef struct ArcNode { //边表结点
    int adjvex; // 该弧所指向的顶点的位置
    struct ArcNode *next; //指向下一条弧的指针
    // int weight; //网的边权值
    // Infotype info;
}ArcNode;
typedef struct VNode { //顶点表结点
    int data; //顶点信息 (VertexType data;)
    ArcNode *first; // 指向第一条依附该顶点的弧的指针
}VNode, AdjList[MaxVertexNum];
typedef struct {
    AdjList vertices; //邻接表
    int vexnum, arcnum; //图的顶点数和弧数
}ALGraph; // ALGraph是以邻接表存储的图类型
void Create_AdjList_Graph(ALGraph &G) { //创建一个邻接表
    scanf("%d%d", &G.vexnum, &G.arcnum); //输入图的顶点数和边数
    for(int i = 1; i <= G.vexnum; i++) {
        G.vertices[i].data = i; //假设顶点信息是1....vernum
        G.vertices[i].first = NULL; //初始化第一条依附该顶点的弧的指针为空
    }
    ArcNode *p;
    for(int i = 0; i < G.arcnum; i++) {
        int u, v;
        scanf("%d%d", &u, &v); //u, v表示u有一条边指向v;
        p = (ArcNode *) malloc (sizeof(ArcNode)); // p = new ArcNode;
        p -> adjvex = v;
        p -> next = G.vertices[u].first; //用头插法将v插到结点u的边表结点中
        G.vertices[u].first = p; // 插入后将第一条依附该顶点的弧的指针修改为p
    }
}
void adjacency_to_inverse_adjacency(ALGraph GOut, ALGraph &GIn) { 
    /*将图的邻接表转化为逆邻接表*/
    GIn.arcnum = GOut.arcnum; //初始化逆邻接表的边数目
    GIn.vexnum = GOut.vexnum; //初始化逆邻接表的顶点数目
    for (int i = 1; i <= GIn.vexnum; i++) { 
        GIn.vertices[i].data = GOut.vertices[i].data; // 初始化逆邻接表的顶点信息
        GIn.vertices[i].first = NULL; // 初始化指向第一条依附该顶点的弧的指针
    }
    for(int i = 1; i <= GOut.vexnum; i++) {
        ArcNode *p = GOut.vertices[i].first; // 取得指向第一条依附该顶点的弧的指针
        ArcNode *s;
        while(p != NULL) { // 遍历邻接表中第i个顶点所有邻接边 
            s = (ArcNode *) malloc (sizeof(ArcNode)); // or s = new ArcNode;
            int temp = p -> adjvex;
            s -> adjvex = i;
            s -> next = GIn.vertices[temp].first; //头插法将顶点i挂到GIn.vertices[temp]的边表中
            GIn.vertices[temp].first = s;
            p = p -> next; // 继续往后遍历i所指向的顶点
        }
    }
}
void print(ALGraph G) { // 打印邻接表
    for(int i = 1; i <= G.vexnum; i++) {
        printf("(%d) ", i);
        ArcNode *p = G.vertices[i].first;
        while(p) {
            printf("-> %d ", p -> adjvex);
            p = p -> next;
        }
        puts("");
    }
}
int main() {
    ALGraph GraphOut, GraphIn; // GraphOut为邻接表，GraphIn为逆邻接表
    Create_AdjList_Graph(GraphOut); // 构造邻接表
    cout << endl;
    print(GraphOut); //打印邻接表
    adjacency_to_inverse_adjacency(GraphOut, GraphIn);
    cout << endl;
    print(GraphIn); //打印逆邻接表
    system("pause");
    return 0;
}
/*
测试样例一：
6 8
1 2
1 4
4 2
2 5
5 4
3 5
3 6
6 6
测试样例二：
9 14
1 2
1 3
2 5
2 4
5 3
5 4
5 6
6 5
3 8
8 9
9 6
4 7
7 6
7 9
*/