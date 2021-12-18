//
// Created by P7XXTM1-G on 2021/11/27.
//

#include "AdjacencyListGraph.h"

// 求第一个邻接顶点
int FirstAdjVex_AL(ALGraph graph, int k, AdjVexNodeP *p) {

    // k顶点不存在
    if (k < 0 || k >= graph.vexNum) {
        return -1;
    }

    // 令指针p 指向 k顶点对应邻接链表的第一个结点
    p = &graph.vexs[k].firstArc;

    // 若图中k顶点的邻接链表非空，则令指针p指向第一个结点，并返回其存储的邻接顶点位序
    // 【否则】令指针p为NULL，并返回-1
    if (p != NULL) {
        // 返回第一个结点存储的顶点位序
        return (*p)->adjVex;
    } else {
        // k顶点无邻接顶点
        return -1;
    }
}

// 求下一个邻接顶点
int NextAdjVex_AL(ALGraph graph, int k, AdjVexNodeP *p) {

    // k顶点不存在
    if (k < 0 || k >= graph.vexNum) {
        return -1;
    }

    // 指针p为空
    if (p == NULL) {
        return -1;
    }

    // 在k顶点的邻接链表中，令p指向下一个顶点
    p = &(*p)->nextArc;

    // 若p非空，返回存储在p结点中的下一个邻接顶点的位序，否则返回-1
    if (*p != NULL) {
        return (*p)->adjVex;
    } else {
        // k顶点无下一个邻接顶点
        return -1;
    }
}

// 求k顶点的所有邻接顶点
Status visitAllAdjVex(ALGraph graph, int k, Status(*visit)(int)) {
    int i;
    AdjVexNodeP p = NULL;

    if (k < 0 || k >= graph.vexNum) {
        return ERROR;
    }

    for (i = FirstAdjVex_AL(graph, k, &p); i >= 0; i = NextAdjVex_AL(graph, k, &p)) {
        if (visit(i) == ERROR) {
            return ERROR;
        }
    }

    return OK;
}

// [2019.829] 算法填空题3
// 从k顶点出发对连通图G进行深度优先遍历
void DFS_From_K_Node_AL(ALGraph graph, int k) {
    AdjVexNodeP p;

    printf("%c", graph.vexs[k]);

    graph.tags[k] = VISITED;

    for (p = graph.vexs[k].firstArc; p != NULL; p = p->nextArc) {
        if (graph.tags[p->adjVex] == UNVISITED) {
            DFS_From_K_Node_AL(graph, p->adjVex);
        }
    }
}

// 广度优先遍历
Status BFSTraverse_AL(ALGraph graph, Status (*visit)(int)) {
    int i, j, k;
    AdjVexNodeP p;

    LinkQueue queue;

    // 初始化访问队列
    InitQueue_LQ(&queue);

    // 初始化标志数组
    for (i = 0; i < graph.vexNum; i++) {
        graph.tags[i] = UNVISITED;
    }

    // 依次检查所有顶点
    for (i = 0; i < graph.vexNum; i++) {
        // 顶点i 未被访问
        if (graph.tags[i] == UNVISITED) {
            if (visit(i) == ERROR) {
                return ERROR;
            }

            // 访问 i顶点，入队
            graph.tags[i] = VISITED;
            EnQueue_LQ(&queue, i);

            // 出队元素赋值到k
            while (DeQueue_LQ(&queue, &k)) {
                for (j = FirstAdjVex_AL(graph, k, &p); j >= 0; j = NextAdjVex_AL(graph, k, &p)) {
                    // 依次判断 k顶点的所有邻接顶点j
                    if (graph.tags[j] == UNVISITED) {
                        // 若未曾访问
                        if (visit(j) == ERROR) {
                            return ERROR;
                        }

                        // 访问并入队
                        graph.tags[j] = VISITED;
                        EnQueue_LQ(&queue, j);
                    }
                }
            }
        }
    }

    return OK;
}