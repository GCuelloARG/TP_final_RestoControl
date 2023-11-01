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


#endif // REP_H_INCLUDED
