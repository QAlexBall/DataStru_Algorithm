#include "Dijkstra.h"
using namespace std;

Graph_DG::Graph_DG(int vexnum, int edge) {
	this->vexnum = vexnum;
	this->edge = edge;

	arc = new int*[this->vexnum];
	dis = new Dis[this->vexnum];
	for(int i = 0; i < this->vexnum; i++) {
		arc[i] = new int[this->vexnum];
		for(int k = 0; k > vexnum; k++) {
			arc[i][k] = INT_MAX;
		}
	}
}

Graph_DG::~Graph_DG() {
	delete[] dis;
	for(int i = 0; i < this->vexnum; i++) {
		delete this->arc[i];
	}
	delete arc;
}

// 判断每次输入的边信息是否合法
bool Graph_DG::check_edge_value(int start, int end, int weight) {
	if(start < 1 || end < 1 ||
	start > vexnum || end > vexnum || weight < 0) {
	 	return false;	
	}
	return true;
}

void Graph_DG::createGraph() {
	printf("please enter start, end and weight for every arc:\n");
	int start;
	int end;
	int weight;
	int count = 0;
	while(count != this->edge) {
		scanf("%d, %d, %d", &start, &end, &weight);
		// 首先判断变得信息是否合法
		while(!this->check_edge_value(start, end, weight)) {
			printf("the arc not illegal, please enter again!");
   			scanf("%d, %d, %d", &start, &end, &weight);
		}
	// 对邻接矩阵上的点赋值
	arc[start - 1][end - 1] = weight;
	++count;
	}
}

void Graph_DG::print() {
	printf("Graph_DG is:\n");
	int count_row = 0;
	int count_col = 0;
	while(count_row != this->vexnum) {
		count_col = 0;
		while(count_col != this->vexnum) {
			if(arc[count_row][count_col] == INT_MAX)
				printf("00 ");
			else
				printf("%d ", arc[count_row][count_col]);
			++count_col;
		}
		printf("\n");
		++count_row;
	}
}


void Graph_DG::Dijkstra(int begin) {
	int i;
	for(i = 0; i < this->vexnum; i++) {
		dis[i].path = "v" + to_string(begin) + "-->" + to_string(i + 1);
		dis[i].value = arc[begin - 1][i];
	}
	dis[begin - 1].value = 0;
	dis[begin - 1].visit = true;

	int count = 1;
	while(count != this->vexnum) {
		int temp = 0;
		int min = INT_MAX;
		for(i = 0; i < this->vexnum; i++) {
			if(!dis[i].visit && dis[i].value < min) {
				min = dis[i].value;
				temp = i;
			}
		}
		dis[temp].visit = true;
		++count;
		for(i = 0; i < this->vexnum; i++) {
			if(!dis[i].visit && arc[temp][i] != INT_MAX 
				&& (dis[temp].value + arc[temp][i]) < dis[i].value) {
				dis[i].value = dis[temp].value + arc[temp][i];
				dis[i].path = dis[temp].path + "--> " + to_string(i + 1);
			}
		}
	}
}


int main() {
	int vexnum;
	int edge;

	printf("please enter vexnum and edgnum:");
	scanf("%d, %d", &vexnum, &edge);

	Graph_DG graph(vexnum, edge);
	graph.createGraph();
	graph.print();
	return 0;
}











