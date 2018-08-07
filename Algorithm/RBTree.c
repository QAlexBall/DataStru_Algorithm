#include <stdio.h>
#include <malloc.h>
#include <assert.h>

struct rb_node {
        unsigned long __rb_parent_color;
        struct rb_node *rb_right;
        struct rb_node *rb_left;
} __attribute__((aligned(sizeof(long)))); // struct rb_node在内存中的地址需按4B或者8B对齐
// struct rb_node的字段__rb_parent_color利用最后一位保存节点的颜色信息

struct rb_root {
        struct rb_node *rb_node;
};

struct rb_root_cached {
        struct rb_root rb_root;
        struct rb_node *rb_leftmost;
};

#define rb_parent(r) ((struct rb_node*)((r)->__rb_parent_color & ~3))

#define RB_ROOT (struct rb_root) { NULL, }


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
