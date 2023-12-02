#include "p1.h"

Nodo::Nodo(int valor)
{
    this->valor=valor;
    this->siguiente=nullptr;
}

ListaEnlazada::ListaEnlazada()
{
    this->pPrimer=nullptr;
    this->cant=0;
}

void ListaEnlazada::agregarElemento(int valor, int pos)
{
    Nodo* nuevoNodo = new Nodo(valor);
    if(pos==0)
    {
        nuevoNodo->siguiente=this->pPrimer;
        this->pPrimer=nuevoNodo;
    }
    else{
        Nodo* pPtr = this->pPrimer;
        Nodo* pAnte =nullptr;
        int conta=0;
        while(pPtr!=nullptr)
        {
            if(conta==pos)
            {
                nuevoNodo->siguiente=pPtr;
                pAnte->siguiente=nuevoNodo;
                this->cant++;
                return;
            }
            pAnte = pPtr;
            pPtr=pPtr->siguiente;
            conta++;
        }
        pAnte->siguiente=nuevoNodo;
    }
    this->cant++;
}

void ListaEnlazada::eliminarElemento(int pos)
{
    Nodo* pPtr = this->pPrimer;
    if(pos==0)
    {
        this->pPrimer=pPtr->siguiente;  
        delete pPtr;
    }
    else{
        Nodo* pAnte= nullptr;
        int conta=0;
        while(pPtr!=nullptr)
        {
            if(pos==conta)
            {
                pAnte=pPtr->siguiente;
                delete pPtr;
            }
            pAnte=pPtr;
            pPtr=pPtr->siguiente;
            conta++;
        }
    }
    this->cant--;
}

int ListaEnlazada::verValor(int pos)
{
    Nodo* pPtr = this->pPrimer;
    int conta=0;
    while(pPtr!=nullptr)
    {
        if(pos==conta)
        {
            return pPtr->valor;
        }
        pPtr=pPtr->siguiente;
        conta++;
    }
    return -1;
}

int ListaEnlazada::cantidadElementos()
{
    return this->cant;
}

void ListaEnlazada::imprimir()
{
    Nodo* pPtr = this->pPrimer;
    while(pPtr!=nullptr)
    {
        std::cout<<pPtr->valor<<"->"<<std::endl;
        pPtr=pPtr->siguiente;
    }
}
