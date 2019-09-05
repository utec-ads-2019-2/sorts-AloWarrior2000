#ifndef BUBBLE_H
#define BUBBLE_H

#include "sort.h"
#include <algorithm>

class BubbleSort : public Sort {       
    public:
        BubbleSort(int *elements, size_t size) : Sort(elements, size) {}

        static void swap(int &A, int &B){
            int temp = A;
            A = B;
            B = temp;
        }

        void execute() override {
            size_t altSize = size-1;
            for (size_t x = 0; x < size -1; ++x) {
                for (size_t i = 0; i < altSize; ++i) {
                    if (elements[i] > elements[i + 1]) {
                        swap(elements[i], elements[i + 1]);
                    }
                }
                --altSize;
            }
        }

        inline string name() override { return "BubbleSort"; }
};

#endif