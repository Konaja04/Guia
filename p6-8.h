// 6. Crear una clase llamada HojaCalculo que represente una hoja de calculo similar a la
// de un excel. Para esto la clase deberá contener una lista de filas, cada fila debe
// contener una lista de celdas. Todas las filas de la hoja de calculo deben contener la
// misma cantidad de celdas. HojaCalculo debe contener los siguientes métodos:
// • agregarFila: agrega una fila a la hoja de cálculo.
// • agregarColumna: agrega una columna a la hoja de cálculo, es decir agrega
// una celda a todas las filas.
// • verValor: retorna el valor ubicado en la fila y columna indicada.
// • asignarValor: asigna el valor ingresado en la celda indicada.
// • mostrarHoja: muestra la hoja de cálculo en la consola.
// Recordar qué puede crear las clases auxiliares que considere necesarias.

class Celda
{
public:
    int valor;
    Celda* siguiente;
    Celda(int valor);
};
class Fila
{  
public:
    Celda* pPrimeraCelda;
    Fila* siguiente;
    Fila();
    void IngresarCelda();
    void IngresarCeldaPos(int valor, int pos);
    void ImprimirFila();
};
class HojaCalculo
{
public:
    Fila* pPrimeraFila;
    HojaCalculo();  
    void agregarFila();
    void agregarCol();
    void verValor(int posFila, int posCol);
    void asignarValor(int fila, int columna, int valor);
    void mostrarHoja();
    Celda* retornarCeldaPos(int fila,int columna);
    void AsignarValorSuma(int fila1,int columna1, int fila2, int columna2, int fila_destino, int columna_destino);
    void AsignarValorResta(int fila1,int columna1, int fila2, int columna2, int fila_destino, int columna_destino);
};


