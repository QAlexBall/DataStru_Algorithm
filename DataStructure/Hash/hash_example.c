/**
 * hash example
 * refer to linux kernel
 */

#include <stdio.h>
#include <stdlib.h>

struct hlist_node {                     
        struct hlist_node *next;        // 指向想一个结点的指针
        struct hlist_node **pprev;      // 指向上一个结点的next指针的地址
};
struct hlist_head {
        struct hlist_node *first;       // 指向每一个hash桶的第一个结点的指针
};

// 初始化hash桶的头结点
#define INIT_HLIST_HEAD(ptr) ((ptr)->first = NULL)
// 初始化hash桶的普通结点
static inline void INIT_HLIST_NODE(struct hlist_node *node) {
        node->next = NULL;
        node->pprev = NULL;
}

/**
 * hlist_add_head
 * @n: the element to add to the hash list.
 * @h: the list to add to.
 */
static inline void hlist_add_head(struct hlist_node *n, struct hlist_head *h) {
        struct hlist_node *first = h->first;    // 创建一个frst指针,指向首结点的下一个结点h;
        n->next = first;                        // 新节点n指向h

        if(first)
                first->pprev = &n->next;        // 指向n结点的next指针的地址
        
        h->first = n;                           // 头的first指针指向新结点n
        n->pprev = &h->first;                   
}

/* next must be != NULL */
/* n: new node 
 * next: add node before next
 */
static inline void hlist_add_before(struct hlist_node *n, struct hlist_node *next) {
        n->pprev = next->pprev;
        n->next = next;
        next->pprev = &n->next;
        *(n->pprev) = n;
}
/* next must != NULL */
/**
 * n: new node 
 * next: add node after next
 */
static inline void hlist_add_after(struct hlist_node *n, struct hlist_node *next) {
        n->next = next->next;
        next->next = n;
        n->pprev = &next->next;

        if(n->next)
                n->next->pprev = &n->next;
}

/**
 * n: node need delete
 */
static inline void __hlist_del(struct hlist_node *n) {
       struct hlist_node *next = n->next;
       struct hlist_node **pprev = n->pprev;
       *pprev = next;
       if(next)
                next->pprev = pprev;
}

static inline void hlis_del(struct hlist_node *n) {
        __hlist_del(n);
        /*n->next = LIST_POISON1;*/
        /*n->pprev = LIST_POISON2;*/
}


/*
 * 判断一个结点是否已经存在与hash桶中
 * 判断h->prev是不是为空,如果pprev的指向是空,表示这个结点没有到添加到这个链表
 * 如果为空,返回true,否则返回false
 */
static inline int hlist_unhashed(const struct hlist_node *h) {
        return !h->pprev;
}

/**
 * 遍历
 */
/* ptr: 表示struct hlist_node类型的一个地址
 * type: 结构体名
 * member: type结构体中的hlist_node成员变量的名称
 * 表示得到ptr所指地址的这个结构体的首地址
 */
#define hlist_entry(ptr, type, member) container_of(ptr, type, member)















