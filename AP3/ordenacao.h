#ifndef ORDENACAO
#define ORDENACAO
#include <iostream>
using namespace std;
/*
 *cabeçalho dos algortimos de ordenação default 
 *códigos aproveitados dos algoritmos aprendidos em sala de aula
 
 Gabriel Viana Raulino

*/
//----------------------------------- Bubble ------------------------------------------------------

void bubbleSort(int A[], int n);
//------------------------------------------- insertion sort --------------------------------------
void insertionsort(int A[], int n);
//------------------------------------------- selection sort --------------------------------------
void selectionsort(int A[], int n);

//--------------------------------------------------- merge sort ----------------------------------
void Intercala(int A[], int p, int q, int r);


void mergesort(int A[], int p, int r);


void mergesort(int A[], int n);


void mergesort_aux(int A[], int n);

//------------------------------------------ quick sort -------------------------------------------
int partitionsort(int A[], int p, int r);

void quicksort(int A[], int p, int r);
void quicksort(int A[], int n);

#endif