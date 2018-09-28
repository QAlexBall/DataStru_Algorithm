#include <iostream>
#include <fstream>
using namespace std;
#define true 0

#define MaxVertexNum 100
typedef struct {
        char Vex[MaxVertexNum];
        int Edge[MaxVertexNum][MaxVertexNum];
        int VexNum, EdgeNum;
}MGraph;

bool initGraph(MGraph &graph) {
        int verNum, edgeNum;
        cout << "input vertex num: " << endl;
        cin >> verNum;
        cout << "input edge num: " << endl;
        cin >> edgeNum;
        if(verNum < 1 || verNum > 100 || edgeNum < 0) {
                cout << "error" << endl;
                return false;
        }
        cout << "input vertex: " << endl;
        for(int i = 1; i <= verNum; i++)
                cin >> graph.Vex[i];
        for(int i = 1; i <= verNum; i++)
                for(int j = 1; j <= verNum; j++)
                        graph.Edge[i][j] = 0;
        cout << "input edge: " << endl;
        for(int i = 0, x, y; i < edgeNum; i++) {
                cin >> x >> y;
                if(x <= verNum && y <= verNum)
                        graph.Edge[x][y] = 1;
                else {
                        cout << "error" << endl;
                        return false;
                }
        }
        graph.VexNum = verNum;
        graph.EdgeNum = edgeNum;
        return true;
}

bool initGraphByFile(MGraph &graph) {
        cout << "reading MGraph.txt" << endl;
        ifstream fin("./MGraph.txt");
        streambuf* cinbackup = cin.rdbuf(fin.rdbuf());
        bool result = initGraph(graph);
        cin.rdbuf(cinbackup);
        if(result) {
                cout << "create success" << endl;
                return true;
        }
        return false;
}

bool adjacent(MGraph &G, int x, int y) {
        if(G.Edge[x][y] == 1) 
                return true;
        else 
                return false;
}

void neighbors(MGraph &G, int x) {
        for(int i = 1; i <= G.VexNum; i++) {
                if(G.Edge[x][i] == 1)
                        cout << x << " " << endl;
                if(G.Edge[i][x] == 1)
                        cout << i << " " << x << endl;
        }
}



int main(void) {
	MGraph graph;
	initGraph(graph);
        return 0;
}


