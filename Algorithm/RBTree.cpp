enum RBColor{RED, BLACK};

template <class T>
class RBTNode {
        public :
                RBColor color;
                T key;
                RBTNode *left;
                RBTNode *right;
                RBTNode *parent;

                RBTNode(T value,RBColor c,  RBTNode *p, RBTNode *l, RBTNode *r):
                        key(value), color(c), parent(), left(l), right(r) {}
};

