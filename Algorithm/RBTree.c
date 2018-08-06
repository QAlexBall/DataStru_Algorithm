#include <stdio.h>
#include <malloc.h>
#include <assert.h>

struct rb_node {
        unsigned long __rb_parent_color;
        struct rb_node *rb_right;
        struct rb_node *rb_left;
};

struct rb_root {
        struct rb_node *rb_node;
};

struct rb_root_cached {
        struct rb_root rb_root;
        struct rb_node *rb_leftmost;
};


