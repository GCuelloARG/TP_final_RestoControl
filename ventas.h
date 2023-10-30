#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED
#include <iostream>
#include <cstring>
#include "globales.h"
#include "clientes.h"
#include "detalle.h"

using namespace std;

class Venta{
private:
        int numVenta;
        Fecha fechaVenta;
        int idCli;
        float precioTotal;
        bool estado;

public:
        void setNumVenta(int nv) {numVenta=nv;}
        void setFecha(Fecha f){fechaVenta=f;}
        void setPrecioTotal(float pt){precioTotal=pt;}
        void setEstado(bool e){estado=e;}
        void setCliente(int i){idCli=i;}

        int getNumVenta(){return numVenta;}
        Fecha getFechaVenta(){return fechaVenta;}
        float getPrecioTotal(){return precioTotal;}
        bool getEstado(){return estado;}


        void Cargar(){
        }

        void Mostrar(){
            int id;
            cout << "Numero de venta: ";
            cout << numVenta;
            cout << "Fecha: ";
            fechaVenta.Mostrar();
            cout << "Precio total: $";
            cout << precioTotal;
            cout << endl;
        }
};

class ArchivoVenta{
    private:
            char nombre[30];
    public:
            ArchivoVenta(const char *nom){
                strcpy(nombre, nom);
            }

            bool agregarRegistro(Venta reg){
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
                Venta reg;
                FILE *p=fopen(nombre,"rb");
                if(p==NULL){
                    cout<<"ERROR DE ARCHIVO"<<endl;
                    return -2;
                }

                int cont=0;
                while(fread(&reg, sizeof reg, 1, p)==1){
                    if(id==reg.getNumVenta()){
                        fclose(p);
                        return cont;
                    }
                    cont++;
                }
                fclose(p);
            return -1;
            }

            Venta leerRegistro(int pos){
                Venta reg;
                reg.setEstado(false);

                FILE *p=fopen(nombre, "rb");
                if(p==NULL){
                    cout<<"ERROR DE ARCHIVO"<<endl;
                    return reg;
                }

                fseek(p, sizeof reg*pos, 0);
                fread(&reg, sizeof reg, 1, p);
                fclose(p);

                return reg;
            }

            bool modificarRegistro(int pos, Venta reg){
                FILE *p=fopen("ventas.dat", "rb+");
                if(p==NULL){
                    cout<<"ERROR DE ARCHIVO"<<endl;
                    return false;
                }

                fseek(p, sizeof reg*pos, 0);
                bool escribio=fwrite (&reg, sizeof reg, 1, p);
                fclose(p);

                return escribio;
            }

            bool bajaLogica(){
                ArchivoVenta archi ("ventas.dat");
                int nv, pos;
                cout << "Ingrese el NUMERO DE VENTA a dar de baja: ";
                cin >> nv;
                pos=archi.buscarRegistro(nv);
                if(pos==-1){
                    cout<<"No existe un registro con ese NUMERO DE VENTA"<<endl;
                    return false;
                } else {
                    if(pos==-2){
                        cout<<"ERROR DE ARCHIVO"<<endl;
                        return false;
                    }
                }

                Venta reg=archi.leerRegistro(pos);
                reg.setEstado(false);
                bool quePaso=archi.modificarRegistro(pos, reg);
                if(quePaso==true){
                    cout<<"Venta eliminada con exito"<<endl;
                }else{
                    cout<<"No se pudo eliminar el registro"<<endl;
                }
                return true;
            }

            int contarRegistros(){
                FILE *p=fopen("ventas.dat", "ab");
                if(p==NULL){
                    cout << "ERROR DE ARCHIVO" <<endl;
                    system("pause");
                    return -2;
                }

                fseek(p, 0,2);
                int tam=ftell(p);
                fclose(p);

                return tam/sizeof (Detalle);
            }

            bool modificarFecha(){
                ArchivoVenta archi("ventas.dat");
                int nv;
                int pos;
                Fecha fec;
                cout<<"Ingrese el NUMERO DE VENTA: ";
                cin>>nv;

                pos=archi.buscarRegistro(nv);
                if(pos==-1){
                    cout<<"No existe registro con este NUMERO DE VENTA"<<endl;
                    return false;
                }else{
                    if(pos==-2){
                        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
                        return false;
                    }
                }

                Venta reg=archi.leerRegistro(pos);
                reg.Mostrar();

                cout<<"Ingrese la nueva fecha de venta: "<<endl;
                fec.Cargar();
                reg.setFecha(fec);

                bool whatPass=archi.modificarRegistro(pos, reg);
                if(whatPass==true){
                    cout<<"Registro modificado con exito"<<endl;
                }else{
                    cout<<"No se pudo modificar el registro"<<endl;
                }

                cout<<endl;
                return true;
            }

            void copiaDeSeguridad(){
                FILE* p;
                FILE* pBackUp;

                p = fopen("ventas.dat", "rb");

                if (p == NULL) {
                    cout << "ERROR DE ARCHIVO" << endl;
                    return;
                }

                pBackUp = fopen("ventas_backup.bkp", "wb");
                if (pBackUp == NULL) {
                    cout << "ERROR DE ARCHIVO" << endl;
                    return;
                }

                Venta reg;
                while (fread(&reg, sizeof reg, 1, p) == 1) {
                    if(reg.getEstado()==true){
                        fwrite(&reg, sizeof reg, 1, pBackUp);
                    }
                }

                fclose(p);
                fclose(pBackUp);
                cout << "Copia de seguridad de VENTAS realizada correctamente" << endl;
            }

    /// LISTAR REGISTROS >> para opc "VER" en menu (?)
};

/*void mostrarListaVentas(){
    Venta ven;
    ArchivoVenta arcVen("ventas.dat");
    int cantReg=arcVen.contarRegistros();
    for(int i=0;i<cantReg;i++){
        ven=arcVen.leerRegistro(i);
        if (ven.getEstado()==true){
            ven.Mostrar();
        }else{
            cout<<endl<<"VENTA eliminada"<<cout;
            ven.Mostrar();
    }

}*/

int traerNumeroVenta(){
    ArchivoVenta arcVen("ventas.dat");
    int numVen;
    numVen=arcVen.contarRegistros();

    return numVen+1;
}

void limpiarArchivoVentas(){
    FILE *p=fopen("ventas.dat","wb");
    cout<<endl<<"Archivo BORRADO"<<endl;
    fclose(p);
}

void nuevaVenta(){
    ArchivoVenta arcVen("ventas.dat");
    Venta reg;
    int nv=traerNumeroVenta();
    reg.setNumVenta(nv);
    float total;
    Fecha fec;
    fechaActual(fec);
    reg.setFecha(fec);
    cout<<"Comanda n"<<(char)167<<": "<<nv;
    //preguntar por cliente, si no existe dejarlo en blanco > lo trae, todavia no lo escribe
    int ic;
    char nombre[30];
    cout << "\nID CLIENTE: ";
    cin >> ic;
    reg.setCliente(ic);
    traerNombreCliente(ic, nombre); ///Quizas habria que mostrar solo el nombre, pero traer el cliente entero, para despues setCliente en obj venta << no creo que haga falta, si traer direccion "ponele" en caso de envios, pero no lo se
    cout<<endl<<"Cliente: "<< nombre;

    total=cargarDetalle(nv); //>> desarrollar falta subtotal < OK
    reg.setPrecioTotal(total);
    reg.setEstado(true);
    cout<<"Total: $"<<total;
    //>> pasar por parametro numero de venta para identificar al detalle OK
    //leer archivo detalle>> calcular total

}

void listarPorNumVenta(){//incompleta, el archivo venta solo mostraria una parte, falta mostrar el detalle y eso se hace reccoriendo det.dat y trayendo lo que coincida con el nv
    Venta ven;
    ArchivoVenta arcVen("ventas.dat");
    int nv;
    cout<<endl<<"Ingrese el NUMERO DE VENTA: ";
    cin>>nv;
    int pos=arcVen.buscarRegistro(nv);
    if(pos>0){
        ven=arcVen.leerRegistro(pos);
        if (ven.getEstado()==true){
            cout<<endl<< "Detalle venta no. "<<nv<<":"<<endl;
            ven.Mostrar();
        }else{
            cout<<endl<<"Esta venta fue dada de baja."<<endl;
            cout<<"Detalle venta no. "<<nv<<":"<<endl;
            ven.Mostrar();
        }
    }else{
        cout<<endl<<"No existe una venta con ese NUMERO DE VENTA";
    }
}

void bajaLogicaVenta(){//no creo que haga falta, uno no deberia poder alterar las ventas que hizo, es evasion de impuestos-- tener en cuenta
    ArchivoVenta archi ("ventas.dat");
    int nv, pos;
    cout<<"Ingrese el NUMERO DE VENTA a eliminar: ";
    cin>>nv;
    pos=archi.buscarRegistro(nv);
    if(pos==-1){
        cout<<endl<<"No existe VENTA con ese numero"<<endl;
        return;
    } else {
        if(pos==-2){
            cout<<endl<<"ERROR DE ARCHIVO - baja"<<endl;
            return;
        }
    }
    Venta reg=archi.leerRegistro(pos);
    reg.setEstado(false);
    bool quePaso=archi.modificarRegistro(pos, reg);
    if(quePaso==true){
        cout<<endl<<"VENTA eliminada con exito"<<endl;
    }else{
        cout<<endl<<"No se pudo eliminar la VENTA"<<endl;
    }
    return;
}

#endif // VENTAS_H_INCLUDED
