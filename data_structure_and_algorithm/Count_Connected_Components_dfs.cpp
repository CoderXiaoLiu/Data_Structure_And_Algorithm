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
bool visited[MaxVertexNum]; // 访问标记数组
void dfs(LGraph Graph, int v) { // 从顶点v出发，深度优先遍历图
        PtrToAdjVNode p = Graph->G[v].FirstEdge;
        visited[v] = true; // 设已访问标记
        while(p != NULL) {
            int temp = p -> AdjV;
            if(!visited[temp]) { // temp为尚未访问的邻接顶点
                dfs(Graph, temp);
            }
            p = p -> Next;
        }
}
int CountConnectedComponents( LGraph Graph ){
    int sum = 0;
    for(int i = 0; i < Graph->Nv;i++) visited[i] = false; // 初始化已访问标记数据
    for(int i = 0; i < Graph->Nv; i++) { //对图进行深度优先遍历
        if(!visited[i]) {
            dfs(Graph, i);
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