#pragma once
#ifndef ALGraph_H_
#define ALGraph_H_

#include <iostream>
#include <string>
#include <stdlib.h>
#define MAX_VERTEX_NUM 100
using namespace std;


template <typename InfoType>
struct ArcNode {
	int adjvex;
	ArcNode * next;
	InfoType * info;
};


// typedef int VertexType;
template <class VertexType>
struct VNode {
	VertexType data;
	ArcNode<int> * firstarc;
};
typedef  VNode<int> AdjList[MAX_VERTEX_NUM];

class ALGraph {
private:
	AdjList vertices;
	int vexnum, arcnum;
	const int kind;

public:
	ALGraph(int vexnum, int arcnum);
	~ALGraph();
	void createGraph();
};

#endif

