#include "p4.h"
#include <iostream>
void ColaDePrioridad::enqueue(int valor)
{
    Nodo* nuevoNodo = new Nodo(valor);
    Nodo* pPtr = primerNodo();
    if(pPtr==nullptr)
    {
        setprimerNodo(nuevoNodo);
    }
    else
    {
        if(nuevoNodo->valor<pPtr->valor)
        {
            nuevoNodo->siguiente=pPtr;
            setprimerNodo(nuevoNodo);

        }else{
            Nodo* pAnte = nullptr;
            while (pPtr->siguiente!=nullptr)
            {
                if(nuevoNodo->valor<pPtr->valor)
                {
                    nuevoNodo->siguiente=pPtr;
                    pAnte->siguiente=nuevoNodo;
                    return;
                }
                pAnte = pPtr;
                pPtr=pPtr->siguiente;
            }
            pPtr->siguiente=nuevoNodo;
        }
    }
}
