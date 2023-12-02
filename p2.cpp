#include "p2.h"
#include <iostream>
Pila::Pila()
{
    this->pPrimer=nullptr;
    this->pUltimo=nullptr;
}

void Pila::push(int valor)
{
    Nodo* nuevoNodo = new Nodo(valor);
    if(this->pPrimer==nullptr)
    {
        this->pPrimer=nuevoNodo;
        this->pUltimo=nuevoNodo;
    }
    else
    {
        Nodo* pPtr = this->pPrimer;
        while (pPtr->siguiente!=nullptr)
        {
            pPtr=pPtr->siguiente;
        }
        pPtr->siguiente=nuevoNodo;
        this->pUltimo=nuevoNodo;
    }
}
void Pila::peek()
{
    std::cout<<"El ultimo elemento es: "<<pUltimo->valor<<std::endl;
}
void Pila::pop()
{
    Nodo* pPtr = this->pPrimer;
    Nodo* pAnte = nullptr;
    while (pPtr->siguiente!=nullptr)
    {
        pAnte=pPtr;
        pPtr=pPtr->siguiente;
    }
    this->pUltimo=pAnte; 
    pAnte->siguiente=nullptr;
}
