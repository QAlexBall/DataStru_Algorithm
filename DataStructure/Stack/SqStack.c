#include <stdio.h>
#include <stdlib.h>

# define STACK_INIT_SIZE 100  // 存储空间初始分配量
# define STACKINCREMENT 10   // 存储空间分配增量
# define OK 0
# define ERROR 1
# define OVERFLOW -1

typedef int Status;
typedef char SElemType;
typedef struct {
    SElemType *base;
    SElemType *top;
    int stacksize;
} SqStack;

Status InitStack(SqStack *S) {
    // 构建一个空栈S
    S->base = (SElemType *) malloc (STACK_INIT_SIZE * sizeof(SElemType));
    if(!S->base) exit (OVERFLOW);
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
        if (!S->base) exit(OVERFLOW);       // 存储空间分配失败
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
int main() {
    SqStack ss;
    SElemType e;
    InitStack(&ss);
    Push(&ss, 'a');
    GetTop(ss, &e);
    printf("%c\n", e);	// a
    Pop(&ss, &e);
    Pop(&ss, &e); 		// error
    SElemType f;
    GetTop(ss, &f);
    printf("%c\n", f);	// <0x00>
    return 0;
}
