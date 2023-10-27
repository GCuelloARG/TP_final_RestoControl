#ifndef DETALLE_H_INCLUDED
#define DETALLE_H_INCLUDED
#include "productos.h"

using namespace std;

class Detalle{
	private:
            int cant;
            float subTotal;
            bool estado;
	public:
            void setEstado(bool st){estado=st;}
            bool getEstado(){return estado;}
            void Cargar();
            void Mostrar();
};

class ArchivoDetalle{
	private:
            char nombre[30];
	public:
            ArchivoDetalle(const char *nom){
            strcpy(nombre, nom);
            }
    };

#endif // DETALLE_H_INCLUDED
