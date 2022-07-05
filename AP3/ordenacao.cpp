#include "ordenacao.h"


//----------------------------------- Bubble ------------------------------------------------------
void bubbleSort(int A[], int n) {   
    for (int i = 0; i < n-1; ++i) { 
		for (int j = n-1; j > i; --j) { 
			if (A[j] < A[j-1]) { 
				int aux = A[j];
				A[j] = A[j-1];
				A[j-1] = aux; 
			}
		}
	}
}

//------------------------------------------- insertion sort --------------------------------------
void insertionsort(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            --j;
        }
        A[j + 1] = key;
    }
}

//------------------------------------------- selection sort --------------------------------------
void selectionsort(int A[], int n){
    for (int i = 0; i < n-1; i++) {
        int index = i;
        for (int j = i+1; j < n; j++) {
            if(A[j] < A[index])
                index = j;
            int aux = A[index];
            A[index] = aux;    
        }
    }
}

//--------------------------------------------------- merge sort ----------------------------------
void Intercala(int A[], int p, int q, int r) {
	int *W = new int[r-p+1];
	int i = p;
	int j = q+1;
	int k = 0;

	while(i <= q && j <= r) {
		if(A[i] <= A[j])
			W[k++] = A[i++];
		else 
			W[k++] = A[j++];
	}
	while(i <= q) W[k++] = A[i++];
	while(j <= r) W[k++] = A[j++];

	for(i = p; i <= r; i++)
		A[i] = W[i-p];
	
	delete[] W;
}


void mergesort(int A[], int p, int r) {
	if(p < r) {
		int q = (p + r) / 2;
		mergesort(A, p, q);
		mergesort(A, q+1, r);
		Intercala(A, p, q, r);
	}
}


void mergesort(int A[], int n) {
	mergesort(A, 0, n-1);
}


void mergesort_aux(int A[], int n) {
	mergesort(A, 0, n-1);
}

//------------------------------------------ quick sort -------------------------------------------
int partitionsort(int A[], int p, int r) {
	int pivo = A[r];
	int j = p;
	for(int k = p; k < r; k++) {
		if(A[k] <= pivo) {
			int aux = A[k];
			A[k] = A[j];
			A[j] = aux;
			j++;
		}
	}
	A[r] = A[j];
	A[j] = pivo;
	return j;
}

void quicksort(int A[], int p, int r) {
	if(p < r) {
		int i = partitionsort(A, p, r);
		quicksort(A, p, i-1);  
		quicksort(A, i+1, r); 
	}
}

void quicksort(int A[], int n) {
	quicksort(A, 0, n-1);
}
