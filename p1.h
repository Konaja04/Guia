// 1. Crear una clase llamada ListaEnlazada que contenga una lista enlazada y los
// siguientes métodos:
// • agregarElemento: agrega un elemento en la posición indicada.
// • eliminarElemento: elimina un elemento en la posición indicada.
// • verValor: retorna el valor de la posición indicada.
// • cantidadElementos: muestra la cantidad de elementos que posee la lista
// enlazada.
#pragma once    
#include <iostream>
class Nodo
{
    public:
        int valor;
        Nodo* siguiente;
        Nodo(int valor); 
};

class ListaEnlazada
{
public:
    Nodo* pPrimer;
    ListaEnlazada();
    int cant;
    void agregarElemento(int valor, int pos);
    void eliminarElemento(int pos);
    int verValor(int pos);
    int cantidadElementos();
    void imprimir();
};
