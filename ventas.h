#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED
#include <iostream>
#include "globales.h"
#include "clientes.h"
#include "detalle.h"

using namespace std;


class venta{
private:
        int numVenta;
        Fecha fechaVenta;
        Cliente cli;
        Detalle det;
        float precioTotal;
        bool estado;

public:

        void setNumVenta(int nv) {numVenta=nv;} ///

        void setFecha(Fecha f){fechaVenta=f;}
        void setCliente(Cliente c){cli=c;}
        void setDetalle(Detalle d){det=d;}
        void setPrecioTotal(float pt){precioTotal=pt;}
        void setEstado(bool e){estado=e;}

        int getNumVenta(){return numVenta;}
        Fecha getFechaVenta(){return fechaVenta;}
        Cliente getCliente(){return cli;}
        Detalle getDetalle(){return det;}
        float getPrecioTotal(){return precioTotal;}
        bool getEstado(){return e;}

        cont<<;


        void Cargar(){

            int id, pos;

            setNumVenta(nv);
            cout << "Fecha: ";
            fechaVenta.Cargar();
            cout << "ID Cliente: ";
            cin >> id;
            pos=Cliente.buscarRegistro(id);
            cli.leerRegistro(pos);
            cout << "Detalle: ";
            det.Cargar();
            cout << "Precio total: ";
            cin >> pt;
            setPrecioTotal;
            estado=(true);
        }

        void Mostrar(){
            int id;

            cout << "Numero de venta: ";
            cout << numVenta;
            cout << "Fecha: ";
            fechaVenta.Mostrar();
            cout << "Cliente ";
            id=cli.getId();
            cout << id << endl;
            cout << "Detalle: ";
            det.Mostrar();
            cout << "Precio total: $";
            cout << precioTotal;
            cout << endl;
        }

};




class archivoVentas{
private:

public:

};


#endif // VENTAS_H_INCLUDED
