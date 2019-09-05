#ifndef INSERT_H
#define INSERT_H

#include "sort.h"

class InsertSort : public Sort {       
    public:
        InsertSort(int *elements, size_t size) : Sort(elements, size) {}

        static void swap(int &A, int &B){
            int temp = A;
            A = B;
            B = temp;
        }
        void execute() override {
            for (size_t i = 1; i < size; ++i) {
                int* criticalPos = &elements[i];
                for (size_t j = i; j > 0 ; --j) {
                    if(*criticalPos < elements[j-1]){
                        swap(*criticalPos,elements[j-1]);
                        criticalPos = &elements[j-1];
                    }
                }
            }
        }

        inline string name() override { return "InsertSort"; }
};

#endif