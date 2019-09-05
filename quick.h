#ifndef QUICK_H
#define QUICK_H

#include "sort.h"

class QuickSort : public Sort {
    public:
        QuickSort(int *elements, size_t size) : Sort(elements, size) {}

        static void swap(int &A, int &B){
            int temp = A;
            A = B;
            B = temp;
        }


        static void funcQuickSort(int* _List, size_t _size, int pivot, int &pos){
            if (_size > 0) {
                int sizeA = 0,sizeB = 0;
                int ListA[_size];
                int ListB[_size];
                int newpivot;
                for (size_t i = 0; i < _size; ++i) {
                    if (_List[i] <= pivot) {
                        ListA[sizeA] = _List[i];
                        sizeA++;
                    } else {
                        ListB[sizeB] = _List[i];
                        sizeB++;
                    }
                }
                newpivot = ListA[sizeA-1];
                funcQuickSort(ListA,sizeA, newpivot,pos);
                _List[pos] = newpivot;
                pos++;
                newpivot = ListB[sizeB-1];
                funcQuickSort(ListB,sizeB,newpivot,pos);
                _List[pos] = newpivot;
                pos++;
            }
        }


        void execute() override {
            int generalpos = 0;
            funcQuickSort(elements, size, elements[-1], generalpos);
        }

        inline string name() override { return "QuickSort"; }
};

#endif