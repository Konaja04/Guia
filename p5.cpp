#include "p5.h"
#include <iostream>
void LazyColaDePrioridad::InsertarPos(Nodo *nodo, int pos)
{
    Nodo* pPtr = primerNodo();
    if(pos==0)
    {
        nodo->siguiente=primerNodo();
        setprimerNodo(nodo);
        this->longitud++;
    }
    else{
        Nodo* pAnte = nullptr;
        int conta=0;
        while(pPtr!=nullptr)
        {
            if(conta==pos)
            {
                nodo->siguiente=pPtr;
                pAnte->siguiente=nodo;
                this->longitud++;
                return;
            }
            pAnte = pPtr;
            pPtr=pPtr->siguiente;
            conta++;
        }
        pAnte->siguiente=nodo;
    }

}
Nodo* LazyColaDePrioridad::Sacar(int pos)
{
    Nodo* pPtr = this->primerNodo();
    if(pos==0)
    {
        setprimerNodo(pPtr->siguiente);
        pPtr->siguiente=nullptr;
        this->longitud--;
        return pPtr;
    }
    else{
        int conta = 0;
        Nodo* pAnte = nullptr;
        while (pPtr!=nullptr)
        {
            if(conta==pos)
            {
                pAnte->siguiente=pPtr->siguiente;
                pPtr->siguiente=nullptr;
                this->longitud--;
                return pPtr;
            }
            pAnte=pPtr;
            pPtr=pPtr->siguiente;
            conta++;
        }
    }
    return nullptr;
}
Nodo* LazyColaDePrioridad::ObtenerPos(int pos)
{
    Nodo* pPtr = this->primerNodo();
    int conta = 0;
    while (pPtr!=nullptr)
    {
        if(conta==pos)
        {
            return pPtr;
        }
        pPtr=pPtr->siguiente;
        conta++;
    }
    return nullptr;
}
void LazyColaDePrioridad::Intercambiar(int pos1, int pos2)
{
    Nodo* nodo1 = Sacar(pos2);
    InsertarPos(nodo1, pos1);
    Nodo* nodo2 = Sacar(pos1+1);
    InsertarPos(nodo2, pos2);
}
void LazyColaDePrioridad::ordenar()
{
    for (int i = 0; i < this->longitud-1; i++)
    {
        for (int j = 0; j < this->longitud-i-1; j++)
        {
            if(ObtenerPos(j)->valor>ObtenerPos(j+1)->valor)
            {
                this->Intercambiar(j,j+1);
            }
        }
        
    }
    
}

void LazyColaDePrioridad::dequeue()
{   
    ordenar();
    Cola::dequeue();
}
void LazyColaDePrioridad::first()
{
    ordenar();
    Cola::first();
}