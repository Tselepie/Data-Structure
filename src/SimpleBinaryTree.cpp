#include <iostream>
#include <string.h>

#include "SimpleBinaryTree.h"
#include "Node.h"
#include "Pair.h"

SimpleBinaryTree::SimpleBinaryTree()
{
    this->elements = 0;
    this->head = nullptr;
}

SimpleBinaryTree::~SimpleBinaryTree()
{
    //dtor
}

/*
** Compares two pairs, which are stored in node data, and
** returns -1 if pair1 < pair2
** returns 0 if pair1 = pair2
** returns 1 if pair1 > pair2
*/
int SimpleBinaryTree::compareNodeData(char *data1, char *data2)
{
    int longer;
    int length;
    int leftPairLen = strlen(data1);
    int rightPairLen = strlen(data2);

    if(leftPairLen < rightPairLen)
    {
        length = leftPairLen;
        longer = -1;
    }
    else if(leftPairLen > rightPairLen)
    {
        length = rightPairLen;
        longer = 1;
    }
    else
    {
        length = leftPairLen;
        longer = 0;
    }


    for(int i=0; i<length; i++)
    {
        if(data1[i] == data2[i])
            continue;
        else if(data1[i] < data2[i])
            return -1;
        else
            return 1;
    }

    return longer;
}

/*
** Adds a new node to simple binary tree
*/
void SimpleBinaryTree::addNode(char *leftword, char *rightword)
{
    Node *newNode = new Node(leftword, rightword);

    if(head == nullptr)
    {
        head = newNode;
        head->setLeft(nullptr);
        head->setRight(nullptr);
        elements++;
        return;
    }

    Node *temp = head;

    while(true)
    {
        if(compareNodeData(newNode->getData(), temp->getData()) == -1)
        {
            if(temp->getLeft() == nullptr)
            {
                temp->setLeft(newNode);
                elements++;
                return;
            }

            temp = temp->getLeft();
        }
        else if(compareNodeData(newNode->getData(), temp->getData()) == 1)
        {
            if(temp->getRight() == nullptr)
            {
                temp->setRight(newNode);
                elements++;
                return;
            }

            temp = temp->getRight();
        }
        else
            return;
    }
}

/*
** Searches for a node using the given key
*/
void SimpleBinaryTree::searchNode(char *key)
{
    Node *temp = head;

    while(true)
    {
        if(compareNodeData(key, temp->getData()) == 0)
            return;
        else if(compareNodeData(key, temp->getData()) == -1)
        {
            if(temp->getLeft() == nullptr)
                return;

            temp = temp->getLeft();
        }
        else
        {
            if(temp->getRight() == nullptr)
                return;

            temp = temp->getRight();
        }
    }
}
