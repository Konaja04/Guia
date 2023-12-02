
#include <iostream>

using namespace std;


class Parametro
{
public:
    Parametro* Siguiente;
    Parametro(/* args */);
};

class Valor : public Parametro
{
public:
    int valor;
    Valor(int valor);
};


class Funcion : public Parametro
{
public:
    Parametro* pPrimer;
    std::string nombre = "";
    Funcion(string nombre, string parametro);
    string formarLlamadaPython();
    string formarLlamadaRacket();
};

