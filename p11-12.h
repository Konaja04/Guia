// 11. Crear una clase PartidaAjedrez que represente una partida de ajedrez y contenga
// los siguientes métodos:
// • verTurno: muestra en la consola que color de piezas se deben mover en este
// turno.
// • mostrarPartida: muestra en la consola el tablero y las fichas en su respectiva
// ubicación. Imprimir también los ejes del tablero.

// • mostrarPosiblesMovimientos: muestra en consola las casillas a las que se
// podría mover la pieza de la casilla indicada. En caso no haya una pieza en
// dicha casilla indicarlo en la consola.
// • moverFicha: recibe de parámetros las coordenadas de la ficha a mover y las
// coordenadas del destino. Mueve la ficha a la casilla indicada en caso sea
// posible, en caso contrario muestra en la consola que la jugada es incorrecta.
// • reiniciarPartida: devuelve todos los valores a su estado inicial.

// Sugerencia: crear una clase abstracta que representa a las piezas y luego crear
// clases hija a partir de esta para cada una de las piezas en particular (peón, caballo,
// etc)
#include <iostream>
#pragma once
using namespace std;
//==============PIEZAS==============
class Pieza
{
public:
    string simbolo;
    int coorX;
    int coorY;
    string color;
    Pieza(string color);
    // virtual void MostrarPos() = 0;
    // virtual void MostrarPosiblesMovs() = 0;
};

class Peon : public Pieza
{
public:
    Peon(string color);
};
class Rey : public Pieza
{
public:
    Rey(string color);
};
class Reina : public Pieza
{
public:
    Reina(string color);
};
class Alfil : public Pieza
{
public:
    Alfil(string color);
};
class Torre : public Pieza
{
public:
    Torre(string color);
};
class Caballo : public Pieza
{
public:
    Caballo(string color);
};
//==============TABLERO==============
class casilla
{
private:
public:
    casilla *siguiente;
    Pieza *pieza;
    casilla();
    void agregarCasilla();
};
class Fila
{
private:
public:
    Fila *siguienteFila;
    casilla *PrimeraCasilla;
    Fila();
    void agregarCasilla();
    void colocarPiezaPos(int X, Pieza *pieza);
    void imprimir();
};

//==============PARTIDA==============

class PartidaAjedrez
{
public:
    Fila *primeraFila;
    PartidaAjedrez();
    string turno;
    void verTurno();
    void mostraPartida();
    void mostrarPosiblesMovimientos(Pieza *pieza);
    void moverPieza(char ColOR, int FilaOR, char deCol, int deFila);
    void reiniciarPartida();
};
