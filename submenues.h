#ifndef SUBMENUES_H_INCLUDED
#define SUBMENUES_H_INCLUDED
#include <iostream>
#include "ventas.h"
#include "configuracion.h"
#include "detalle.h"
#include "rep.h"



using namespace std;

void subMenuVentas(){
    int opc;
    while(true){
        cout << endl;
        cout << "\t            Menu de VENTAS"<< endl;
        cout << "\t::::::::::::::::::::::::::::::::::::::"<< endl;
        cout << "\t::     1. CARGAR venta              ::"<< endl;
        cout << "\t::     2. BUSCAR venta              ::"<< endl;
        cout << "\t::     3. VER ventas                ::"<< endl;
        cout << "\t::     4. ANULAR venta              ::"<< endl;
        cout << "\t::     5. MODIFICAR FECHA venta     ::"<< endl;
        cout << "\t::::::::::::::::::::::::::::::::::::::"<< endl;
        cout << "\t0. VOLVER al menu principal"<< endl;
        cout << endl;
        cout << "Elija una opcion: ";
        cin >> opc;
        system("cls");
        switch(opc){
            case 1:
                nuevaVenta();
                break;
            case 2:
                listarPorNumVenta();
                break;
            case 3:
                mostrarListaVentas();
                break;
            case 4:
                bajaLogicaVenta();
                break;
            case 5:

                break;
            case 6:
                limpiarArchivoDetalles(); /// OCULTO - Limpia registros del archivo detalles
                limpiarArchivoVentas(); /// OCULTO - Limpia registros del archivo ventas
                break;
            case 0:
                cout << endl << "\n\n\n\tRegresando al menu principal...\n\n\n" << endl;
                system ("pause");
                system("cls");
                return;
            default:
                cout << endl << "Opcion no valida." << endl;
                system ("pause");
                system("cls");
                break;
        }
    }
}

void subMenuClientes(){
    int opc;
    while(true){
        cout << endl;
        cout << "\t            Menu de CLIENTES"<< endl;
        cout << "\t::::::::::::::::::::::::::::::::::::::::"<< endl;
        cout << "\t::     1. CARGAR cliente              ::"<< endl;
        cout << "\t::     2. BUSCAR cliente              ::"<< endl;
        cout << "\t::     3. VER clientes                ::"<< endl;
        cout << "\t::     4. MODIFICAR DATOS cliente     ::"<< endl;
        cout << "\t::     5. BORRAR cliente              ::"<< endl;
        cout << "\t::::::::::::::::::::::::::::::::::::::::"<< endl;
        cout << "\t0. VOLVER al menu principal"<< endl;
        cout << endl;
        cout << "Elija una opcion: ";
        cin >> opc;
        system("cls");
        switch(opc){
            case 1:
                nuevoCliente();
                break;
            case 2:
                mostrarIDCli();
                break;
            case 3:
                mostrarListaClientes();
                break;
            case 4:
                cambiarDatosCliente();
                break;
            case 5:
                bajaLogicaCli();
                break;
            case 6:
                limpiarArchivoClientes(); /// OCULTO / Para limpiar todos los registros del archivo
                break;
            case 0:
                cout << endl << "\n\n\n\tRegresando al menu principal...\n\n\n" << endl;
                system ("pause");
                system("cls");
                return;
            default:
                cout << endl << "Opcion no valida." << endl;
                system ("pause");
                system("cls");
                break;
        }
    }
}

void subMenuProductos(){
    int opc;
    while(true){
        cout << endl;
        cout << "\t            Menu de PRODUCTOS"<< endl;
        cout << "\t::::::::::::::::::::::::::::::::::::::::::"<< endl;
        cout << "\t::     1. CARGAR producto               ::"<< endl;
        cout << "\t::     2. BUSCAR producto               ::"<< endl;
        cout << "\t::     3. VER productos                 ::"<< endl;
        cout << "\t::     4. MODIFICAR PRECIO producto     ::"<< endl;
        cout << "\t::     5. BORRAR producto               ::"<< endl;
        cout << "\t::::::::::::::::::::::::::::::::::::::::::"<< endl;
        cout << "\t0. VOLVER al menu principal"<< endl;
        cout << endl;
        cout << "Elija una opcion: ";
        cin >> opc;
        system("cls");
        switch(opc){
            case 1:
                nuevoProd();
                break;
            case 2:
                mostrarIDProd();
                break;
            case 3:
                mostrarListaProductos();
                break;
            case 4:
                cambiarPrecioProducto();
                break;
            case 5:
                bajaLogicaProd();
                break;
            case 6:
                limpiarArchivoProductos(); /// OCULTO - Para limpiar todos los registros del archivo.
                break;
            case 0:
                cout << endl << "\n\n\n\tRegresando al menu principal...\n\n\n" << endl;
                system ("pause");
                system ("cls");
                return;
            default:
                cout << endl << "Opcion no valida." << endl;
                system ("pause");
                system("cls");
                break;
        }
    }
}

void subMenuReportes(){
    int opc;
    while(true){
        cout << endl;
        cout << "\t             Menu de REPORTES"<< endl;
        cout << "\t::::::::::::::::::::::::::::::::::::::::::"<< endl;
        cout << "\t::     1. Ver VENTAS del DIA            ::"<< endl;
        cout << "\t::     2. Ver VENTAS por MES y ANIO     ::"<< endl;
        cout << "\t::     3. Ver VENTAS por CLIENTE        ::"<< endl;
        cout << "\t::::::::::::::::::::::::::::::::::::::::::"<< endl;
        cout << "\t0. VOLVER al menu principal"<< endl;
        cout << endl;
        cout << "Elija una opcion: ";
        cin >> opc;
        system("cls");
        switch(opc){
            case 1:
                reporteDiario();
                break;
            case 2:
                ventasPorMes();
                break;
            case 3:
                reportePorCliente();
                break;
            case 0:
                cout << endl << "\n\n\n\tRegresando al menu principal...\n\n\n" << endl;
                system ("pause");
                system("cls");
                return;
            default:
                cout << endl << "Opcion no valida." << endl;
                system ("pause");
                system("cls");
                break;
        }
    }
}

void subMenuConfiguracion(){
    int opc;
    while(true){
        cout << endl;
        cout << "\t            Menu de  CONFIGURACION"<< endl;
        cout << "\t::::::::::::::::::::::::::::::::::::::::::::::"<< endl;
        cout << "\t::     1. COPIA de SEGURIDAD: Ventas        ::"<< endl;
        cout << "\t::     2. COPIA de SEGURIDAD: Clientes      ::"<< endl;
        cout << "\t::     3. COPIA de SEGURIDAD: Productos     ::"<< endl;
        cout << "\t::     4. RESTAURAR Ventas                  ::"<< endl;
        cout << "\t::     5. RESTAURAR Clientes                ::"<< endl;
        cout << "\t::     6. RESTAURAR Productos               ::"<< endl;
        cout << "\t::::::::::::::::::::::::::::::::::::::::::::::"<< endl;
        cout << "\t0. VOLVER al menu principal"<< endl;
        cout << endl;
        cout << "Elija una opcion: ";
        cin >> opc;
        system("cls");
        switch(opc){
            case 1:
                copiaDeSeguridadVentas();
                break;
            case 2:
                copiaDeSeguridadClientes();
                break;
            case 3:
                copiaDeSeguridadProductos();
                break;
            case 4:
                restaurarVentas();
                break;
            case 5:
                restaurarClientes();
                break;
            case 6:
                restaurarProductos();
                break;
            case 0:
                cout << endl << "\n\n\n\tRegresando al menu principal...\n\n\n" << endl;
                system ("pause");
                system("cls");
                return;
            default:
                cout << endl << "Opcion no valida." << endl;
                system ("pause");
                system("cls");
                break;
        }
    }
}


#endif // SUBMENUES_H_INCLUDED
