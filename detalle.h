#ifndef DETALLE_H_INCLUDED
#define DETALLE_H_INCLUDED
#include "productos.h"

using namespace std;

class Detalle{
	private:
            int id;
            int cant;
            //agregar nombre y setearlo desde producto
            float subTotal;
            bool estado;
	public:
            void setID(int i){id=i;}
            void setEstado(bool st){estado=st;}
            void setCant(int c){cant=c;}
            int getId(){return id;}
            int getCant(){return cant;}
            bool getEstado(){return estado;}
            float getSubt(){return subTotal;}
            void Cargar(){
               cout<<"ID";
               cin>>id;
               cout<<"Cant";
               cin>>cant;
            }
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

void cargarDetalle(){
    ArchivoProducto arcProd("productos.dat");
    Detalle det;
    Producto prod;
    int id, cant;
    float sb;
    cout<<"ID ";
    cin>>id;
    while(id!=0){
    det.setID(id);
    int pos=arcProd.buscarRegistro(det.getId());
    prod=arcProd.leerRegistro(pos);
    cout<<prod.getNombre()<<endl;
    cout<<"Cant: ";
    cin>>cant;
    det.setCant(cant);
    cout<<endl;
    //agregar a archivo

    cout<<"ID ";
    cin>>id;
    }


}

#endif // DETALLE_H_INCLUDED
