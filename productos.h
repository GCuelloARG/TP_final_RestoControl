#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include "globales.h"
#include "rlutil.h"

using namespace std;

class Producto{
    private:
        int id;
        char nombre[30];
        char descripcion[50];
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
        void setPrecioUnitario (float n){precioUnitario=n;}
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
            cout <<setfill('0')<<setw(4)<< id << endl;
            cout << "Nombre: ";
            cout << nombre << endl;
            cout <<"Descripcion: ";
            cout << descripcion<<endl;
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
                FILE *p=fopen("productos.dat", "wb");
                return 0;
                if(p==NULL){
                    cout << "ERROR DE ARCHIVO -contar" <<endl;
                    system("pause");
                    return -2;
                }
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

void darAltaProd(int num, Producto pr, ArchivoProducto archi){
    char letra;
    int pos;
    cout<<"Quiere dar de alta el producto? Y/N: ";
    cin>>letra;
    if(letra=='Y'||letra=='y'){
        pr.setEstado(true);
        pos=archi.buscarRegistro(num);
        archi.modificarRegistro(pos, pr);
        cout<<endl<<"El producto fue dado de alta"<<endl;
    }else if(letra=='N'||letra=='n'){
        cout<<endl<<"El producto no fue modificado"<<endl;
    }
}

void nuevoProd(){
    Producto prod;
    ArchivoProducto arcProd("productos.dat");
    int id;
    bool escribio=false;
    id=arcProd.contarRegistros()+1;
    cout << "ID Producto: "<<setfill('0')<<setw(4)<<id<<"\n";
    int pos=arcProd.buscarRegistro(id);
    if(pos==-1){
        prod.Cargar(id);
        escribio=arcProd.agregarRegistro(prod);
        }else if(pos>=0){
            if(prod.getEstado()==true){
            cout<<endl<<"Ya existe un PRODUCTO con ese ID."<<endl;
            }else{
            cout<<endl<<"El PRODUCTO con ese ID fue dado de baja."<<endl;
            prod=arcProd.leerRegistro(pos);
            prod.Mostrar();
            cout<<endl;
            darAltaProd(id,prod,arcProd);
            }
        }
    if(escribio==true){
            cout<<endl<<"PRODUCTO agregado con exito."<<endl;
        }
        system("pause");
        system("cls");

}

void mostrarListaProductos(){
    Producto prod;
    ArchivoProducto arcProd("productos.dat");
    int cantReg=arcProd.contarRegistros();
    if(cantReg>0){
        for(int i=0;i<cantReg;i++){
        prod=arcProd.leerRegistro(i);
        if(prod.getEstado()==true){
            prod.Mostrar();
        }
    }
}else{
    cout << "No hay PRODUCTOS ingresados."<<endl;
}
    system("pause");
    system("cls");
}

void mostrarIDProd(){
    Producto prod;
    ArchivoProducto arcProd("productos.dat");
    int id;
    cout<<endl<<"Ingrese el ID del PRODUCTO: ";
    cin>>id;
    system("cls");
    int pos=arcProd.buscarRegistro(id);
    if(pos>=0){
        prod=arcProd.leerRegistro(pos);
        if(prod.getEstado()==true){
            prod.Mostrar();
        }else{
            cout<<endl<<"El PRODUCTO fue dado de baja"<<endl;
            prod.Mostrar();
            darAltaProd(id, prod, arcProd);
        }
    }else{
        cout<<endl<<"No existe PRODUCTO con este ID"<<endl;
    }
    system("pause");
    system("cls");
}

void bajaLogicaProd(){
    ArchivoProducto arc ("productos.dat");
    int id, pos;
    char choice;
    cout << "Ingrese el ID del PRODUCTO: ";
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
    reg.Mostrar();
    cout<<"\nQuiere dar de baja el producto?\tY/N: ";
    cin>>choice;
    if(choice=='Y'||choice=='y'){
    reg.setEstado(false);
    bool quePaso=arc.modificarRegistro(pos, reg);
    if(quePaso==true){
        cout<<endl<<"PRODUCTO borrado con exito"<<endl;
    }else{
        cout<<endl<<"No se pudo borrar el PRODUCTO"<<endl;
        }
    }else if(choice=='N'||choice=='n'){
        cout<<"Operacion cancelada\n";
}
    system("pause");
    system("cls");
}

void cambiarPrecioProducto(){
    Producto prod;
    ArchivoProducto arcProd("productos.dat");
    int id, pos;
    float np;
    char choice;
    cout<<"Ingrese el ID del producto a modificar: ";
    cin>>id;
    pos=arcProd.buscarRegistro(id);
    if(pos==-1){
        cout<<"No existe PRODUCTO con ese ID"<<endl;
        return;
    } else {
        if(pos==-2){
            cout<<"ERROR DE ARCHIVO - modificar"<<endl;
            return;
        }
    }
    prod=arcProd.leerRegistro(pos);
    cout<<endl;
    prod.Mostrar();
    cout<<"Ingrese el nuevo precio: $";
    cin>>np;
    cout<<"El nuevo precio va a ser de: $"<<np<<endl;
    cout<<"Confirmar? Y/N: ";
    cin>>choice;
    if(choice=='Y'||choice=='y'){
        prod.setPrecioUnitario(np);
        bool quePaso=arcProd.modificarRegistro(pos,prod);
        if(quePaso==true){
            system("cls");
            cout<<endl<<"PRODUCTO modificado con exito"<<endl;
            cout<<endl;
            cout<<"El nuevo producto: "<<endl;
            prod.Mostrar();
            system("pause");
            system("cls");
        }else{
            cout<<endl<<"No se pudo modificar el PRODUCTO"<<endl;
        }
    }else if(choice=='N'||choice=='n'){
        cout<<"Operacion cancelada.";
        system("pause");
        system("cls");
    }
    else if(choice!='N'||choice!='n'||choice!='Y'||choice!='y'){
        cout<<"Opcion invalida."<<endl;
        system("pause");
        system("cls");
        return;
    }
}

#endif // PRODUCTOS_H_INCLUDED
