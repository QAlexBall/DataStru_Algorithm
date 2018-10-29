#include <stdio.h>
#include <stdlib.h>

// ----- 图的数组(邻接矩阵)存储表示 -----
#define INFINITY INT_MAX		// 最大值
#define MAX_VERTEXT_NUM 20		// 最大顶点个数
typedef enum {DG, DN, UDG, UDN} GraphKind; // {有向图， 有向网， 无向图， 无向网}
typedef struct ArcCell {
	VRType adj;			// VRType是顶点
	InfoType * info;
}ArcCell, AdjMatrix[MAX_VERTEXT_NUM][MAX_VERTEXT_NUM];


