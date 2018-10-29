#pragma once
#ifndef ALGraph_H_
#define ALGraph_H_

#include <iostream>
#include <string>
#include <stdlib.h>
#define MAX_VERTEX_NUM 100
using namespace std;


// template <typename InfoType>
typedef char InfoType;
typedef struct ArcNode {
	int adjvex;
	struct ArcNode *next;
	InfoType * info;
}ArcNode;

// template <typename VertexType>
typedef int VertexType;
typedef struct VNode{
	VertexType data;
	ArcNode * firstarc;
}VNode, AdjList[MAX_VERTEX_NUM];

class ALGraph {
private:
	AdjList vertices;
	int vexnum, arcnum;
	int kind;

public:
	ALGraph(int vexnum, int edge);
	~ALGraph();
};

#endif

