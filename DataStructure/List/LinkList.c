#include "List.h"

typedef struct LNode {
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

void CreateList_L(LinkList *L, int n) {
    int i;
    LNode *p;
    *L = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL; 	// 建立一个带头节点的单链表
    (*L)->data = n;		// 头结点存储链表长度
    for(i = 0; i < n; i++) {
        p = (LinkList) malloc (sizeof(LNode));
        p->data = i + 1;
        p->next = (*L)->next;
        (*L)->next = p;
    }
}// CreateList_L

Status ListInsert_L(LinkList *L, int i, ElemType e) {
    // 在带头结点的单链线性表L中第i个位置之前插入元素e
    int j = 0;
    LNode *p, *s;
    p = *L;
    if(i < 1 || i > (*L)->data) return ERROR;
    while(p && j < i - 1) {
        p = p->next;
        j++;
    }
    s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    printf("%d, %d\n", i, s->data);
    (*L)->data = (*L)->data + 1;        // 表长加1
    return OK;
} // ListInsert_L

void display(LinkList L) {
    printf("the link length is: %d\n", L->data);
    LNode *p;
    p = L->next;
    printf("[ %d->", p->data);
    while(p->next != NULL) {
     	 p = p->next;
     	printf("%d->", p->data);
     }
    printf("null ]\n");
}


int main() {
    int n = 5;
    LinkList Link = NULL;
    CreateList_L(&Link, n);
    ListInsert_L(&Link, 2, 0);
    display(Link);
    return 0;
}
