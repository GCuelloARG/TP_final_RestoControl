#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <cstring>
#include "globales.h"

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
        void setprecioUnitario (float n){precioUnitario=n}
        void setEstado (bool st){estado=st;}

        int getId(){return id;}
        const char *getNombre(){return nombre;}
        const char *getDescripcion(){return descripcion;}

        void Cargar(int id){

        setId(id);
        cout<<"Nombre"<<endl;
        cargarCadena(nombre,29);
        cout<<"Descripcion"<<endl;
        cargarCadena(nombre,29)
        cout<<"Precio unitario";
        cin >> precioU;
        estado=(true);
        }


        void Mostrar(){
        cout << "ID Producto: "
        cout << id << endl;
        cout << "Nombre: "
        cout << nombre << endl;
        cout << "Descripcion"
        cout << descripcion << endl;
        cout << "Precio Unitario"
        cout << precioU << endl;
        }
};

class ArchivoProducto{
private:
    char nombre[30];
public:
    archivoProducto (const char *nomb){
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

    Producto leerRegistro(int pos){
        Producto reg;
        FILE *p=fopen(nombre,"rb");
        if (p==NULL){
            cout <<"ERROR DE ARCHIVO"<<endl;
            return reg;
        }

        fseek(p,sizeof(Producto)*pos, 0):
        fread(&reg, sizeof (Producto)1,p);
        fclose(p);

        return reg;
    }


    bool modificarRegistro(int pos, Producto reg){

            FILE pProd=fopen("productos.dat", "rb+");
            if(pProd==NULL){
                cout<<"ERROR DE ARCHIVO"<<endl;
                return false;
            }

            fseek(pProd, sizeof (Producto),pos, 0);
            bool escribio=fwrite (&reg, sizeof(Producto), 1, pProd);
            fclose(pProd);

            return escribio;
        }

    bool bajaLogica(){
            ArchivoProducto arc ("productos.dat");
            int id, pos;
            cout << "Ingrese el ID a dar de baja: ";
            cin >> id;
            pos=arc.buscarRegistro(id);
            if(pos==-1){
                cout<<"No existe el producto con ese ID"<<endl;
                return false;
            } else {
                if(pos==-2){
                    cout<<"ERROR DE ARCHIVO"<<endl;
                    return false;
                }
            }

            Producto reg=arc.leerRegistro(pos);
            reg.setEstado(false);
            bool quePaso=arc.modificarRegistro(pos, reg);
            if(quePaso==true){
                cout<<"Registro borrado con exito"<<endl;
            }else{
                cout<<"No se pudo borrar el registro"<<endl;
            }
            return true;
        }


};

#endif // PRODUCTOS_H_INCLUDED
