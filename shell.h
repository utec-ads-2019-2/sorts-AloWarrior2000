#ifndef SHELL_H
#define SHELL_H

#include "sort.h"

class ShellSort : public Sort {       
    public:
        ShellSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() override {
            for (size_t sepSize = size/2;  sepSize > 0; sepSize/=2) {
                for (size_t i = sepSize; i < size; ++i) {
                    int temp = elements[i];
                    size_t j;
                    for (j = i; j >=sepSize && elements[j-sepSize] > temp; j-=sepSize) {
                        elements[j] = elements[j-sepSize];
                    }
                    elements[j] = temp;
                }
            }
        }

        inline string name() override { return "ShellSort"; }
};

#endif