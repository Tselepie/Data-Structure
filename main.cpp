#include <iostream>
#include <algorithm>
#include <cctype>
#include <ctime>
#include <string.h>
#include <cstring>
#include <string>
#include <sstream>

#include "Pair.h"
#include "Arrays.h"
#include "SimpleBinaryTree.h"
#include "AVL.h"
#include "Hashtable.h"

#define CAP 50000 // The number of the pairs extracted from the file given
#define LINE_LENGTH 100 // The approximate length of each line in the file
#define RANDOM_NUMBER 500 // Used while created the random pairs array

using namespace std;

/*
** A function converting a float to a string
*/
string toString(float time)
{
    ostringstream convert;
    convert << time;
    string theString = convert.str();

    return theString;
}

/*
** @ FOR THE VOID FUNCTIONS BELOW
**
** @ n : the number of the random pairs
** @ randomPairs : the array holding the random pairs
** @ output : the output file in which the data will be stored
**
*/

/*
** @ unArray: the unordered array
*/
void unorderedArray(Arrays &unArray, int &n, string *&randomPairs, FILE &output)
{
    int *pairPos; // an array of random numbers which are technically the random pair positions
    float timeConsumed;

    // get random pairs
    srand(time(0));
    n = rand()%CAP/4 + RANDOM_NUMBER; // n will always be some number+500 due to the RANDOM_NUMBER
    pairPos = new int[n];
    randomPairs = new string[n];

    // start
    clock_t timer = clock();

    for(int i=0; i<n; i++)
    {
        pairPos[i] = rand()%n; // stores random numbers in array
        randomPairs[i] = unArray.searchElement(pairPos[i]); // searches pairs in unordered array and creates
                                                            // a string array which stores the randomly created pairs
    }

    // finish
    timer = clock() - timer;
    timeConsumed = (float)timer/CLOCKS_PER_SEC;

    string convert = toString(timeConsumed);

    fputs("Search in unordered array: ", &output);
    fputs(&convert[0], &output);
    fputs(" sec.\n", &output);
}

void orderedArray(Arrays &unArray, int &n, string *&randomPairs, FILE &output)
{
    char *stringObj;
    float timeConsumed;

    // sorting the array
    clock_t timer1 = clock();

    unArray.sortElements();

    timer1 = clock() - timer1;
    timeConsumed = (float)timer1/CLOCKS_PER_SEC;

    string convert = toString(timeConsumed);

    fputs("Time consumed to sort the array: ", &output);
    fputs(&convert[0], &output);
    fputs(" sec.\n", &output);

    // start
    clock_t timer2 = clock();

    for(int i=0; i<n; i++)
    {
        stringObj = &randomPairs[i][0];
        unArray.searchElementInSortedArray(stringObj); // searches pairs in ordered array
    }

    // finish
    timer2 = clock() - timer2;
    timeConsumed = (float)timer2/CLOCKS_PER_SEC;

    convert = toString(timeConsumed);

    fputs("Search in ordered array: ", &output);
    fputs(&convert[0], &output);
    fputs(" sec.\n", &output);
}

/*
** @ simpleTree: the simple tree
*/
void simpleBinaryTree(SimpleBinaryTree &simpleTree, int &n, string *&randomPairs, FILE &output)
{
    char *stringObj;
    float timeConsumed;

    // start
    clock_t timer = clock();

    for(int i=0; i<n; i++)
    {
        stringObj = &randomPairs[i][0];
        simpleTree.searchNode(stringObj); // searches pairs in tree
    }

    // finish
    timer = clock() - timer;
    timeConsumed = (float)timer/CLOCKS_PER_SEC;

    string convert = toString(timeConsumed);

    fputs("Search in simple binary tree: ", &output);
    fputs(&convert[0], &output);
    fputs(" sec.\n", &output);
}

/*
** @ avl: the AVL tree
*/
void avlTree(AVL &avl, int &n, string *&randomPairs, FILE &output)
{
    char *stringObj;
    float timeConsumed;

    // start
    clock_t timer = clock();

    for(int i=0; i<n; i++)
    {
        stringObj = &randomPairs[i][0];
        avl.searchNode(stringObj); // searches pairs in tree
    }

    // finish
    timer = clock() - timer;
    timeConsumed = (float)timer/CLOCKS_PER_SEC;

    string convert = toString(timeConsumed);

    fputs("Search in AVL tree: ", &output);
    fputs(&convert[0], &output);
    fputs(" sec.\n", &output);
}

/*
** @ hashtable: the hash table
*/
void hashing(Hashtable &hashtable, int &n, string *&randomPairs, FILE &output)
{
    char *stringObj;
    float timeConsumed;

    // start
    clock_t timer = clock();

    for(int i=0; i<n; i++)
    {
        stringObj = &randomPairs[i][0];
        hashtable.searchHash(stringObj);
    }

    // finish
    timer = clock() - timer;
    timeConsumed = (float)timer/CLOCKS_PER_SEC;

    string convert = toString(timeConsumed);

    fputs("Search in hash table: ", &output);
    fputs(&convert[0], &output);
    fputs(" sec.\n", &output);
}

/*
** This function deletes special characters and numbers from a string
** and returns it lowercase
*/
char *fixWord(char *word, char noString[])
{
    if(word == nullptr)
        return noString;

    string str(word);

    for(unsigned int i=0; i<str.size(); i++)
    {
        if((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {
            str.erase(i, 1);
            i--;
        }
    }

    if(str.empty())
        return noString;

    transform(str.begin(), str.end(), str.begin(), [](unsigned char c){return tolower(c);});

    for(unsigned int i=0; i<str.size()+1; i++)
        word[i] = str[i];

    return word;
}

int main()
{
    clock_t timer = clock();

    FILE *file = fopen("a_file.txt", "r");

    if(!file)
    {
        cout << stderr << "File didn't open.." << endl;
        return 1;
    }

    Arrays *unArray = new Arrays(CAP);
    SimpleBinaryTree *simpleTree = new SimpleBinaryTree();
    AVL *avl = new AVL();
    Hashtable *hashtable = new Hashtable();

    int n, i=0;
    string *randomPairs;       // the array of the random pairs
    char buffer[LINE_LENGTH];  // holds the current line while reading the file
    char noString[] = "EMPTY"; // this helps in order to check if a word is a whitespace while reading the file
    char *temp = noString;     // holds the previous ward in order to create a pair while reading the file
    float timeConsumed;

    while(fgets(buffer, LINE_LENGTH, file) && i!=-1)
    {
        char *c = strtok(buffer, " , "); // helps to distinguish each word in the current line

        while(c != nullptr)
        {
            if(unArray->getElements() >= CAP-1)
            {
                i = -1;
                break;
            }

            c = fixWord(c, noString);

            if(c != noString)
            {
                if(i++ >= 1)
                {
                    unArray->addElement(temp, c);  // adding pair to array
                    simpleTree->addNode(temp, c);  // adding pair to simple tree
                    avl->addNode(temp, c);         // adding pair to AVL tree
                    hashtable->addToHash(temp, c); // adding pair to Hash table
                }

                delete temp;
                temp = new char[strlen(c)+1];

                for(unsigned int j=0; j<=strlen(c); j++)
                    temp[j] = c[j];
            }

            c = strtok(nullptr, " , ");
        }
    }

    fclose(file);

    FILE *output = fopen("output.txt", "w");

    unorderedArray(*unArray, n, randomPairs, *output);

    orderedArray(*unArray, n, randomPairs, *output);

    simpleBinaryTree(*simpleTree, n, randomPairs, *output);

    avlTree(*avl, n, randomPairs, *output);

    hashing(*hashtable, n, randomPairs, *output);

    timer = clock() - timer;
    timeConsumed = (float)timer/CLOCKS_PER_SEC;

    string convert = toString(timeConsumed);

    fputs("Total time consumed: ", output);
    fputs(&convert[0], output);
    fputs(" sec.", output);

    fclose(file);

    return 0;
}
