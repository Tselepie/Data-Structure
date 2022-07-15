#include "Node.h"
#include "Pair.h"

Node::Node(char *leftword, char *rightword)
{
    this->data = new Pair(leftword, rightword);
    this->left = nullptr;
    this->right = nullptr;
}

Node::Node(Pair *newPair)
{
    this->data = newPair;
    this->left = nullptr;
    this->right = nullptr;
}

Node::~Node()
{
    //dtor
}
