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
        cout << "ID Producto: ";
        cout << id << endl;
        cout << "Nombre: ";
        cout << nombre << endl;
        cout << "Descripcion: ";
        cout << descripcion << endl;
        cout << "Precio Unitario: $";
        cout << precioUnitario << endl<<endl;
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
                    cout << "ERROR DE ARCHIVO" <<endl;
                    system("pause");
                    return -2;
                }

                fseek(p, 0,2);
                int tam=ftell(p);
                fclose(p);

                return tam/sizeof (Producto);
            }

        Producto leerRegistro(int pos){
            Producto reg;
            FILE *p=fopen(nombre,"rb");
            if (p==NULL){
                cout <<"ERROR DE ARCHIVO"<<endl;
                return reg;
            }

            fseek(p,sizeof(Producto)*pos, 0);
            fread(&reg, sizeof (Producto),1,p);
            fclose(p);

            return reg;
        }

        bool modificarRegistro(int pos, Producto reg){

                FILE *pProd=fopen("productos.dat", "rb+");
                if(pProd==NULL){
                    cout<<"ERROR DE ARCHIVO"<<endl;
                    return false;
                }

                fseek(pProd, sizeof (Producto)*pos, 0);
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

        void copiaDeSeguridad (){
            FILE *p;
            FILE *pBackUp;

            p=fopen("productos.dat","rb");
            if(p==NULL){
                cout << "ERROR DE ARCHIVO" << endl;
                return;
            }

            pBackUp = fopen ("productos_backup.bkp", "wb");
            if (pBackUp==NULL){
                cout << "ERROR DE ARCHIVO" << endl;
                return;
            }

            Producto reg;
            while (fread(&reg, sizeof reg, 1, p)==1){
                if (reg.getEstado()==true){
                    fwrite(&reg, sizeof reg, 1, pBackUp);
                }

            }
            fclose(p);
            fclose(pBackUp);
            cout << "copia de seguridad de PRODUCTOS realizada correctamente.";
        }

        void restaurarProducto(){

                FILE* p;
                FILE* pBackUp;

                p = fopen("productos.dat", "wb");
                if (p == NULL) {
                    cout << "ERROR DE ARCHIVO - abrir" << endl;
                    return;
                }

                pBackUp = fopen("productos_backup.bkp", "rb");
                if (pBackUp == NULL) {
                    cout << "ERROR DE ARCHIVO - abrir bkp" << endl;
                    return;
                }

                Producto reg;
                while (fread(&reg, sizeof reg, 1, pBackUp) == 1){
                    fwrite(&reg, sizeof reg, 1, p);
                }

                fclose(p);
                fclose(pBackUp);

                cout << "Restauracion de PRODUCTO realizada correctamente" << endl;
            }


};

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
    if(escribio==true)cout<<"Producto agregado con exito.";
    }else{cout<<"Ya existe un producto con ese numero de ID";}
}

void MostrarListaProductos(){
    Producto prod;
    ArchivoProducto arcProd("productos.dat");
    int cantReg=arcProd.contarRegistros();
    for(int i=0;i<cantReg;i++){
        prod=arcProd.leerRegistro(i);
        prod.Mostrar();
    }
}

bool mostrarID(){

    int id;
    bool existe=false;

    Producto reg;
    FILE *p=fopen("productos.dat", "rb");

    if(p==NULL){
        cout << "ERROR DE ARCHIVO - abrir";
        return false;
    }
    cout << "Ingrese ID: ";
    cin >> id;

    while (fread(&reg, sizeof reg, 1,p)==1){
        if(id == reg.getId()){
            if(reg.getEstado()==true){
            reg.Mostrar();
            cout<<endl;
            existe=true;
            system("pause");
            system("cls");
        }else{
            cout << "El PRODUCTO fue dado de baja" << endl;
            existe=true;
            }
        }
    }

    fclose(p);

    if(existe==false){
        cout << "No hay PRODUCTO con ese ID"<<endl;
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
#endif // PRODUCTOS_H_INCLUDED
