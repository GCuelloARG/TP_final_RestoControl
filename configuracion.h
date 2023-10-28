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

#endif // CONFIGURACION_H_INCLUDED
