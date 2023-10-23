#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <cstring>

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

    Producto leerRegistro();
        Producto Reg;
        FILE *p=fopen(nombre,"rb");
        if (p==NULL){
            cout <<"ERROR DE ARCHIVO"<<endl;
            return reg;
        }

        fseek(p,sizeof(Producto)*pos, 0):
        fread(&reg, sizeof (Producto)1,p);
        fclose(p);

        return reg;
};

#endif // PRODUCTOS_H_INCLUDED
