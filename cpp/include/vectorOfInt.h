#ifndef VECTOR_OF_INT_H
#define VECTOR_OF_INT_H

class vectorOfInt
{
    public:

    vectorOfInt ();
    vectorOfInt (int);
    int get (int);
    void set (int, int);
    void push_back (int);
    void push_front (int);
    vectorOfInt& operator= (const vectorOfInt &);
    vectorOfInt (const vectorOfInt &);
    ~vectorOfInt();
    int size ();
    void print ();

    private:
    
    int *arr;
    int curr_index;
    int capacity;
};

#endif
