#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>

#include "Pair.h"

class Hashtable
{
    public:
        Hashtable();
        ~Hashtable();

        void addToHash(char *leftword, char *rightword);
        void searchHash(char *key);

    protected:

    private:
        std::string *hashtable;
        int hashFunction(char *pair);
        int quadraticProbing(int hash);
        int quadraticProbingSearch(char *key, int hash);
};

#endif // HASHTABLE_H
