#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED

#include <iostream>
#include "clientes.h"
#include "productos.h"

void copiaDeSeguridadClientes(){
    int cantReg;
    ArchivoCliente archiCli("clientes.dat");
    ArchivoCliente archiCliBackUp ("clientes_backup.bkp");
    Cliente reg;
    cantReg=archiCli.contarRegistros();
    for(int i=0; i<cantReg; i++){
        reg=archiCli.leerRegistro(i);
        if(reg.getEstado()==true){
            archiCliBackUp.agregarRegistro(reg);
        }
    }
    cout << "Copia de seguridad de CLIENTES realizada correctamente" << endl;
}

void restaurarClientes(){
    int cantReg;
    ArchivoCliente archiCli("clientes.dat");
    ArchivoCliente archiCliBackUp ("clientes_backup.bkp");
    Cliente reg;
    cantReg=archiCliBackUp.contarRegistros();
    for(int i=0; i<cantReg; i++){
        reg=archiCliBackUp.leerRegistro(i);
        if(reg.getEstado()==true){
            archiCli.agregarRegistro(reg);
        }
    }
    cout << "Restauracion de CLIENTES desde copia de seguridad realizada correctamente" << endl;
}

void copiaDeSeguridadProductos(){
    ArchivoProducto archi("productos.dat");
    int cantReg;
    Producto reg;
    cantReg=archi.contarRegistros();
    ArchivoProducto archibkp("productos_backup.bkp");
    for(int x=0;x<cantReg;x++){
        reg=archi.leerRegistro(x);
        if(reg.getEstado()==true){
        archibkp.agregarRegistro(reg);
        }
    }
    cout << "Copia de seguridad de CLIENTES realizada correctamente" << endl;
}

void restaurarProductos(){
    int cantReg;
    ArchivoProducto archi("productos.dat");
    ArchivoProducto archibkp ("productos_backup.bkp");
    Producto reg;
    cantReg=archibkp.contarRegistros();
    for(int i=0; i<cantReg; i++){
        reg=archibkp.leerRegistro(i);
        if(reg.getEstado()==true){
            archi.agregarRegistro(reg);
        }
    }
    cout << "Restauracion de PRODUCTOS desde copia de seguridad realizada correctamente" << endl;
}

void copiaDeSeguridadVentas(){
    ArchivoVenta archi("ventas.dat");
    int cantReg;
    Venta reg;
    cantReg=archi.contarRegistros();
    ArchivoVenta archibkp("ventas_backup.bkp");
    for(int x=0;x<cantReg;x++){
        reg=archi.leerRegistro(x);
        if(reg.getEstado()==true){
        archibkp.agregarRegistro(reg);
        }
    }
    cout << "Copia de seguridad de VENTAS realizada correctamente" << endl;
}

void restaurarVentas(){
    int cantReg;
    ArchivoVenta archi("ventas.dat");
    ArchivoVenta archibkp ("ventas_backup.bkp");
    Venta reg;
    cantReg=archibkp.contarRegistros();
    for(int i=0; i<cantReg; i++){
        reg=archibkp.leerRegistro(i);
        if(reg.getEstado()==true){
            archi.agregarRegistro(reg);
        }
    }
    cout << "Restauracion de VENTAS desde copia de seguridad realizada correctamente" << endl;
}


#endif // CONFIGURACION_H_INCLUDED
