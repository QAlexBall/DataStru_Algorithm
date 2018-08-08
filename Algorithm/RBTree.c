#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#define RB_RED 0
#define RB_BLACK 1

struct rb_node {
        unsigned long __rb_parent_color;
        struct rb_node *rb_right;
        struct rb_node *rb_left;
} __attribute__((aligned(sizeof(long)))); // struct rb_node在内存中的地址需按4B或者8B对齐
// struct rb_node的字段__rb_parent_color利用最后一位保存节点的颜色信息

struct rb_root {        // 根
        struct rb_node *rb_node;
}; // 通过判断此指针是否为空,来判断树是否为空,引入以下接口
#define RB_EMPTY_ROOT(root) ((root)->rb_node == NULL)   

struct rb_root_cached {
        struct rb_root rb_root;
        struct rb_node *rb_leftmost;
};

#define rb_parent(r) ((struct rb_node*)((r)->__rb_parent_color & ~3)) // 提取父节点地址
/**
 * __rb_parent_color & ~3 = 过滤掉低2位(非0变成0),保留3-32位.
 * __rb_parent_color是无符号长整型,强制转化成struct rb_node * 类型
 */


#define RB_ROOT (struct rb_root) { NULL, }      // 将{ NULL, }强制转换成(struct rb_root),初始化为空树
/** 
 * 定义一颗红黑树,初始化为空树:
 * static struct rb_root mytree = RB_ROOT;
 */

int main(void) {
        __int8_t i = 10;
        printf("%d", i);
        struct rb_node a;
        a.__rb_parent_color = 0;
        printf("%lu\n", a.__rb_parent_color);
        int b = sizeof(long);
        printf("%d", b);
        return 0;
}
