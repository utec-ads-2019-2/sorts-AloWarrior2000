#ifndef MERGE_H
#define MERGE_H

#include "sort.h"

class MergeSort : public Sort {       
    public:
        MergeSort(int *elements, size_t size) : Sort(elements, size) {}


        static void FuncMergeSort(int* _Array, size_t _Size) {
            if (1 < _Size){
                size_t middle = _Size - _Size/2;
                int* m1 = new int[middle];
                int* m2 = new int[_Size - middle];
                for (size_t i = 0; i < middle; ++i){
                    m1[i] = _Array[i];
                }
                for (size_t j = 0; j < (_Size - middle); ++j){
                    m2[j] = _Array[j+middle];
                }
                FuncMergeSort(m1,middle);
                FuncMergeSort(m2, _Size - middle);

                int A = 0, B = 0, k = 0;
                while (A < middle & B<(_Size - middle)) {
                    if (m1[A] > m2[B]) {
                        _Array[k] = m2[B];
                        B++;
                    } else {
                        _Array[k] = m1[A];
                        A++;
                    }
                    k++;
                }
                while (A<middle){
                    _Array[k] = m1[A];
                    A++;
                    k++;
                }
                while (B<(_Size - middle)){
                    _Array[k] = m2[B];
                    B++;
                    k++;
                }

                }
            }

        void execute() override {
            FuncMergeSort(elements,size);
        }

        inline string name() override { return "MergeSort"; }
};

#endif