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
        int getCliente(){return idCli;}

        void Mostrar(){
            cout<<"\t"<<setfill('0')<<setw(4)<<numVenta<<"\t"<<setfill('0')<<setw(4)<<idCli<<"\t";
            fechaVenta.Mostrar();
            cout<<"  \t$"<<precioTotal<<endl;
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
                cout << "Ingrese el NUMERO DE VENTA para anular: ";
                cin >> nv;
                pos=archi.buscarRegistro(nv);
                if(pos==-1){
                    cout<<"No existe un registro con ese NUMERO DE VENTA"<<endl;
                    return false;
                }else{
                    if(pos==-2){
                        cout<<"ERROR DE ARCHIVO - baja"<<endl;
                        return false;
                    }
                }
                Venta reg=archi.leerRegistro(pos);
                reg.setEstado(false);
                bool quePaso=archi.modificarRegistro(pos, reg);
                if(quePaso==true){
                    cout<<"VENTA anulada con exito"<<endl;
                }else{
                    cout<<"No se pudo anular el registro"<<endl;
                }
                return true;
            }

            int contarRegistros(){
                FILE *p=fopen(nombre, "rb");
                if(p==NULL){
                    FILE *p=fopen("ventas.dat", "wb");
                    return 0;
                    if(p==NULL){
                        cout << "ERROR DE ARCHIVO" <<endl;
                        system("pause");
                        return -2;
                    }
                }
                fseek(p, 0,2);
                int tam=ftell(p);
                fclose(p);
                return tam/sizeof(Venta);
            }

            void copiaDeSeguridad(){
                FILE* p;
                FILE* pBackUp;
                p=fopen("ventas.dat", "rb");
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
                cout << "Copia de seguridad de VENTAS realizada correctamente"<<endl;
            }
};


int traerNumeroVenta(){
    ArchivoVenta arcVen("ventas.dat");
    int numVen;
    numVen=arcVen.contarRegistros()+1;
    return numVen;
}

void limpiarArchivoVentas(){
    FILE *p=fopen("ventas.dat","wb");
    cout<<endl<<"Archivo BORRADO"<<endl;
    fclose(p);
}

void mostrarDetalle(int nv, Fecha fec, char *nombre, int numCli, float total){

    ArchivoDetalle arcDet("detalles.dat");
    Detalle det;
    cout << "Detalle comanda n"<<(char)167<<" "<<setfill('0')<<setw(4)<<nv<<endl;
    cout << "Fecha operacion: ";
    fec.Mostrar();
    cout << "\nNumero de cliente: "<<numCli<<endl;
    cout << "Nombre del cliente: "<<nombre<<endl<<endl;
    cout << "---------------------- Detalle --------------------- "<<endl;
    cout << "ID     Nombre                P.U.  Cant    Subtotal"<<endl;
    cout << "----------------------------------------------------\n";
    int cantDet=arcDet.contarRegistros();
    int x=1, y=9;
    for(int i=0;i<cantDet;i++){
        det=arcDet.leerRegistro(i);
        if(det.getNumVen()==nv){
            det.Mostrar(x, y);
            y++;
        }
    }
    cout << "\n----------------------------------------------------";
    cout <<"\n\t\t Importe total: $"<<total<<endl;
    cout << "----------------------------------------------------\n\n\n\n";

    system("pause");
    system("cls");
}

void darAltaVen(int num, Venta ven, ArchivoVenta archi){
    char letra;
    int pos;
    cout<<"Quiere dar de alta la VENTA?    Y/N: ";
    cin>>letra;
    if(letra=='Y'||letra=='y'){
        ven.setEstado(true);
        pos=archi.buscarRegistro(num);
        archi.modificarRegistro(pos, ven);
        cout<<endl<<"La venta fue dada de alta\n";
    }else if(letra=='N'||letra=='n'){
        cout<<endl<<"La venta no fue modificada"<<endl;
    }
    system("pause");
    system("cls");
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
    cout<<"Comanda n"<<(char)167<<": "<<setfill('0')<<setw(4)<<nv;
    //preguntar por cliente, si no existe dejarlo en blanco > lo trae, todavia no lo escribe
    int ic;
    char nombre[30];
    cout << "\nID CLIENTE: ";
    cin >> ic;
    reg.setCliente(ic);
    traerNombreCliente(ic, nombre);
    gotoxy(14,2);
    cout<<" - "<< nombre;
    total=cargarDetalle(nv);
    reg.setPrecioTotal(total);
    reg.setEstado(true);
    arcVen.agregarRegistro(reg);
    system("cls");

    mostrarDetalle(nv, fec, nombre, ic, total);
}

void listarPorNumVenta(){
    Venta ven;
    Fecha fec;
    char nombre[30];
    ArchivoVenta arcVen("ventas.dat");
    int nv, idc;
    float total;
    cout<<endl<<"Ingrese el NUMERO DE COMANDA: ";
    cin>>nv;
    system("cls");// mostarDetalle(int nv, char *nombre, archivoventa, archivodetalle, fec
    int pos=arcVen.buscarRegistro(nv);
    if(pos>=0){
        ven=arcVen.leerRegistro(pos);
            if(ven.getEstado()==true){
                fec=ven.getFechaVenta();
                idc=ven.getCliente();
                traerNombreCliente(idc, nombre);
                total=ven.getPrecioTotal();
                mostrarDetalle(nv, fec, nombre, idc, total);
            }else{
                cout<<endl<<"La venta fue anulada"<<endl;
                darAltaVen(nv,ven,arcVen);
            }
    }else{
        cout<<"No hay comandas con ese numero\n";
        system("pause");
        system("cls");
    }
}

void bajaLogicaVenta(){
    ArchivoVenta archi ("ventas.dat");
    int nv, pos;
    cout<<"Ingrese el NUMERO DE COMANDA a anular: ";
    cin>>nv;
    pos=archi.buscarRegistro(nv);
    if(pos==-1){
        cout<<endl<<"No existe COMANDA con ese numero"<<endl;
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
        cout<<endl<<"VENTA anulada con exito"<<endl;
    }else{
        cout<<endl<<"No se pudo anular la VENTA"<<endl;
    }
    system("pause");
    system("cls");
    return;
}

void mostrarListaVentas(){
    Venta ven;
    ArchivoVenta arcVen("ventas.dat");
    int cantReg, i;
    cantReg=arcVen.contarRegistros();
    if(cantReg>0){
    cout<<"      Comanda  Cliente\tFecha    \tTotal\n";
    for(i=0;i<cantReg;i++){
        ven=arcVen.leerRegistro(i);
        if(ven.getEstado()==true){
            ven.Mostrar();
        }
    }
    }else{cout<<"\n\n\tNo hay registros de ventas\n\n\n\n";}
    system("pause");
    system("cls");
}

void modificarFechaVenta(){//La fecha se carga de manera automatica, agregamos esta funcion para poder chequear el funncionamineto de otros metodos
    ArchivoVenta arcVenta("ventas.dat");
    Venta ven;
    Fecha fec;
    int nv, dia, mes, ano;
    cout<<"Numero de comanda: ";
    cin>>nv;
    int pos=arcVenta.buscarRegistro(nv);
    ven=arcVenta.leerRegistro(pos);
    cout<<"Dia: ";
    cin>>dia;
    cout<<"Mes: ";
    cin>>mes;
    cout<<"Ano: ";
    cin>>ano;
    fec.setDia(dia);
    fec.setMes(mes);
    fec.setAnio(ano);
    ven.setFecha(fec);
    bool que=arcVenta.modificarRegistro(pos, ven);
    if(que==true){cout<<"Facha modificada";}
}


#endif // VENTAS_H_INCLUDED
