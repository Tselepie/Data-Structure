#include <iostream>
#include <algorithm>
#include <math.h>

#include "AVL.h"
#include "SimpleBinaryTree.h"
#include "Pair.h"

AVL::AVL():SimpleBinaryTree()
{
    this->balance = 0;
}

AVL::~AVL()
{
    //dtor
}

/*
** Adds node to AVL tree
*/
void AVL::addNode(char *leftword, char *rightword)
{
    Pair *newPair = new Pair(leftword, rightword);

    head = recursion(head, newPair);
    return;
}

/*
** Checks the height of the node given
*/
int AVL::checkHeight(Node *node)
{
    if(node == nullptr)
        return 0;

    return node->getHeight();
}

/*
** Implementation of the left rotation which
** is used to create the AVL tree
*/
Node *AVL::rotateLeft(Node *node)
{
    Node *temp1 = node->getRight();
    Node *temp2 = temp1->getLeft();

    temp1->setLeft(node);
    node->setRight(temp2);

    node->setHeight(1 + std::max(checkHeight(node->getLeft()), checkHeight(node->getRight())));
    temp1->setHeight(1 + std::max(checkHeight(temp1->getLeft()), checkHeight(temp1->getRight())));

    return temp1;
}

/*
** Implementation of the right rotation which
** is used to create the AVL tree
*/
Node *AVL::rotateRight(Node *node)
{
    Node *temp1 = node->getLeft();
    Node *temp2 = temp1->getRight();

    temp1->setRight(node);
    node->setLeft(temp2);

    node->setHeight(1 + std::max(checkHeight(node->getLeft()), checkHeight(node->getRight())));
    temp1->setHeight(1 + std::max(checkHeight(temp1->getLeft()), checkHeight(temp1->getRight())));

    return temp1;
}

/*
** Creates a new node
*/
Node *AVL::createNode(Pair *newPair)
{
    Node *temp = new Node(newPair);

    temp->setLeft(nullptr);
    temp->setRight(nullptr);
    temp->setHeight(1);

    return temp;
}

/*
** The following function uses recursion to create the AVL tree
*/
Node *AVL::recursion(Node *node, Pair *newPair)
{
    if(node == nullptr)
    {
        node = createNode(newPair);
        elements++;
        return node;
    }
    else
    {
        if(compareNodeData(node->getData(), newPair->getPair()) == -1)
            node->setLeft(recursion(node->getLeft(), newPair));
        else if(compareNodeData(node->getData(), newPair->getPair()) == 1)
            node->setRight(recursion(node->getRight(), newPair));
        else
            return node;

        node->setHeight(1 + std::max(checkHeight(node->getLeft()), checkHeight(node->getRight())));
        balance = checkHeight(node->getLeft()) - checkHeight(node->getRight());

        // perform left-left rotation
        if(balance > 1 && compareNodeData(node->getData(), newPair->getPair()) == -1)
            return rotateRight(node);

        // perform right-right rotation
        if(balance < -1 && compareNodeData(node->getData(), newPair->getPair()) == 1)
            return rotateLeft(node);

        // perform left-right rotation
        if(balance > 1 && compareNodeData(node->getData(), newPair->getPair()) == 1)
        {
            node->setLeft(rotateLeft(node->getLeft()));
            return rotateRight(node);
        }

        // perform right-left rotation
        if(balance < -1 && compareNodeData(node->getData(), newPair->getPair()) == -1)
        {
            node->setRight(rotateRight(node->getRight()));
            return rotateLeft(node);
        }
    }


    return node;
}
