#include <iostream>
#include "ALGraph.h"
using namespace std;


ALGraph::ALGraph(int vexnum, int arcnum) : kind(0) {
	this->vexnum = vexnum;
	this->arcnum = arcnum;
	
	for(int i = 0; i < vexnum; i++) {
		vertices[i].data = i;
		vertices[i].firstarc = NULL;
	}
}

void ALGraph::createGraph() {
	cout << "please enter data for vertices: " << endl;
	for(int i = 0; i < vexnum; i++) {
		cin >> vertices[i].data;
	}
	cout << "please enter every arc: " << endl;
	for(int i = 0; i < arcnum; i++) {
		
	}
}
int main() {

}
