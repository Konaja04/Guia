#include "p6-8.h"
#include <iostream>
Celda::Celda(int valor)
{
    this->valor=valor;
    this->siguiente=nullptr;
}

Fila::Fila()
{
    this->pPrimeraCelda=nullptr;
    this->siguiente=nullptr;
}

void Fila::IngresarCelda()
{
    Celda* nuevaCelda = new Celda(0);
    if(this->pPrimeraCelda==nullptr)
    {
        this->pPrimeraCelda=nuevaCelda;
    }
    else{
        Celda* pPtr = this->pPrimeraCelda;
        while(pPtr->siguiente!=nullptr)
        {           
            pPtr=pPtr->siguiente;
        }
        pPtr->siguiente=nuevaCelda;
    }
}
void Fila::IngresarCeldaPos(int valor, int pos)
{
    Celda* pPtr = this->pPrimeraCelda;
    int conta=0;
    while(pPtr!=nullptr)
    {
        if(conta==pos)
        {
            pPtr->valor=valor;
        }
        pPtr=pPtr->siguiente;
        conta++;
    }
}

void Fila::ImprimirFila()
{
    Celda* pPtr = this->pPrimeraCelda;
    while(pPtr!=nullptr)
    {
        std::cout<<"["<<pPtr->valor<<"]";
        pPtr=pPtr->siguiente;
    }  
    std::cout<<std::endl;
}

HojaCalculo::HojaCalculo()
{
    this->pPrimeraFila=nullptr;
}

void HojaCalculo::agregarFila()
{
    Fila* nuevaFila= new Fila();
    if(this->pPrimeraFila==nullptr)
    {
        this->pPrimeraFila=nuevaFila;
    }
    else{
        Fila* pPtr = this->pPrimeraFila;
        while(pPtr->siguiente!=nullptr)
        {
            
            pPtr=pPtr->siguiente;
        }
        pPtr->siguiente=nuevaFila;
    }
}

void HojaCalculo::agregarCol()
{
    Fila* pPtr = this->pPrimeraFila;
    while(pPtr!=nullptr)
    {
        pPtr->IngresarCelda();
        pPtr=pPtr->siguiente;
    }
}

void HojaCalculo::asignarValor(int fila, int columna, int valor)
{
    Fila* pPtr = this->pPrimeraFila;
    int contafila=0;
    while(pPtr!=nullptr)
    {
        if(fila==contafila)
        {
            pPtr->IngresarCeldaPos(valor,columna);
        }
        pPtr=pPtr->siguiente;
        contafila++;
    }
}

void HojaCalculo::mostrarHoja()
{
    Fila* pPtr = this->pPrimeraFila;
    while(pPtr!=nullptr)
    {
        pPtr->ImprimirFila();
        pPtr=pPtr->siguiente;
    }
}
Celda* HojaCalculo::retornarCeldaPos(int fila,int columna)
{
    Fila* pPtr = this->pPrimeraFila;
    int contafila=0;
    while(pPtr!=nullptr)
    {
        if(fila==contafila)
        {
            Celda* pointer = pPtr->pPrimeraCelda;
            int contacol=0;
            while(pointer!=nullptr)
            {
                if(columna==contacol)
                {
                    return pointer;
                }
                pointer=pointer->siguiente;
                contacol++;
            }
            
        }
        pPtr=pPtr->siguiente;
        contafila++;
    }
}
void HojaCalculo::AsignarValorSuma(int fila1,int columna1, int fila2, int columna2, int fila_destino, int columna_destino)
{
    Celda* pPtrSum1 = retornarCeldaPos(fila1, columna1);
    Celda* pPtrSum2 = retornarCeldaPos(fila2, columna2);
    Celda* pPtrDestino = retornarCeldaPos(fila_destino, columna_destino);
    (pPtrDestino->valor) = pPtrSum1->valor + pPtrSum2->valor;
}
void HojaCalculo::AsignarValorResta(int fila1,int columna1, int fila2, int columna2, int fila_destino, int columna_destino)
{
    Celda* pPtrSum1 = retornarCeldaPos(fila1, columna1);
    Celda* pPtrSum2 = retornarCeldaPos(fila2, columna2);
    Celda* pPtrDestino = retornarCeldaPos(fila_destino, columna_destino);
    (pPtrDestino->valor) = pPtrSum1->valor - pPtrSum2->valor;
}

