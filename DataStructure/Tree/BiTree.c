#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define OK 1
#define ERROR 0

typedef char TElemType;
typedef char Status;
// 二叉树的顺序存储表示
#define MAX_TREE_SIZE 100  						// 二叉树的最大结点数
typedef TElemType SqBiTiTree[MAX_TREE_SIZE];    // 0号单元存储根结点

// 二叉树的二叉链表存储表示
typedef struct BiTNode {
    TElemType data;
    struct BiTNode *rchild, *lchild; // 左右孩子指针
}BiTNode, *BiTree;


Status CreateBiTree(BiTree *T) {
// 按先序次序输入二叉树中结点的值（一个字符）， 空格字符表示空字
// 构造二叉链表表示的二叉树T
    char ch;
    printf("please enter node:");
    scanf("%c", &ch);
    if (ch == '#') {
        T = NULL;
        printf("NULL\n");
    }
    else {
        if(!((*T) = (BiTNode *) malloc(sizeof(BiTNode)))) exit(OVERFLOW);
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

Status PrintElement(TElemType e) {
    printf("%c", e);
    return OK;
}
int main() {
    BiTree BT;
    CreateBiTree(&BT);
    PreOrderTraverse(BT, PrintElement);
    return 0;
}
