#include "p1.h"
#include "p2.h"
#include "p3.h"
#include "p4.h"
#include "p5.h"
#include "p7.h"
#include "p9-10.h"
#include "p11-12.h"
#include <iostream>

int main()
{
    PartidaAjedrez *NuevaPartida = new PartidaAjedrez();
    NuevaPartida->verTurno();
    NuevaPartida->moverPieza('A', 2, 'A', 4);
    NuevaPartida->mostraPartida();
    return 0;
}