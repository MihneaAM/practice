#include <iostream>
#include "vectorOfInt.h"

using namespace std;

vectorOfInt::vectorOfInt ()
{
    this->arr = new int [32];
    this->capacity = 32;
    this->curr_index = 0;
}

vectorOfInt::vectorOfInt (int specified_size)
{
    this->arr = new int [specified_size];
    this->capacity = specified_size;
    this->curr_index = 0;
}

int vectorOfInt::get (int index)
{
    if (index < this->capacity)
    {
        return arr[index];
    }
    else
    {
        cout << "out of memory";
        return -1;
    }
}

void vectorOfInt::set (int value, int index)
{
    if (index == this->capacity)
    {
        push_back(value);
    }
    else
    {
        arr[index] = value;
    }
    
}

void vectorOfInt::push_back (int value)
{
    if (this->curr_index == this->capacity)
    {
        int *temp = new int [2 * this->capacity];

        for (int i = 0; i < this->capacity; ++i)
        {
            temp[i] = arr[i];
        }

        delete[] arr;
        this->capacity *= 2;
        arr = temp;
    }

    arr[this->curr_index] = value;
    this->curr_index++;
}

void vectorOfInt::push_front (int value)
{
    if (this->curr_index == this->capacity)
    {
        int *temp = new int [2 * this->capacity];

        for (int i = 0; i < this->capacity; ++i)
        {
            temp[i + 1] = arr[i]; // start with offset 1
        }
        
        delete[] arr;
        this->capacity *= 2;
        arr = temp;  
    }
    else
    {
        for (int i = this->curr_index - 1; i >= 0; --i)
        {
            arr[i + 1] = arr[i];
        }
    }

    this->curr_index ++;
    arr[0] = value;
}

int vectorOfInt::size ()
{
    return this->curr_index;
}

void vectorOfInt::print()
{
    for (int i = 0; i < this->curr_index; i++)
    {
        cout << arr[i] << " ";
    }
    
    cout << endl;
}

int main (int argc, char *argv[])
{
    vectorOfInt v;

    v.push_back (1);
    v.push_back (2);
    v.push_back (3);
    
    cout << v.size() << endl;
    v.print();

    v.push_front (0);
    v.print();

    return 0;
}