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
            if(mm==auxMes&&aaaa==auxAnio){
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
    ArchivoVenta arcDiario("ventasDiarias.dat");
    Venta ven;
    Venta diario;
    Fecha fec;
    fechaActual(fec);
    int dia=fec.getDia(), mes=fec.getMes(), anio=fec.getAnio();
    int cantVen=arcVen.contarRegistros();
    int cantDiarias;
    float totalDiario=0;
    cout<<"Reporte de ventas Diario"<<endl;
    cout<<"Fecha :";
    fec.Mostrar();

    for(int i=0;i<cantVen;i++){
        ven=arcVen.leerRegistro(i);

        if(ven.getFechaVenta().getAnio()==anio&&ven.getFechaVenta().getMes()==mes&&ven.getFechaVenta().getDia()==dia){
                if(ven.getEstado()==true){
                arcDiario.agregarRegistro(ven);
                }
        }

    }
    cantDiarias=arcDiario.contarRegistros();
    if(cantDiarias>0){
    cout<<"      Comanda  Cliente\tFecha    \tTotal\n";
    for(int x=0;x<cantDiarias;x++){
        diario=arcDiario.leerRegistro(x);
        totalDiario+=diario.getPrecioTotal();
        diario.Mostrar();
    }
    cout <<"\n\t\t Recaudacion total: $"<<totalDiario<<endl;
    }else{
    cout<<"Aun no hay registros de ventas para hoy\n";
    }
    system("pause");
    system("cls");
}
#endif // REP_H_INCLUDED
