// 7. Crear una clase llamada Caja que contenga los siguientes atributos:
// • capacidad: volumen que puede caber en la caja en cm3
// • volumen: volumen de la caja
// • contenido: lista de objetos (cajas o productos)
// • peso: peso de la caja
// Y los siguientes métodos:
// • agregarObjeto: agrega un objeto a la lista de objetos en caso la caja aun
// tenga capacidad, en caso contrario debe verificar si alguna caja de la lista
// posee el espacio suficiente para guardar el objeto. En caso ninguna caja o
// sub caja pueda guardar el objeto imprime en consola que no hay espacio.
// • calcularPeso: retorna el peso de la caja.
// La clase Producto debe contener los siguientes atributos:
// • volumen: volumen del producto
// • peso: peso del producto

class Objeto
{

public:
    float peso;
    float volumen;
    Objeto* siguiente;
};
class Producto: public Objeto
{
public:
    Producto(float peso, float volumen);
};


class Caja : public Objeto
{
public:
    float capacidad;
    Objeto* primerContenido;
    Caja(float capacidad);
    void AgregarObjeto(Objeto* obj);
    void CalcularPeso();
};

