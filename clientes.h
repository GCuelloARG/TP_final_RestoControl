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
        strcpy(nombre,nomb);
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
            FILE *p=fopen(nombre,"ab+");
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

        bool bajaLogica(){
            ArchivoCliente archi("cliente.dat");
            int id, pos;
            cout << "Ingrese el ID a dar de baja: ";
            cin >> id;
            pos=archi.buscarRegistro(id);
            if(pos==-1){
                cout<<"No existe el producto con ese ID"<<endl;
                return false;
            } else {
                if(pos==-2){
                    cout<<"ERROR DE ARCHIVO"<<endl;
                    return false;
                }
            }

            Cliente reg=archi.leerRegistro(pos);
            reg.setEstado(false);
            bool quePaso=archi.modificarRegistro(pos, reg);
            if(quePaso==true){
                cout<<"Registro borrado con exito"<<endl;
            }else{
                cout<<"No se pudo borrar el registro"<<endl;
            }
            return true;
        }

        int contarRegistros(){

            FILE *p=fopen("clientes.dat", "rb");
            if(p==NULL){
                cout << "ERROR DE ARCHIVO" <<endl;
                system("pause");
                return -2;
            }

            fseek(p, 0,2);
            int tam=ftell(p);
            fclose(p);

            return tam/sizeof (Cliente);
        }

        /*void restaurarClientes(){

            FILE* p;
            FILE* pBackUp;

            p = fopen("clientes.dat", "wb");
            if (p == NULL) {
                cout << "ERROR DE ARCHIVO - abrir" << endl;
                return;
            }

            pBackUp = fopen("clientes_backup.bkp", "rb");
            if (pBackUp == NULL) {
                cout << "ERROR DE ARCHIVO - abrir bkp" << endl;
                return;
            }

            Cliente reg;
            while (fread(&reg, sizeof reg, 1, pBackUp) == 1){
                fwrite(&reg, sizeof reg, 1, p);
            }

            fclose(p);
            fclose(pBackUp);

            cout << "Restauracion de CLIENTES realizada correctamente" << endl;
        }

        void copiaDeSeguridad(){
            FILE* p;
            FILE* pBackUp;

            p = fopen("clientes.dat", "rb");

            if (p == NULL) {
                cout << "ERROR DE ARCHIVO - abrir" << endl;
                return;
            }

            pBackUp = fopen("clientes_backup.bkp", "wb");
            if (pBackUp == NULL) {
                cout << "ERROR DE ARCHIVO - abrir bkp" << endl;
                return;
            }

            Cliente reg;
            while (fread(&reg, sizeof reg, 1, p) == 1) {
                if(reg.getEstado()==true){
                    fwrite(&reg, sizeof reg, 1, pBackUp);
                }
            }

            fclose(p);
            fclose(pBackUp);
            cout << "Copia de seguridad de CLIENTES realizada correctamente" << endl;
        }*/


};

void nuevoCliente(){
    Cliente cli;
    ArchivoCliente arcCli("clientes.dat");
    int id;
    cout<<"ID :";
    cin>>id;
    int pos=arcCli.buscarRegistro(id);
    if(pos==-1){
    cli.Cargar(id);
    bool escribio=arcCli.agregarRegistro(cli);
    if(escribio==true)cout<<"Cliente agregado con exito.";
    }else{cout<<"Ya existe un cliente con ese numero de ID";}
}

void MostrarListaClientes(){
    Cliente cli;
    ArchivoCliente arcCli("clientes.dat");
    int cantReg=arcCli.contarRegistros();
    for(int i=0;i<cantReg;i++){
        cli=arcCli.leerRegistro(i);
        cli.Mostrar();
    }

}

#endif // CLIENTES_H_INCLUDED
