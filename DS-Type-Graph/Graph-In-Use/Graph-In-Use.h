//
// Created by P7XXTM1-G on 2021-12-16.
//

#ifndef HELLO_C_GRAPH_IN_USE_H
#define HELLO_C_GRAPH_IN_USE_H

#include <stdio.h>
#include <stdlib.h>

#include "Status/Status.h"
#include "../MatrixGraph/MatrixGraph.h"
#include "../AdjacencyListGraph/AdjacencyListGraph.h"
#include "../DS-Type-Link/LinkQueue/LinkQueue.h"

Status isReachable_DFS(MatrixGraph graph, int s, int t);

void ShortestPathLength_BFS(ALGraph graph, int s, int *p);

#endif //HELLO_C_GRAPH_IN_USE_H
