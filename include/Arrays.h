#ifndef ARRAYS_H
#define ARRAYS_H

#include "Pair.h"

class Arrays
{
    public:
        Arrays(int cap);
        ~Arrays();

        bool areSame(char *pair1, char *pair2);
        bool comparePair(char *pair1, char *pair2);
        void addElement(char *leftword, char *rightword);
        void searchElementInSortedArray(char *key);
        void sortElements();
        char *searchElement(int pos);
        char *findPair(int pos);
        int getCap(){ return cap; }
        int getElements(){ return elements; }

    protected:

    private:
        int cap, elements;
        Pair **array;
};

#endif // ARRAYS_H
