#include<bits/stdc++.h>
using namespace std;
#define MaxVertexNum 10  /* maximum number of vertices */
typedef int Vertex;      /* vertices are numbered from 0 to MaxVertexNum-1 */

typedef struct AdjVNode *PtrToAdjVNode, AdjVNode; 
struct AdjVNode{
    Vertex AdjV;
    PtrToAdjVNode Next;
};

typedef struct Vnode{
    PtrToAdjVNode FirstEdge;
} AdjList[MaxVertexNum];

typedef struct GNode *PtrToGNode, GNode;
struct GNode{  
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToGNode LGraph;

LGraph ReadG() {
    int n, m, u, v;
    scanf("%d%d", &n, &m);
    LGraph Graph;
    Graph = (LGraph) malloc (sizeof(GNode));
    Graph->Nv = n, Graph->Ne = m;
    for(int i = 0; i < n; i++) {
        Graph->G[i].FirstEdge = NULL;
    }
    AdjVNode *p, *q;
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        p = (AdjVNode *) malloc (sizeof(AdjVNode));
        p -> AdjV = v;
        p -> Next = Graph->G[u].FirstEdge;
        Graph->G[u].FirstEdge = p; 

        q = (AdjVNode *) malloc (sizeof(AdjVNode));
        q -> AdjV = u;
        q -> Next = Graph->G[v].FirstEdge;
        Graph->G[v].FirstEdge = q; 
    }
    return Graph;
}

int CountConnectedComponents( LGraph Graph );

void print(LGraph Graph) {
    for(int i = 0; i < Graph->Nv; i++) {
        printf("(%d) ->", i);
        AdjVNode *p = Graph->G[i].FirstEdge;
        while(p) {
            printf("%d->", p->AdjV);
            p = p->Next;
        }
        cout << endl;
    }
}
int main()
{
    LGraph G = ReadG();
    print(G);
    printf("%d\n", CountConnectedComponents(G));
    
    return 0;
}

/* Your function will be put here */
const int Maxsize = 50; // 定义队列中元素的最大个数
typedef struct {
    int data[Maxsize]; // 存放队列元素
    int front, rear; // 队头指针和队尾指针
}SqQueue;
void InitQueue(SqQueue &Q) {
    Q.rear = Q.front = 0; // 初始化队首队尾指针
}
bool isEmpty(SqQueue Q) {
    return Q.rear == Q.front; //队空条件
}
bool EnQueue(SqQueue &Q, int x) {
    if((Q.rear+1)%Maxsize == Q.front) return false; //队满则报错
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear+1)%Maxsize; //队尾指针加一取模
    return true;
}
bool DeQueue(SqQueue &Q, int &x) {
    if(Q.rear == Q.front) return false; // 队空则报错
    x = Q.data[Q.front];
    Q.front = (Q.front+1) % Maxsize; //队头指针加一取模
    return true;
}


bool visited[100]; //访问标记数组
SqQueue Q;
void bfs(LGraph Graph, int v) { // 从顶点v出发，广度优先遍历图G
    visited[v] = true; //对v做已访问标记
    EnQueue(Q, v); //顶点V入队列
    while (!isEmpty(Q))
    {
        DeQueue(Q, v); //顶点v出队
        PtrToAdjVNode p = Graph->G[v].FirstEdge;
        while(p != NULL) { //检测v所有邻接点
            int w = p -> AdjV; 
            if(!visited[w]) { //w为v的尚未访问的邻接顶点
                visited[w] = true; //对w做已访问标记
                EnQueue(Q, w); // 顶点w入队列
            }
            p = p->Next;
        }
    }
    
}
int CountConnectedComponents( LGraph Graph ) {
    for(int i = 0; i < Graph->Nv; i ++) visited[i] = false; //对标记数组初始化
    InitQueue(Q); // 初始化辅助队列
    int sum = 0;
    for(int i = 0; i < Graph->Nv; i++) { //从0号顶点开始遍历
        if(!visited[i]) { //对每个连通分量调用一次bfs
            bfs(Graph, i); //vi未访问过，从vi开始bfs
            sum++;
        }
    }
    return sum;
}
/*
8 6
0 7
0 1
2 0
4 1
2 4
3 5
*/