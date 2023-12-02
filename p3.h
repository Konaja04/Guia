// 3. Crear una clase llamada Cola que contenga una lista y posea solo los siguientes
// métodos:
// • enqueue: agrega un elemento al final de la lista.
// • first: muestra el primer elemento de la lista.
// • dequeue: elimina el primer elemento de la lista.
// La lista de la Cola debe ser privada, es decir no se podrá acceder a ella fuera de la
// clase.
#pragma once
#include "p1.h"

class Cola
{
private:
    Nodo* pPrimer;
public:
    Cola();
    int longitud;
    void enqueue(int valor);
    void first();
    void dequeue();
    Nodo* primerNodo();
    void setprimerNodo(Nodo* N);
};

