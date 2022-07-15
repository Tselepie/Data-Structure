#include <iostream>
#include <string.h>
#include <math.h>

#include "Hashtable.h"
#include "Pair.h"

#define HASH_TABLE_SIZE_PRIME 100003 // the first prime number > 2*CAP

Hashtable::Hashtable()
{
    this->hashtable = new std::string[HASH_TABLE_SIZE_PRIME];
}

Hashtable::~Hashtable()
{
    //dtor
}

/*
** Adds pair to hash table
*/
void Hashtable::addToHash(char *leftword, char *rightword)
{
    Pair *newPair = new Pair(leftword, rightword);

    int pos = hashFunction(newPair->getPair());

    if(hashtable[pos] == "")
        hashtable[pos] = newPair->getPair();
    else
    {
        pos = quadraticProbing(pos);
        hashtable[pos] = newPair->getPair();
    }
}

/*
** Searches for the given key in the hash table
*/
void Hashtable::searchHash(char *key)
{
    int pos = hashFunction(key);

    if(hashtable[pos] == key)
        return;
    else
    {
        pos = quadraticProbingSearch(key, pos);
        return;
    }
}

/*
** Implementation of the djb2 hash function
*/
int Hashtable::hashFunction(char *pair)
{
    unsigned int hash = 5381;

    for(unsigned int i=0; i<strlen(pair); i++)
        hash = ((hash << 5) + hash) + (int)pair[i];

    hash = hash%HASH_TABLE_SIZE_PRIME;

    return hash;
}

/*
** Implementation of the function : h_i(X) = (Hash(X) + i^2)%HashTableSize
** which is used if we have a collision
*/
int Hashtable::quadraticProbing(int hash)
{
    int i=0, newHash;

    while(true)
    {
        newHash = (hash + i*i)%HASH_TABLE_SIZE_PRIME;

        if(hashtable[newHash] == "")
            return newHash;

        i++;
    }
}

/*
** Searches for the key which when added a collision occurred
** and the quadraticProbing function was used
*/
int Hashtable::quadraticProbingSearch(char *key, int hash)
{
    int i=0, newHash;

    while(true)
    {
        newHash = (hash + i*i)%HASH_TABLE_SIZE_PRIME;

        if(hashtable[newHash] == key)
            return newHash;

        i++;
    }
}
