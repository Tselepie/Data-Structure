#include <string.h>

#include "Pair.h"

Pair::Pair()
{
    this->pair = nullptr;
}

/*
** Merges two words into one pair
*/
Pair::Pair(char *leftword, char *rightword)
{
    int j=0;
    int length = strlen(leftword) + strlen(rightword);
    pair = new char[length+1];

    for(unsigned int i=0; i <= strlen(leftword); i++)
        this->pair[i] = leftword[i];

    for(int i=strlen(leftword); i <= length; i++)
        this->pair[i] = rightword[j++];
}

Pair::~Pair()
{
    //dtor
}
