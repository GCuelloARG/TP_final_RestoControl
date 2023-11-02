#ifndef REP_H_INCLUDED
#define REP_H_INCLUDED
#include "rlutil.h"
#include "globales.h"

using namespace std;


void ventasPorMes(){
    Venta ven;
    Fecha fec;
    ArchivoVenta arcVen("ventas.dat");
    int mm, aaaa, auxMes, auxAnio,  i, cantReg, cont=0;
    float fact;
    cantReg=arcVen.contarRegistros();
    cout<<endl<<"Ingrese el ANO (aaaa) que desea reportar: ";
    cin>>aaaa;
    cout<<"Ingrese el MES (mm) que desea reportar: ";
    cin>>mm;
    system("cls");
    cout<<"\t   -  VENTAS DE "<<mm<<"/"<<aaaa<<"  -"<<endl;
    if(cantReg>0){
        for(i=0; i<cantReg; i++){
            ven=arcVen.leerRegistro(i);
            fec=ven.getFechaVenta();
            auxMes=fec.getMes();
            auxAnio=fec.getAnio();
            if(mm==auxMes&&aaaa==auxAnio&&ven.getEstado()==true){
                ven.Mostrar();
                cont++;
                fact+=ven.getPrecioTotal();
            }
       }
    }
       cout<<endl<<"Cantidad de ventas del mes "<<mm<<" de "<<aaaa<<": "<<cont<<endl;
       cout<<"Total facturado: $"<<fact<<endl<<endl;

       system("pause");
       system("cls");
}

void reporteDiario(){
    ArchivoVenta arcVen("ventas.dat");
    Venta ven;
    Fecha fec;
    fechaActual(fec);
    int dia=fec.getDia(), mes=fec.getMes(), anio=fec.getAnio();
    int cantVen=arcVen.contarRegistros();
    float totalDiario=0.00;
    cout<<"Reporte de ventas Diario"<<endl;
    cout<<"Fecha :";
    fec.Mostrar();
    cout<<"      Comanda  Cliente\tFecha    \tTotal\n";
    for(int i=0;i<cantVen;i++){
        ven=arcVen.leerRegistro(i);

        if(ven.getFechaVenta().getAnio()==anio&&ven.getFechaVenta().getMes()==mes&&ven.getFechaVenta().getDia()==dia){
                if(ven.getEstado()==true){
                    ven.Mostrar();
                    totalDiario+=ven.getPrecioTotal();
                }
        }

    }
    cout <<"\n\t\t    Recaudacion total: $"<<totalDiario<<endl;


    system("pause");
    system("cls");
}

void reportePorCliente(){
    Cliente cli;
    ArchivoCliente archi("clientes.dat");
    Venta ven;
    ArchivoVenta arcVen ("ventas.dat");
    int pos=0, id, i;
    cout<<"Ingrese el ID del cliente: ";
    cin>>id;
    int cantVen, cont=0;
    char nombre[30];
    float acum=0;
    pos=archi.buscarRegistro(id);
    cli=archi.leerRegistro(pos);
    cantVen=arcVen.contarRegistros();
    traerNombreCliente(id,nombre);
    cout << "Compras del cliente "<<nombre<<": "<<endl;
    for(i=0;i<cantVen;i++){
        ven=arcVen.leerRegistro(i);
        if(ven.getCliente()==id){
            ven.Mostrar();
            cont++;
            acum+=ven.getPrecioTotal();
        }

    }
    cout<<endl;
    cout<<"Cantidad de compras: "<<cont<<endl;
    cout<<"Recaudacion: $"<<acum<<endl;
    system("pause");
    system("cls");
}
#endif // REP_H_INCLUDED
