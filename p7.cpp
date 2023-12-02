#include "p7.h"
#include <iostream>


Producto::Producto(float peso, float volumen)
{
    this->peso=peso;
    this->volumen=volumen;
    this->siguiente=nullptr;
}

Caja::Caja(float capacidad)
{
    this->peso=0;
    this->volumen=0;
    this->capacidad=capacidad;
    this->primerContenido=nullptr;
}

void Caja::AgregarObjeto(Objeto *obj)
{
    if(obj->volumen<=(this->capacidad-this->volumen))
    {
        if(this->primerContenido==nullptr)
        {
            this->primerContenido=obj;
            this->volumen+=obj->volumen;
            this->peso+=obj->peso;
        }
        else{
            Objeto* pPtr = this->primerContenido;
            while (pPtr->siguiente!=nullptr)
            {
                pPtr=pPtr->siguiente;
            }
            pPtr->siguiente=obj;
            this->volumen+=obj->volumen;
            this->peso+=obj->peso;
            
        }
    }
    else{
        std::cout<<"No hay espacio disponible"<<std::endl;
    }
}
void Caja::CalcularPeso()
{
    std::cout<<"La caja pesa "<<this->peso<<" Kg"<<std::endl;
}

