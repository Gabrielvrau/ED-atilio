#include <iostream>
#include "ORDENACAO.h" 
#include "iterativo.h"
#include "temporizacao.h"
#include "temporizalista.h"
using namespace std;

int main()
{

marca_tempo("QuickSort", quicksort);
marca_tempo("QuickSortIterativo", quickSortIt);
marca_tempo("MergeSort", mergesort);
marca_tempo("MergeSortIterativo", mergeSortIt);
marca_tempo("SelectionSort", selectionsort);
marca_tempo("InsertionSort", insertionsort);
marca_tempo("BubbleSort", bubbleSort);
marcalist("BubbleSortList", bubbleSortList);
marcalist("SelectionSortList", selectionSortList);

}
