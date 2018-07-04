
#include "List.h"
// #include <stdio.h>
// #include <stdlib.h>
// // 顺序表 （主要特点随机访问）
// /* 静态分配
// #define MaxSize 50 // 定义线性表的最大长度

// typedef struct{
// 	ElemType data[MaxSize];
// 	int length;	   // 顺序表当前长度
// } SeqList;		   // 顺序表类型定义
// */

// // 动态分配  (动态分配属于顺序存储结构，分配的控件大小可以在运行时决定)
# define LIST_INIT_SIZE 100 // 表长度的初始定义
# define LISTINCREMENT 10   // 线性表存储空间的分配增量

typedef struct {
	ElemType *elem;			// 存储空间的基地址
	int length;				// 当前长度
	int listsize;    		// 当前分配的存储容量（以sizeof(ElemType)为单位
} SeqList;

// C的初始动态分配语句
// L.data = (ElemType *)malloc(sizeof(ElemType)*InitSize);
// C++的初始动态分配语句
// L.data = new ElemType[InitSize];

Status InitList_Seq(SeqList &L) {
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if(!L.elem) exit(OVERFLOW);    // 存储分配失败
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
} // InitList_Seq

Status ListInsert_Seq(SeqList &L, int i, ElemType e) {
	if(i < 1 || i > L.length + 1) return ERROR;    // i值不合法
	if(L.length >= L.listsize) {				   // 当前存储空间已满，增加分配
		ElemType *newbase = (ElemType *)realloc(L.elem, 
			(L.listsize + LISTINCREMENT) * sizeof(ElemType));
	if(!newbase) exit(OVERFLOW);				   // 存储分配失败
	L.elem = newbase;							   // 新基质
	L.listsize += LISTINCREMENT; 				   // 增加后的存储容量
	}

	ElemType *q, *p;
	q = &(L.elem[i - 1]); // q为插入位置的地址（位序由1开始，数组下标由0开始）
	for(p = &(L.elem[L.length - 1]); q <= p; p--) {
		*(p + 1) = *p;
	}
	*q = e;
	L.length++;
	return OK;
}// ListInster_Seq


Status ListDelete_Seq(SeqList &L, int i, ElemType &e) {
	if(i < 0 || i > L.length) return ERROR;		// i值不合理

	ElemType *p, *q;
	p = &(L.elem[i - 1]);
	e = *p;
	for(q = &(L.elem[L.length - 1]); p < q; p++) {
		*(p ) = *(p + 1);
	}
	L.length--;
	return OK;
}



int main() {
	SeqList L;
	ElemType e;
	InitList_Seq(L);
	ListInsert_Seq(L, 1, 100);
	ListInsert_Seq(L, 1, 101);
	ListInsert_Seq(L, 1, 102);
	printf("%d\n", L.elem[0]);
	printf("%d\n", L.elem[1]);
	printf("%d\n", L.elem[2]);
	ListDelete_Seq(L, 1, e);
	printf("%d\n", e);
	// printf("%d\n", L.elem[L.length-1]);
	return 0;
}