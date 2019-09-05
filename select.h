#ifndef SELECT_H
#define SELECT_H

#include "sort.h"

class SelectSort : public Sort {       
    public:
        SelectSort(int *elements, size_t size) : Sort(elements, size) {}

        static void swap(int &A, int &B){
            int temp = A;
            A = B;
            B = temp;
        }

        void execute() {
            for (int i = 0; i < size-1; ++i) {
                int mainNum = elements[i];
                size_t mainPos = i;
                for (int j = i+1; j < size; ++j) {
                    if (mainNum > elements[j]){
                        mainPos = j;
                        mainNum = elements[j];
                    }
                }
                swap(elements[i],elements[mainPos]);
            }
        }

        inline string name() { return "SelectSort"; }
};

#endif