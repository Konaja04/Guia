// 5. A partir de la clase Cola, crear una clase hija llamada LazyColaDePrioridad la cual
// deberá ordenar sus elementos en orden ascendente solo cuando se desee mostrar
// o eliminar un elemento.
#include "p3.h"
class LazyColaDePrioridad : public Cola
{
private:
    void InsertarPos(Nodo* nodo,int pos);
    void Intercambiar(int pos1, int pos2);
    Nodo* ObtenerPos(int pos);
    Nodo* Sacar(int pos);
    void ordenar();
public:
    void dequeue();
    void first();
};
