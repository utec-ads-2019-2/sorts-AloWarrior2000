#ifndef RADIX_H
#define RADIX_H

#include "sort.h"

class RadixSort : public Sort {       
    public:
        RadixSort(int *elements, size_t size) : Sort(elements, size) {}
        static void printArray(int *array, size_t size) {
            for (size_t i = 0; i < size; i++) {
                cout << array[i] << " ";
            }
            cout << endl;
        }
        static int determine_int_length(const int* array, size_t size2){
            int totalmax = 0;
            for (size_t i = 0; i < size2; ++i) {
                int first = array[i];
                int maxi = 1;
                while (first >= 10){
                    first/=10;
                    maxi++;
                }
                if (maxi > totalmax) totalmax = maxi;
            }
            return totalmax;
        }

    static void Count4Radix(int* _elements, const int* digitArray, size_t _size) {
        int range = 9;
        int indexarray[range + 1];
        int aux[_size];
        memset(indexarray, 0, range + 1);

        // Copia _elements en aux
        for (size_t l = 0; l < _size; ++l) aux[l] = digitArray[l];

        //Llena el indexarray con las repeticiones del array principal
        for (size_t i = 0; i < _size; ++i) indexarray[aux[i]] += 1;

        //Convierte indexarray en su acumulado
        for (size_t j = 0; j < range - 1; ++j) indexarray[j + 1] += indexarray[j];

        //Llena el array principal en base al indexarray acumulado
        for (size_t k = 0; k < _size; ++k) {
            --indexarray[aux[k]];
            _elements[indexarray[aux[k]]] = _elements[k];
        }
    }


        static void FuncRadix(int* array, size_t size1){
            int digits[size1];
            for (int j = 0; j < size1; ++j) {
                digits[j] = array[j]%10;
            }
            printArray(array,size1);
            printArray(digits,size1);
            Count4Radix(array,digits,size1);
        }

        void execute() override {
            FuncRadix(elements, size);
        }

        inline string name() override { return "RadixSort"; }
};

#endif