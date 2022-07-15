#ifndef PAIR_H
#define PAIR_H


class Pair
{
    public:
        Pair();
        Pair(char *leftword, char *rightword);
        ~Pair();

        char *getPair(){ return &this->pair[0]; }

    protected:

    private:
        char *pair;
};

#endif // PAIR_H
