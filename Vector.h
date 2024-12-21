#include <iostream>


class Vector{
private: 
        int capacity;
        int size;
        int *array;
public:
        Vector(){
            capacity = 10;
            size = 10;
            array=new int [capacity];
        }

        ~Vector(){
            delete[] array;
        }
};