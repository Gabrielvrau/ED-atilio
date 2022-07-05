/*
 * Algoritmos de Ordenação iterativos usando vetor
 *
  Andre Silva Cavalcanti de Albuquerque
 */

// Protótipos das funções
#ifndef ORDENACAOVETOR_H
#define ORDENACAOVETOR_H

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

// Função auxiliar do quickSort

int partition(int A[], int p, int r);

// QuickSort recursivo usando vetor

void quicksort_aux(int A[], int p, int r);

/* Função para juntar as duas partes arr[l..m] e arr[m+1..r] do vetor[] */

void mergeSortIt(int arr[], int l, int m, int r);


/* MergeSort Iterativo para ordenar o vetor arr[0...n-1]*/

void mergeSortIt(int arr[], int n);

/* QuickSort Iterativo para ordenar o vetor arr[0...n-1]*/

void quickSortIt(int a[], int n);




#endif
