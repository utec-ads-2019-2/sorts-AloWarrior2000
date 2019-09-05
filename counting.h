#ifndef COUNTING_H
#define COUNTING_H

#include "sort.h"
#include <algorithm>
#include<bits/stdc++.h>

class CountingSort : public Sort {       
    public:
        CountingSort(int *elements, size_t size) : Sort(elements, size) {}

        static void FuncCountSort(int* _elements, size_t _size){
            int range = 100;
            int indexarray[range + 1];
            int aux[_size];
            memset(indexarray, 0, range + 1);
            for (size_t l = 0; l < _size; ++l) aux[l] = _elements[l];
            for (size_t i = 0; i < _size; ++i) indexarray[aux[i]]+=1;
            for (size_t j = 0; j < range-1; ++j) indexarray[j + 1]+=indexarray[j];
            for (size_t k = 0; k < _size; ++k) {
                --indexarray[aux[k]];
                _elements[indexarray[aux[k]]] =  aux[k];
            }
        }

        void execute() override {
            FuncCountSort(elements,size);
        }

        inline string name() override { return "CountingSort"; }
};

#endif