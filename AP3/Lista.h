#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "Node.h"
using namespace std;
/**
 * Lista duplamente encadeada circular com nó cabeça
 */
class List
{
private:
    Node *m_head = nullptr; // ponteiro para o nó cabeça
    int m_size = 0;         // o número de elementos na lista

   // função para inserir um novo nó de forma ordenada
    //  em uma lista duplamente encadeada
    void sortedInsert(struct Node **head_ref, struct Node *newNode)
    {
        struct Node *current2;

        // checando se a lista estiver vazia
        if (*head_ref == nullptr)
            *head_ref = newNode;

        // se o nó a ser inserido estiver no inicio
        // da lista duplamente encadeada
        else if ((*head_ref)->valor >= newNode->valor)
        {
            newNode->next = *head_ref;
            newNode->next->prev = newNode;
            *head_ref = newNode;
        }

        else
        {
            current2 = *head_ref;

            // localiza onde o novo nó deve ser inserido
            //    while (current->next != m_head && current->next->valor < newNode->valor){
            while (current2->next != m_head && current2->next->valor < newNode->valor)
            {
                current2 = current2->next;
            }
            /*Faz as ligações apropriadas*/

            newNode->next = current2->next;
            // se um novo nó for inserido no fim da lista
            if (current2->next != m_head)
                newNode->next->prev = newNode;

            current2->next = newNode;
            newNode->prev = current2;
        }
    }

public:
    // construtor vazio: cira lista vazia
    // Complexidade: O(1)
    List()
    {
        m_head = new Node;
        m_head->next = m_head;
        m_head->prev = m_head;
    }
    // adiciona um valor ao final da lista
    // Complexidade: O(1)
    void push_back(const Item &valor)
    {
        Node *aux = new Node;
        aux->valor = valor;
        aux->next = m_head;
        aux->prev = m_head->prev;
        if (m_head->next == m_head)
        {
            m_head->next = aux;
        }
        m_head->prev = aux;
        aux->prev->next = aux;
        m_size++;
    }

    // Imprime elementos na tela
    // Complexidade: O(n)
    void print()
    {
        Node *atual = m_head->next;
        while (atual != m_head)
        {
            std::cout << atual->valor << " ";
            atual = atual->next;
        }
        std::cout << std::endl;
    }

    // deixa a lista vazia
    // Complexidade: O(n)
    void clear()
    {
        while (m_size != 0)
        {
            Node *aux = m_head->prev;
            aux->prev->next = m_head;
            m_head->prev = aux->prev;
            delete aux;
            m_size--;
        }
    }
    // Destrutor
    // Complexidade: O(n)
    ~List()
    {
        clear();       // libera os nós com valores
        delete m_head; // libera o nó cabeça
    }

    /* Bubble sort  */
    void bubbleSortList()
    {
        bool swapped;
        Node *ptr1;

        /* Checando se a lista está vaziaa */
        if (m_head->next == nullptr)
            return;

        do
        {
            // flag de condição de parada
            swapped = false;
            ptr1 = m_head->next;

            while (ptr1->next != m_head) // checa se não chegou ao fim de lista
            {
                if (ptr1->valor > ptr1->next->valor) // verifica a condição de troca
                {
                    swap(ptr1->valor, ptr1->next->valor); // troca os valores dos nós
                    swapped = true;
                }
                ptr1 = ptr1->next; // avança o nó na lista
            }
        } while (swapped);
    }

    // InsertionSort usando lista duplamente encadeada
    void insertionSortList()
    {
        // inicializa um nó chamado sorted
        Node *sorted = m_head;

        // percorre a lista e insere cada nó dentro de sorted
        Node *current = m_head->next;
        while (current != m_head)
        {
            // guarda um nó next para a próxima iteração
            struct Node *next = current->next;

            // remove todos os links e torna current um novo nó a ser inserido em sorted
            current->prev = current->next = nullptr;

            // insere current em sorted duplamente encadeado
            sortedInsert(&sorted, current);

            // atualiza current
            current = next;
        }
        // atualiza o nó cabeça de sorted
        m_head->next = sorted;
    }
    // SelectionSort
    void selectionSortList()
    {
        Node *temp = m_head->next;

        // Percorre a Lista
        while (temp->next != m_head)
        {
            Node *min = temp;
            Node *r = temp->next;

            // Percorre a sublista Desordenada
            while (r != m_head)
            {

                if (min->valor > r->valor)
                    min = r;

                r = r->next;
            }

            // Troca os valores
            int x = temp->valor;
            temp->valor = min->valor;
            min->valor = x;
            temp = temp->next;
        }
    }

    

};

    void bubbleSortList(List* lista){
        lista->bubbleSortList(); // passa o ponteiro da lista criada na função temporizalista e invoca a funçao 
    }

    void insertionSortList(List* lista){
        lista->insertionSortList(); //passa o ponteiro da lista criada na função temporizalista e invoca a funçao
    }

    void selectionSortList(List* lista){
        lista->selectionSortList(); //passa o ponteiro da lista criada na função temporizalista e invoca a funçao
    }


#endif