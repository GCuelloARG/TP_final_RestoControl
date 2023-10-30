#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

#include <iostream>
#include <cstring>

using namespace std;

#include "globales.h"


class Cliente{
    private:
        int id;
        char nombre[30];
        char direccion[30];
        int tel;
        bool estado;
    public:
        void setId(int n){id=n;}
        void setNombre(const char *nomb){
            strcpy(nombre, nomb);
        }
        void setDireccion(const char *dir){
            strcpy(direccion, dir);
        }
        void setTel(int t){tel=t;}
        void setEstado(bool st){estado=st;}

        int getId(){return id;}
        const char *getNombre(){return nombre;}
        const char *getDireccion(){return direccion;}
        int getTel(){return tel;}
        bool getEstado(){return estado;}

        void Cargar(int id){
            int t;
            setId(id);
            cout << "Nombre: ";
            cargarCadena(nombre,29);
            cout << "Direccion: ";
            cargarCadena(direccion,29);
            cout << "Telefono: ";
            cin >> t;
            setTel(t);
            estado=(true);
        }

        void MostrarId(){
            cout << endl;
            cout << "ID Cliente: ";
            cout << id << endl;
            cout << "Nombre: ";
            cout << nombre << endl;
            cout << "Direccion: ";
            cout << direccion << endl;
            cout << "Telefono: ";
            cout << tel << endl;
            cout << endl;
        }

        void Mostrar(){
            cout << "ID Cliente: ";
            cout << id << endl;
            cout << "Nombre: ";
            cout << nombre << endl;
            cout << "Direccion: ";
            cout << direccion << endl;
            cout << "Telefono: ";
            cout << tel << endl;
            cout << endl;
        }
};

class ArchivoCliente{
    private:
        char nombre[30];
    public:
        ArchivoCliente(const char *nomb){
            strcpy(nombre, nomb);
        }

        bool agregarRegistro(Cliente reg){
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
            Cliente reg;
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

        Cliente leerRegistro(int pos){
            Cliente reg;
            reg.setEstado(false);
            FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                cout<<"ERROR DE ARCHIVO-leer"<<endl;
                return reg;
            }
            fseek(p,sizeof(Cliente)*pos,0);
            fread(&reg, sizeof (Cliente),1,p);
            fclose(p);
            return reg;
        }

        bool modificarRegistro(int pos, Cliente reg){
            FILE *pCliente=fopen(nombre, "rb+");
            if(pCliente==NULL){
                cout<<"ERROR DE ARCHIVO-mod"<<endl;
                return false;
            }
            fseek(pCliente, sizeof (Cliente)*pos, 0);
            bool escribio=fwrite (&reg, sizeof(Cliente), 1, pCliente);
            fclose(pCliente);
            return escribio;
        }

        int contarRegistros(){
            FILE *p=fopen(nombre, "rb");
            if(p==NULL){
                FILE *p=fopen("clientes.dat", "wb");
                return 0;
                if(p==NULL){
                    cout << "ERROR DE ARCHIVO -contar" <<endl;
                    system("pause");
                    return -2;
                }
            }
            fseek(p, 0,2);
            int tam=ftell(p);
            fclose(p);
            return tam/sizeof(Cliente);
        }
};

void nuevoCliente(){
    Cliente cli;
    ArchivoCliente arcCli("clientes.dat");
    int id;
    cout<<"ID de CLIENTE: ";
    cin>>id;
    int pos=arcCli.buscarRegistro(id);
    bool escribio=false;
    if(pos==-1){
        cli.Cargar(id);
        escribio=arcCli.agregarRegistro(cli);
    }
    if(escribio==true){
        cout<<endl<<"CLIENTE agregado con exito"<<endl;
        system("pause");
        system("cls");
    }else{
        cout<<endl<<"Ya existe un CLIENTE con ese ID"<<endl;
        system("pause");
        system("cls");
    }
}

void mostrarListaClientes(){
    Cliente cli;
    ArchivoCliente arcCli("clientes.dat");
    int cantReg=arcCli.contarRegistros();
    for(int i=0;i<cantReg;i++){
        cli=arcCli.leerRegistro(i);
        if(cli.getEstado()==true){
        cli.Mostrar();
        }
    }
    system("pause");
    system("cls");
}

void limpiarArchivoClientes(){
    FILE *p=fopen("clientes.dat","wb");
    cout<<endl<<"Archivo BORRADO"<<endl;
    fclose(p);
}

void darAltaCli(int num, Cliente cl, ArchivoCliente archi){
    char letra;
    int pos;
    cout<<"Quiere dar de alta el CLIENTE?    Y/N: ";
    cin>>letra;
    if(letra=='Y'||letra=='y'){
        cl.setEstado(true);
        pos=archi.buscarRegistro(num);
        archi.modificarRegistro(pos, cl);
        cout<<endl<<"El producto fue dado de alta"<<endl;
    }else if(letra=='N'||letra=='n'){
        cout<<endl<<"El producto no fue modificado"<<endl;
    }
}

void mostrarIDCli(){
    Cliente cli;
    ArchivoCliente arcCli("clientes.dat");
    int id;
    cout<<endl<<"Ingrese el ID del CLIENTE: ";
    cin>>id;
    int pos=arcCli.buscarRegistro(id);
    if(pos>0){
        cli=arcCli.leerRegistro(pos);
        if(cli.getEstado()==true){
            cli.Mostrar();
        }else{
            cout<<endl<<"El CLIENTE fue dado de baja"<<endl;
            cli.Mostrar();
            darAltaCli(id, cli, arcCli);
        }
    }else{
        cout<<endl<<"No existe CLIENTE con este ID";
    }
}

void bajaLogicaCli(){
    ArchivoCliente archi("clientes.dat");
    int id, pos;
    cout << "Ingrese el ID del CLIENTE a borrar: ";
    cin >> id;
    pos=archi.buscarRegistro(id);
    if(pos==-1){
        cout<<"No existe CLIENTE con ese ID"<<endl;
        return;
    } else {
        if(pos==-2){
            cout<<"ERROR DE ARCHIVO - baja"<<endl;
            return;
        }
    }
    Cliente reg=archi.leerRegistro(pos);
    reg.setEstado(false);
    bool quePaso=archi.modificarRegistro(pos, reg);
    if(quePaso==true){
        cout<<endl<<"CLIENTE borrado con exito"<<endl;
        system("pause");
        system("cls");
    }else{
        cout<<endl<<"No se pudo borrar el CLIENTE"<<endl;
        system("pause");
        system("cls");
    }
}


void traerNombreCliente(int ic, char *vec){
    ArchivoCliente arcCli("clientes.dat");
    Cliente reg;
    int cant=arcCli.contarRegistros();
    for(int i=0; i<cant;i++){
        reg=arcCli.leerRegistro(i);
        if(reg.getId()==ic){
            strcpy(vec, reg.getNombre());
        }
    }
}


#endif // CLIENTES_H_INCLUDED
