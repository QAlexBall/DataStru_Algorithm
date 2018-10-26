# pragma once
#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include <iostream>
#include <string>
using namespace std;
#define INT_MAX 999999999
#define false 0
#define true 1
struct Dis {
	string path;
	int value;
	bool visit;
	Dis() {
		visit = false;
		value = 0;
		path = "";
	}
};

class Graph_DG {
private:
	int vexnum;
	int edge;
	int **arc; 	// 邻接矩阵
	Dis * dis;	// 记录各个定点最短路径信息

public:
	Graph_DG(int vexnum, int edge);
	~Graph_DG();
	bool check_edge_value(int start, int end, int weight);
	void createGraph();
	void print();
	void Dijkstra(int begin);
	void print_path(int);
};

#endif // DIJKSTRA_H_

