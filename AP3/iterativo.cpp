#include "iterativo.h"

// Funcão auxiliar para encontrar o menor de 2 inteiros
int min(int x, int y) { return (x < y) ? x : y; }

// Função auxiliar do quickSort

int partition(int A[], int p, int r)
{
    int pivo = A[r];
    int j = p;
    for (int k = p; k < r; k++)
    {
        if (A[k] <= pivo)
        {
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

// QuickSort Auxiliar
void quicksort_aux(int A[], int p, int r)
{
    if (p < r)
    {
        int i = partition(A, p, r); // Dividir
        quicksort_aux(A, p, i - 1); // Conquistar
        quicksort_aux(A, i + 1, r); // Conquistar
    }
}



/* MergeSort Iterativo para ordenar o vetor arr[0...n-1]*/
void mergeSortIt(int arr[], int n)
{
    int curr_size;  // Tamanho atual dos valores a serem mesclados
                    // tamanho atual varia de 1 até n/2
    int left_start; // Pega o indice inicial do array da esquerda
                    // a ser mesclado

    // Mescla arrays de maneira crescente. Primeira mesclagem de arrays de
    // tamanho 1 para criar arrays classificados de tamanho 2 e, em seguida, mesclar arrays
    // de tamanho 2 para criar arrays classificados de tamanho 4 e assim por diante.

    for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size)
    {
        // Pega o ponto de partida de diferentes arrays de tamanho atual
        for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size)
        {
            // Encontra o ponto final do subvetor da esquerda. mid+1 está começando
            // vetor da direita
            int mid = min(left_start + curr_size - 1, n - 1);

            int right_end = min(left_start + 2 * curr_size - 1, n - 1);
            // Mescla os arrays arr[left_start...mid] e arr[mid+1...right_end]
            mergeSortIt(arr, left_start, mid, right_end);
        }
    }
}

/* Função para juntar as duas partes arr[l..m] e arr[m+1..r] do vetor[] */

void mergeSortIt(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    /* Cria vetores temporários */
    int *L = new int[n1];
    int *R = new int[n2];
    /* copia os dados pros vetores temporários L[] e R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    /* Mistura os arrays temporários no vetor arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    /* Copia os elementos restantes do vetor L[], caso tenha algum */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    /* Copia os elementos restantes do vetor R[], caso tenha algum */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Quicksort Iterativo

void quickSortIt(int a[], int n)
{
    // cria uma Stack de `std::pairs` para armazenar o índice inicial e final do subarray
    stack<pair<int, int>> s;

    // obtém o índice inicial e final do array fornecido
    int start = 0;
    int end = n - 1;

    // coloca o índice inicial e final do array na Stack
    s.push(make_pair(start, end));

    // faz um loop até que a Stack esteja vazia
    while (!s.empty())
    {
        // remove o top pair da lista e inicia o subarray
        // e índices finais
        start = s.top().first, end = s.top().second;
        s.pop();

        // reorganiza os elementos no pivô
        int pivo = partition(a, start, end);

        // envia índices de subarray contendo elementos que são
        // menor que o pivô atual para stack
        if (pivo - 1 > start)
        {
            s.push(make_pair(start, pivo - 1));
        }

        // envia índices de subarray contendo elementos que são
        // mais do que o pivô atual para stack
        if (pivo + 1 < end)
        {
            s.push(make_pair(pivo + 1, end));
        }
    }
}