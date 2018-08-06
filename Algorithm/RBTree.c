#include <stdio.h>
#include <malloc.h>
#include <assert.h>

struct rb_node {
        unsigned long __rb_parent_color;
        struct rb_node *rb_right;
        struct rb_node *rb_left;
}rb_node;

