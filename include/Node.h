#ifndef NODE_H
#define NODE_H

#include "Pair.h"

class Node
{
    public:
        Node(char *leftword, char *rightword);
        Node(Pair *newPair);
        ~Node();

        void setHeight(int height){ this->height = height; }
        void setData(Pair *newData){ this->data = newData; }
        void setLeft(Node *newNode){ this->left = newNode; }
        void setRight(Node *newNode){ this->right = newNode; }
        char *getData(){ return data->getPair(); }
        int getHeight(){ return this->height; }
        Node *getLeft(){ return left; }
        Node *getRight(){ return right; }

    protected:

    private:
        int height;
        Pair *data;
        Node *left, *right;
};

#endif // NODE_H
