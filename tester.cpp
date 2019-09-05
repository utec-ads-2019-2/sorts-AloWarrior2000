#include "tester.h"

Sort* Tester::getSort(Algorithm sort, int *array, size_t size) {
    switch (sort) {
        case BUBBLE: return new BubbleSort(array, size); //TERMINADO
        case COUNTING: return new CountingSort(array, size); //FUNCIONA CON MAX<25 - POR REVISAR
        case SELECT: return new SelectSort(array, size); //TERMINADO
        case INSERT: return new InsertSort(array, size); //TERMINADO
        case SHELL: return new ShellSort(array, size); //TERMINADO
        case QUICK: return new QuickSort(array, size);//POR REVISAR
        case RADIX: return new RadixSort(array, size);//EN PROCESO
        case MERGE: return new MergeSort(array, size); //TERMINADO
        default: throw invalid_argument("Not a valid sort");
    }
}

void Tester::sorts(int *array, size_t size) {
    Sort* sort;
    int temp[size];

    for (int i = RADIX; i <= RADIX; i++) {
        copy(array, array + size, temp);
        sort = getSort(static_cast<Algorithm>(i), temp, size);
        sort->execute();
        ASSERT(is_sorted(temp, temp + size), "The " + sort->name() + " is not ordering all the elements");
    }
}