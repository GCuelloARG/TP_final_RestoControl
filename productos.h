#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <cstring>

class Productos{
    private:
        int id;
        char nombre[30];
        char descripcion[30];
        float precioUnitario;
        bool estado;
    public:
        void setId(int n){id=n;}
        void setNombre (const char *nomb){
            strcpy(nombre,nomb);
        }
        void setDescripcion (const char *desc){
            strcpy (descripcion, desc);
        }
        void setprecioUnitario (float n){precioUnitario=n}
        void setEstado (bool st){estado=st;}

        int getId(){return id;}
        const char *getNombre(){return nombre;}
        const char *getDescripcion(){return descripcion;}

        void Cargar(){
        cout<<"Id"<<endl;
        cin>>id;
        cout<<"Nombre"<<endl;
        cargarCadena(nombre,29);
        cout<<"Descripcion"<<endl;
        cargarCadena(nombre,29)
        cout<<"Precio unitario";
        cin >> preciou;

        }

};

class ArchivoProductos{
private:
    char nombre[30];
public:
    agregarRegistro();
    eliminarRegistro();
    modificarRegistro();
    buscarRegistro();
    leerRegistro();

};

#endif // PRODUCTOS_H_INCLUDED
