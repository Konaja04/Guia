#include "p11-12.h"
//===========================PIEZAS=======================
Pieza::Pieza(string color)
{
    this->simbolo = "";
    this->coorX = 0;
    this->coorY = 0;
    this->color = color;
}
Peon::Peon(string color) : Pieza(color)
{
    this->simbolo = "P";
}
Rey::Rey(string color) : Pieza(color)
{
    this->simbolo = "R";
}
Reina::Reina(string color) : Pieza(color)
{
    this->simbolo = "F";
}
Torre::Torre(string color) : Pieza(color)
{
    this->simbolo = "T";
}
Alfil::Alfil(string color) : Pieza(color)
{
    this->simbolo = "A";
}
Caballo::Caballo(string color) : Pieza(color)
{
    this->simbolo = "C";
}

//===========================TABLERO)=======================
Fila::Fila()
{
    this->PrimeraCasilla = nullptr;
    this->siguienteFila = nullptr;
}

void Fila::agregarCasilla()
{
    casilla *nuevaCasilla = new casilla();
    if (this->PrimeraCasilla == nullptr)
    {
        this->PrimeraCasilla = nuevaCasilla;
    }
    else
    {
        casilla *ptr = this->PrimeraCasilla;
        while (ptr->siguiente != nullptr)
        {
            ptr = ptr->siguiente;
        }
        ptr->siguiente = nuevaCasilla;
    }
}

void Fila::colocarPiezaPos(int X, Pieza *pieza)
{
    int conta = 1;
    casilla *ptr = this->PrimeraCasilla;
    while (ptr != nullptr)
    {
        if (X == conta)
        {
            ptr->pieza = pieza;
        }
        conta++;
        ptr = ptr->siguiente;
    }
}

void Fila::imprimir()
{
    casilla *ptr = this->PrimeraCasilla;
    while (ptr != nullptr)
    {
        if (ptr->pieza == nullptr)
        {
            cout << "[ ]";
        }
        else
        {
            cout << "[" << ptr->pieza->simbolo << "]";
        }
        ptr = ptr->siguiente;
    }
    cout << endl;
}

casilla::casilla()
{
    this->pieza = nullptr;
    this->siguiente = nullptr;
}

PartidaAjedrez::PartidaAjedrez()
{
    this->primeraFila = new Fila();
    Fila *ptr = this->primeraFila;
    for (int i = 0; i < 8; i++)
    {
        ptr->siguienteFila = new Fila();
        for (int j = 0; j < 8; j++)
        {
            ptr->agregarCasilla();
        }
        ptr = ptr->siguienteFila;
    }
    reiniciarPartida();
}

void PartidaAjedrez::verTurno()
{
    cout << "Es turno de las " << this->turno << endl;
}

void PartidaAjedrez::mostraPartida()
{
    Fila *ptr = this->primeraFila;
    int conta = 1;
    cout << "PARTIDA DE AJEDREZ" << endl;
    cout << "    A  B  C  D  E  F  G  H" << endl;
    while (ptr->siguienteFila != nullptr)
    {
        cout << conta << "->";
        ptr->imprimir();
        ptr = ptr->siguienteFila;
        conta++;
    }
}

void PartidaAjedrez::moverPieza(char ColOR, int FilaOR, char deCol, int deFila)
{
    Fila *ptr = this->primeraFila;
    Pieza *aux = nullptr;
    int contaX = 1;
    int contaY = 1;
    casilla *pointer = nullptr;
    while (ptr != nullptr)
    {
        if (contaX = FilaOR)
        {
            pointer = ptr->PrimeraCasilla;
            while (pointer != nullptr)
            {
                if (contaY == ((int)ColOR) - 64)
                {
                    aux = pointer->pieza;
                    pointer->pieza = nullptr;
                }
                pointer = pointer->siguiente;
                contaY++;
            }
        }
        contaX++;
        ptr = ptr->siguienteFila;
    }
    ptr = this->primeraFila;
    aux = nullptr;
    contaX = 1;
    contaY = 1;
    while (ptr != nullptr)
    {
        if (contaX = deFila)
        {
            pointer = ptr->PrimeraCasilla;
            while (pointer != nullptr)
            {
                if (contaY == ((int)deCol) - 64)
                {
                    pointer->pieza = aux;
                }
                pointer = pointer->siguiente;
                contaY++;
            }
        }
        contaX++;
        ptr = ptr->siguienteFila;
    }
    if (this->turno == "Blancas")
    {
        this->turno = "Negras";
    }
    else
    {
        this->turno = "Blancas";
    }
}

void PartidaAjedrez::reiniciarPartida()
{
    Fila *ptr = this->primeraFila;
    while (ptr->siguienteFila != nullptr)
    {
        casilla *pointer = ptr->PrimeraCasilla;
        while (pointer != nullptr)
        {
            pointer->pieza = nullptr;
            pointer = pointer->siguiente;
        }
        ptr = ptr->siguienteFila;
    }
    this->turno = "Blancas";
    ptr = this->primeraFila;
    Torre *T1 = new Torre("Blancas");
    ptr->colocarPiezaPos(1, T1);
    Caballo *C1 = new Caballo("Blancas");
    ptr->colocarPiezaPos(2, C1);
    Alfil *A1 = new Alfil("Blancas");
    ptr->colocarPiezaPos(3, A1);
    Rey *R1 = new Rey("Blancas");
    ptr->colocarPiezaPos(4, R1);
    Reina *RA2 = new Reina("Blancas");
    ptr->colocarPiezaPos(5, RA2);
    Alfil *A2 = new Alfil("Blancas");
    ptr->colocarPiezaPos(6, A2);
    Caballo *C2 = new Caballo("Blancas");
    ptr->colocarPiezaPos(7, C2);
    Torre *T2 = new Torre("Blancas");
    ptr->colocarPiezaPos(8, T2);

    ptr = ptr->siguienteFila;
    Peon *P1 = new Peon("Blancas");
    ptr->colocarPiezaPos(1, P1);
    Peon *P2 = new Peon("Blancas");
    ptr->colocarPiezaPos(2, P2);
    Peon *P3 = new Peon("Blancas");
    ptr->colocarPiezaPos(3, P3);
    Peon *P4 = new Peon("Blancas");
    ptr->colocarPiezaPos(4, P4);
    Peon *P5 = new Peon("Blancas");
    ptr->colocarPiezaPos(5, P5);
    Peon *P6 = new Peon("Blancas");
    ptr->colocarPiezaPos(6, P6);
    Peon *P7 = new Peon("Blancas");
    ptr->colocarPiezaPos(7, P7);
    Peon *P8 = new Peon("Blancas");
    ptr->colocarPiezaPos(8, P8);
    for (int i = 0; i < 5; i++)
    {
        ptr = ptr->siguienteFila;
    }
    Peon *P11 = new Peon("Negras");
    ptr->colocarPiezaPos(1, P11);
    Peon *P12 = new Peon("Negras");
    ptr->colocarPiezaPos(2, P12);
    Peon *P13 = new Peon("Negras");
    ptr->colocarPiezaPos(3, P13);
    Peon *P14 = new Peon("Negras");
    ptr->colocarPiezaPos(4, P14);
    Peon *P15 = new Peon("Negras");
    ptr->colocarPiezaPos(5, P15);
    Peon *P16 = new Peon("Negras");
    ptr->colocarPiezaPos(6, P16);
    Peon *P17 = new Peon("Negras");
    ptr->colocarPiezaPos(7, P17);
    Peon *P18 = new Peon("Negras");
    ptr->colocarPiezaPos(8, P18);

    ptr = ptr->siguienteFila;
    Torre *T3 = new Torre("Blancas");
    ptr->colocarPiezaPos(1, T3);
    Caballo *C3 = new Caballo("Blancas");
    ptr->colocarPiezaPos(2, C3);
    Alfil *A3 = new Alfil("Blancas");
    ptr->colocarPiezaPos(3, A3);
    Rey *R3 = new Rey("Blancas");
    ptr->colocarPiezaPos(4, R3);
    Reina *RA4 = new Reina("Blancas");
    ptr->colocarPiezaPos(5, RA4);
    Alfil *A4 = new Alfil("Blancas");
    ptr->colocarPiezaPos(6, A4);
    Caballo *C4 = new Caballo("Blancas");
    ptr->colocarPiezaPos(7, C4);
    Torre *T4 = new Torre("Blancas");
    ptr->colocarPiezaPos(8, T4);
}
