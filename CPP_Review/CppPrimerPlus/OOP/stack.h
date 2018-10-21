//
// Created by alex on 10/21/18.
//

#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;

class Stack {
private:
    enum {MAX = 10};
    Item items[MAX];
    int top;

public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    // push() returns false if stack already is full, true otherwise
    bool push(const Item & item);   // add item to stack
    // pop() returns false if stack already is empty, true otherwise
    bool pop(Item & item);  // pop top into item
};
#endif //STACK_H_
