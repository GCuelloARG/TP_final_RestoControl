#ifndef REP_H_INCLUDED
#define REP_H_INCLUDED
#include "rlutil.h"
#include "globales.h"

using namespace std;


void ventasPorMes(){
    Venta ven;
    Fecha fec;
    ArchivoVenta arcVen("ventas.dat");
    int mm, aux,  i, cantReg, cont=0;
    float fact;
    cantReg=arcVen.contarRegistros();
    cout<<endl<<"Ingrese el MES (mm) que desea reportar: ";
    cin>>mm;
    system("cls");
    cout<<"\t   -  VENTAS MES "<<mm<<" 2023  -"<<endl;
    if(cantReg>0){
        for(i=0; i<cantReg; i++){
            ven=arcVen.leerRegistro(i);
            fec=ven.getFechaVenta();
            aux=fec.getMes();
            if(mm==aux){

                ven.Mostrar();
                cont++;
                fact+=ven.getPrecioTotal();
            }
       }
    }
       cout<<endl<<"Cantidad de ventas del mes "<<mm<<" de 2023: "<<cont<<endl;
       cout<<"Total facturado: $"<<fact<<endl<<endl;

       system("pause");
       system("cls");
}


#endif // REP_H_INCLUDED
