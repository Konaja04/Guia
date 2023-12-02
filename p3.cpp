#include "p3.h"
#include <iostream>
Cola::Cola()
{
    this->pPrimer=nullptr;
    int longitud=0;
}

void Cola::enqueue(int valor)
{
    Nodo* nuevoNodo = new Nodo(valor);
    if(this->pPrimer==nullptr)
    {
        this->pPrimer=nuevoNodo;
    }
    else
    {
        Nodo* pPtr = this->pPrimer;
        while (pPtr->siguiente!=nullptr)
        {
            pPtr=pPtr->siguiente;
        }
        pPtr->siguiente=nuevoNodo;
    }
    this->longitud++;
}
void Cola::first()
{
    std::cout<<"El primer elemento es: "<<pPrimer->valor<<std::endl;
}
void Cola::dequeue()
{
    Nodo* pPtr= this->pPrimer;
    this->pPrimer=pPtr->siguiente;
    std::cout<<"Eliminando "<<pPtr->valor<<std::endl;
    delete pPtr;
    this->longitud--;
}

Nodo *Cola::primerNodo()
{
    return this->pPrimer;
}

void Cola::setprimerNodo(Nodo* N)
{
    this->pPrimer=N;
}
