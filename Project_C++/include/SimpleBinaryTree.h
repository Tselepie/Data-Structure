#ifndef SIMPLEBINARYTREE_H
#define SIMPLEBINARYTREE_H

#include "Arrays.h"
#include "Node.h"
#include "Pair.h"

class SimpleBinaryTree
{
    public:
        SimpleBinaryTree();
        ~SimpleBinaryTree();

        void addNode(char *leftword, char *rightword);
        void searchNode(char *key);
        int compareNodeData(char *data1, char *data2);
        int getElements(){ return this->elements; }

    protected:
        int elements;
        Node *head;

    private:
};

#endif // SIMPLEBINARYTREE_H
