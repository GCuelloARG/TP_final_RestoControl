#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED
#include <iostream>
#include "fxglobales.h"
#include "clientes.h"
#include "detalle.h"

using namespace std;

/*ventas.dat
numVenta
fechaVenta
cliente
detalle
precioTotal*/

class venta{
private:
        int numVenta;
        Fecha fechaVenta;
        Cliente cli;
        Detalle det;
        float precioTotal;

public:
        cargar();
        mostrar();

        void setFecha()



};

class archivoVentas{
private:

public:

};


#endif // VENTAS_H_INCLUDED
