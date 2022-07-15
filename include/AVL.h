#ifndef AVL_H
#define AVL_H

#include "SimpleBinaryTree.h"

class AVL: public SimpleBinaryTree
{
    public:
        AVL();
        ~AVL();

        void addNode(char *leftword, char *rightword);
        int checkHeight(Node *node);

    protected:

    private:
        int balance;
        Node *rotateLeft(Node *node);
        Node *rotateRight(Node *node);
        Node *createNode(Pair *newPair);
        Node *recursion(Node *node, Pair *newPair);
};

#endif // AVL_H
