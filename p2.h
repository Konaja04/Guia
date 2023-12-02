#include "p1.h"
// 2. Crear una clase llamada Pila que contenga una lista y posea solo los siguientes
// métodos:
// • push: agrega un elemento al final de la lista.
// • peek: muestra el último elemento de la lista.
// • pop: elimina el último elemento de la lista.
// La lista de la Pila debe ser privada, es decir no se podrá acceder a ella fuera de la
// clase.

class Pila
{
private:
    Nodo* pPrimer;
    Nodo* pUltimo;
public:
    Pila();
    void push(int valor);
    void peek();
    void pop();

};

