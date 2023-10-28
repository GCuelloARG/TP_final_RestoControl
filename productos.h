#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <cstring>
#include "globales.h"

using namespace std;

class Producto{
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
        void setprecioUnitario (float n){precioUnitario=n;}
        void setEstado (bool st){estado=st;}

        int getId(){return id;}
        const char *getNombre(){return nombre;}
        const char *getDescripcion(){return descripcion;}
        bool getEstado(){return estado;}
        float getPrecio(){return precioUnitario;}

        void Cargar(int id){

        setId(id);
        cout<<"Nombre: ";
        cargarCadena(nombre,29);
        cout<<"Descripcion: ";
        cargarCadena(descripcion,29);
        cout<<"Precio unitario: $";
        cin >> precioUnitario;
        estado=(true);
        }

        void MostrarId(){
            cout << endl;
            cout << "ID Producto: ";
            cout << id << endl;
            cout << "Nombre: ";
            cout << nombre << endl;
            cout << "Descripcion: ";
            cout << descripcion << endl;
            cout << "Precio Unitario: $";
            cout << precioUnitario << endl << endl;
        }

        void Mostrar(){
            cout << "ID Producto: ";
            cout << id << endl;
            cout << "Nombre: ";
            cout << nombre << endl;
            cout << "Precio Unitario: $";
            cout << precioUnitario << endl<<endl;
        }
};

class ArchivoProducto{
    private:
        char nombre[30];
    public:
        ArchivoProducto (const char *nomb){
            strcpy(nombre, nomb);
        }

        bool agregarRegistro(Producto reg){
            FILE *p=fopen(nombre,"ab");
                if(p==NULL){
                    cout<<"ERROR DE ARCHIVO-ag"<<endl;
                    return false;
                }
            bool escribio=fwrite(&reg, sizeof reg, 1, p);
            fclose(p);
            return escribio;
        }

        int buscarRegistro(int id){
            Producto reg;
            FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                cout<<"ERROR DE ARCHIVO - buscar"<<endl;
                return -2;
            }
            int cont=0;
            while(fread(&reg, sizeof reg,1,p)==1){
                if(id==reg.getId()){
                    fclose(p);
                    return cont;
                    }
                    cont++;
                }
            fclose(p);
            return -1;
            }

        int contarRegistros(){
            FILE *p=fopen(nombre, "rb");
            if(p==NULL){
                cout << "ERROR DE ARCHIVO -contar" <<endl;
                system("pause");
                return -2;
            }
            fseek(p, 0, 2);
            int tam=ftell(p);
            fclose(p);
            return tam/sizeof(Producto);
        }

        Producto leerRegistro(int pos){
            Producto reg;
            FILE *p=fopen(nombre,"rb");
            if (p==NULL){
                cout <<"ERROR DE ARCHIVO -leer"<<endl;
                return reg;
            }
            fseek(p, sizeof(Producto)*pos, 0);
            fread(&reg, sizeof(Producto), 1, p);
            fclose(p);
            return reg;
        }

        bool modificarRegistro(int pos, Producto reg){
            FILE *pProd=fopen("productos.dat", "rb+");
            if(pProd==NULL){
                cout<<"ERROR DE ARCHIVO -modif"<<endl;
                return false;
            }
            fseek(pProd, sizeof (Producto)*pos, 0);
            bool escribio=fwrite (&reg, sizeof(Producto), 1, pProd);
            fclose(pProd);
            return escribio;
        }

};

void limpiarArchivoProductos(){
    FILE *p=fopen("productos.dat","wb");
    cout<<endl<<"Archivo BORRADO"<<endl;
    fclose(p);
}

void nuevoProd(){
    Producto prod;
    ArchivoProducto arcProd("productos.dat");
    int id;
    cout << "ID Producto: ";
    cin >> id;
    int pos=arcProd.buscarRegistro(id);
    if(pos==-1){
        prod.Cargar(id);
        bool escribio=arcProd.agregarRegistro(prod);

        if(escribio==true){
            cout<<endl<<"PRODUCTO agregado con exito.";
        }else{
            cout<<endl<<"Ya existe un PRODUCTO con ese ID";
        }
    }
}

void mostrarListaProductos(){
    Producto prod;
    ArchivoProducto arcProd("productos.dat");
    int cantReg=arcProd.contarRegistros();
    for(int i=0;i<cantReg;i++){
        prod=arcProd.leerRegistro(i);
        if(prod.getEstado()==true){
            prod.Mostrar();
        }
    }
    system("pause");
    system("cls");
}

bool mostrarIDProd(){
    int id;
    bool existe=false;

    Producto reg;
    FILE *p=fopen("productos.dat", "rb");

    if(p==NULL){
        cout << "ERROR DE ARCHIVO - mostrar";
        return false;
    }
    cout << "Ingrese ID: ";
    cin >> id;

    while (fread(&reg, sizeof reg, 1,p)==1){
        if(id == reg.getId()){
            if(reg.getEstado()==true){
            reg.MostrarId();
            cout<<endl;
            existe=true;
            system("pause");
            system("cls");
        }else{
            cout << endl << "El PRODUCTO fue dado de baja" << endl;
            existe=true;
            }
        }
    }

    fclose(p);

    if(existe==false){
        cout << endl << "No hay PRODUCTO con ese ID"<<endl;
    }
    return existe;

    /*Producto prod;
    ArchivoProducto arcProd("productos.dat");
    int id;
    cout<<"Ingrese el ID del producto: ";
    cin>>id;
    int pos=arcProd.buscarRegistro(id);
    if(pos>0){
    prod=arcProd.leerRegistro(pos);
    prod.Mostrar();
    }else{cout<<"No existe producto con este ID";}*/

}

void bajaLogicaProd(){
    ArchivoProducto arc ("productos.dat");
    int id, pos;
    cout << "Ingrese el ID a dar de baja: ";
    cin >> id;
    pos=arc.buscarRegistro(id);
    if(pos==-1){
        cout<<endl<<"No existe el PRODUCTO con ese ID"<<endl;
        return;
    } else {
        if(pos==-2){
            cout<<endl<<"ERROR DE ARCHIVO - baja"<<endl;
            return;
        }
    }

    Producto reg=arc.leerRegistro(pos);
    reg.setEstado(false);
    bool quePaso=arc.modificarRegistro(pos, reg);
    if(quePaso==true){
        cout<<endl<<"PRODUCTO borrado con exito"<<endl;
    }else{
        cout<<endl<<"No se pudo borrar el PRODUCTO"<<endl;
    }
    return;
}

#endif // PRODUCTOS_H_INCLUDED
