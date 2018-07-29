#include <stdio.h>

// Prim 算法生成最小生成树
void MiniSpanTree_Prim(MGraph G)
{
    int min, i, j, k;
    int adjvex[MAXVEX]; // 保存相关顶点下标
    int lowcost[MAXVEX]; // 保存相关顶点间边的权值

    lowcost[0] = 0; // V0 作为最小生成树的根开始遍历 权值为0
    adjvex[0] = 0; // V0 第一个加入

    for ( i=1; i < G.numVertexes; i++)
    {
        lowcost[i] = G.arc[0][i]; // 将邻接矩阵第0行
        adjvex[i] = 0;  // 初始化全部先为V0的下标
    }

    for ( i=1; i < G.numVertexes;i ++)
    {
        min = INFINITY;
        j = 1;
        k = 0;

        while ( j < G.numVertexes)
        {
            // 找出lowcost与 这个权值最小的边
            if ( lowcost[j]!=0 && lowcost[j] < min)
            {
                min = lowcost[j];
                k = j;
            }
            j ++;

        }

        printf("(%d,%d)", adjvex[k], k);
        lowcost[k] = 0; // 0 代表这条边已经计算在内

        for ( j=1; j < G.numVertexes; j++)
        {
            // 找出与前面V0 结点 和 Vk节点权值较小的所有边
            if ( lowcost[j]!=0 && G.arc[k][j] < lowcost[j])
            {
                lowcost[j] = G.arc[k][j];
                adjvex[j] = k;// 记录k节点
            }
        }
    }
}

