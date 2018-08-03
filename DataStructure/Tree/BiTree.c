#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define OK 1
#define ERROR 0

typedef char TElemType;
typedef int Status;
// 二叉树的顺序存储表示
#define MAX_TREE_SIZE 100                       // 二叉树的最大结点数
typedef TElemType SqBiTiTree[MAX_TREE_SIZE];    // 0号单元存储根结点

typedef struct BiTNode {// 二叉树的二叉链表存储表示
    TElemType data;
    struct BiTNode *rchild, *lchild; // 左右孩子指针
}BiTNode, *BiTree;

# define STACK_INIT_SIZE 100  // 存储空间初始分配量
# define STACKINCREMENT 10   // 存储空间分配增量
# define True 1
# define False 0
typedef BiTree SElemType;
typedef struct {
    SElemType *base;
    SElemType *top;
    int stacksize;
} SqStack;

Status CreateBiTree(BiTree *T) {
// 按先序次序输入二叉树中结点的值（一个字符）， 空格字符表示空字
// 构造二叉链表表示的二叉树T
    char ch;
    scanf("%c", &ch);
    fflush(stdin);
    if (ch == '#') {
        T = NULL;
        printf("NULL\n");
    }
    else {
        if(!((*T) = (BiTNode *) malloc(sizeof(BiTNode)))) exit(-1);
        (*T)->data = ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
    return 0;
}
Status PreOrderTraverse(BiTree T, Status (*Visit)(TElemType e)) {
    // 采用二叉链表存储结构，Visit是对数据元素操作的应用函数
    // 先序遍历二叉树T的递归算法，对每个数据元素调用函数Visit
    if(T) {
        if(Visit(T->data))
            if(PreOrderTraverse(T->lchild, Visit))
                if(PreOrderTraverse(T->rchild, Visit)) return OK;
        return ERROR;
    } else return OK;
} // PreOrderTraverse

Status InOrder(BiTree T, Status (*Visit)(TElemType e)) {
    if(T) {
        if(InOrder(T->lchild, Visit))
            if(Visit(T->data))
                if(InOrder(T->rchild, Visit)) return OK;
        return ERROR;
    } else return OK;
} // InOrder

Status PostOrder(BiTree T, Status (*Visit)(TElemType e)) {
    if(T) {
        if(PostOrder(T->lchild, Visit))
            if(PostOrder(T->rchild, Visit))
                if(Visit(T->data)) return OK;
        return ERROR;
    } else return OK;
} // PostOrder
Status PrintElement(TElemType e) {
    printf("%c ", e);
    return OK;
}
Status InitStack(SqStack *S) {
    // 构建一个空栈S
    S->base = (SElemType *) malloc (STACK_INIT_SIZE * sizeof(SElemType));
    if(!S->base) exit (-1);
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return OK;
}
Status GetTop(SqStack S, SElemType *e) {
    // 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
    if (S.top == S.base) return ERROR;
    *e = *(S.top - 1);
    return OK;
}
Status Push(SqStack *S, SElemType e) {
    // 插入元素e作为新的栈顶元素
    if (S->top - S->base >= S->stacksize) { // 栈满，追加存储空间
        S->base = (SElemType *) realloc (S->base,
                                         (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
        if (!S->base) exit(-1);       // 存储空间分配失败
        S->top = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;
    }
    *(S->top++) = e;
    return OK;
}
Status Pop(SqStack *S, SElemType *e) {
    // 若栈不为空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
    if (S->top == S->base){
        printf("error\n");
        return ERROR;
    }
    *e = *--S->top;
    return OK;
}
Status StackEmpty(SqStack S) {
    if(S.base == S.top){
        return True;
    }
    return False;
}
Status InOrderTraverse(BiTree T, Status (*Visit)(TElemType e)) {
    // 采用二叉链表存储结构，Visit是对数组元素操作的应用函数。
    // 中序遍历二叉树T的非递归算法，对每个数据元素调用函数Visit。
    SqStack S;
    BiTNode *p;
    p = (BiTNode *) malloc (sizeof(BiTNode));
    InitStack(&S);
    Push(&S, T);
    while (!StackEmpty(S)) {
        while(GetTop(S, &p) && p) {
            Push(&S, p->lchild);
        }
        Pop(&S, &p);
        if (!StackEmpty(S)) {
            Pop(&S, &p);
            if(!Visit(p->data)) return ERROR;
            Push(&S, p->rchild);
        }
    }
    return OK;
}


int main() {
    BiTree BT;
    CreateBiTree(&BT);
    PreOrderTraverse(BT, PrintElement);
    InOrder(BT, PrintElement);
    PostOrder(BT, PrintElement);
    InOrderTraverse(BT, PrintElement);
    return 0;
}
