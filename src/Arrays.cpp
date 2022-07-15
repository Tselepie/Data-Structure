#include <iostream>
#include <algorithm>
#include <string.h>

#include "Arrays.h"
#include "Pair.h"

Arrays::Arrays(int cap)
{
    this->cap = cap;
    this->elements = 0;
    this->array = new Pair*[cap];
}

Arrays::~Arrays()
{
    for(int i=0; i<elements; i++)
        delete this->array[i];

    delete []this->array;
}

/*
** Checks if two pairs are exactly the same
*/
bool Arrays::areSame(char *pair1, char *pair2)
{
    if(strlen(pair1) != strlen(pair2))
        return false;

    for(unsigned int i=0; i<strlen(pair1); i++)
    {
        if(pair1[i] != pair2[i])
            return false;
    }

    return true;
}

/*
** Compares which pair is grammatically bigger or smaller and
** returns false if pair1 < pair2
** returns true if pair1 > pair2 or they are the same
*/
bool Arrays::comparePair(char *pair1, char *pair2)
{
    bool longer;
    int length;

    if(strlen(pair1) < strlen(pair2))
    {
        length = strlen(pair1);
        longer = false;
    }
    else
    {
        length = strlen((pair2));
        longer = true;
    }

    for(int i=0; i<length; i++)
    {
        if(pair1[i] == pair2[i])
            continue;
        else if(pair1[i] < pair2[i])
            return false;
        else
            return true;
    }

    return longer;
}

/*
** Adds element to array
*/
void Arrays::addElement(char *leftword, char *rightword)
{
    if(elements >= cap)
        return;

    array[elements++] = new Pair(leftword, rightword);
}

/*
** Sorts the unordered array
*/
void Arrays::sortElements()
{
    Pair *temp;

    for(int i=elements-1; i>0; i--)
    {
        for(int j=0; j<i; j++)
        {
            if(comparePair(findPair(j), findPair(j+1)))
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

/*
** Searches in the ordered array using binary search
*/
void Arrays::searchElementInSortedArray(char *key)
{
    bool found = false;
    int left = 0, middle, right = elements-1;

    middle = right/2;

    while(!found)
    {
        if(areSame(key, findPair(middle)))
            found = true;
        else if(comparePair(key, findPair(middle)))
        {
            left = middle;
            middle = (right+left)/2;
        }
        else
        {
            right = middle;
            middle = (right+left)/2;
        }
    }
}

/*
** Searches element to unordered array
*/
char *Arrays::searchElement(int pos)
{
    int i=0;
    char *key = findPair(pos);

    while(true)
    {
        if(areSame(key, findPair(i++)))
            return key;
    }
}

/*
** Returns the pairs in the position given
*/
char *Arrays::findPair(int pos)
{
    return &array[pos]->getPair()[0];
}
