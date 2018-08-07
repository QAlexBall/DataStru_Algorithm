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
                        key(value), color(c), parent(p), left(l), right(r) {}
};

template <class T>
class RBTree {
        private:
                RBTNode<T> *mRoot;
        public:
                RBTree();
                ~RBTree();

                void preOrder();
                void inOrder();
                void postOrder();

                RBTNode<T>* search(T key);
                RBTNode<T>* iterativeSearch(T key);
                
                T minimum();
                T maximum();


};
