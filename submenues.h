#ifndef SUBMENUES_H_INCLUDED
#define SUBMENUES_H_INCLUDED
#include <iostream>
#include "ventas.h"
#include "configuracion.h"
#include "detalle.h"


using namespace std;

void subMenuClientes(){

    ArchivoCliente archi("clientes.dat");
    int opc;

    while(true){
        cout << endl;
        cout << "**      MENU CLIENTES      **"<< endl;
        cout << "_____________________________"<< endl;
        cout << "1. CARGAR Cliente           ."<< endl;
        cout << "2. BUSCAR Cliente           ."<< endl;
        cout << "3. VER Clientes             ."<< endl;
        cout << "4. BORRAR Cliente           ."<< endl;
        cout << "_____________________________"<< endl;
        cout << endl;
        cout << "0. VOLVER AL MENU PRINCIPAL"<< endl;
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
                bajaLogicaCli();
                break;
            case 5:
                limpiarArchivoClientes(); /// OCULTO / Para limpiar todos los registros del archivo
                break;
            case 0:
                cout << "Regresando al menu principal..." << endl;
                system ("pause");
                return;
            default:
                cout << "Opcion no valida." << endl;
                break;
        }
    }
}

void subMenuProductos(){
    ArchivoProducto archi("productos.dat");
    int opc;

    while(true){
        cout << endl;
        cout << "**     MENU PRODUCTOS     **"<< endl;
        cout << "____________________________"<< endl;
        cout << "1. CARGAR producto         ."<< endl;
        cout << "2. BUSCAR producto         ."<< endl;
        cout << "3. VER productos           ."<< endl;
        cout << "4. BORRAR producto         ."<< endl;
        cout << "____________________________"<< endl;
        cout << endl;
        cout << "0. VOLVER AL MENU PRINCIPAL "<< endl;
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
                bajaLogicaProd();
                break;
            case 5:
                limpiarArchivoProductos();
                break;
            case 0:
                cout << "Regresando al menu principal..." << endl;
                system ("pause");
                return;
            default:
                cout << "Opcion no valida." << endl;
                break;
        }
    }
}

void subMenuVentas(){
    int opc;
    while(true){
        cout << endl;
        cout << "**       MENU VENTAS       **"<< endl;
        cout << "_____________________________"<< endl;
        cout << endl;
        cout << "1. CARGAR venta             ."<< endl;
        cout << "2. BUSCAR venta             ."<< endl;
        cout << "3. VER ventas               ."<< endl;
        cout << "4. BORRAR venta (limpiar)   ."<< endl;
        cout << "_____________________________" << endl;
        cout << endl;
        cout << "0. VOLVER AL MENU PRINCIPAL"<< endl;
        cout << endl;
        cout << "Elija una opcion: ";
        cin >> opc;

        switch(opc){
            case 1:
                system("cls");
                //numero de venta viene de la cantidad de registros en archivoVenta+1
                cout<<traerNumeroVenta();


                //preguntar por cliente, si no existe dejarlo en blanco
                int ic;
                cout << "ID CLIENTE: ";
                cin >> ic;
                cout<<endl<<"Cliente: (Nombre)"<<endl;

                cargarDetalle(); //>> desarrollar falta subtotal

                //>> pasar por parametro numero de venta para identificar al detalle
                //leer archivo detalle>> calcular total
                break;
            case 2:
                system("cls");
                ///listarPorNumVen();  >> desarrollar
                break;
            case 3:
                system("cls");
                mostrarListaDetalles();
                break;
            case 4:
                system("cls");
                limpiarArchivoDetalles();
                break;
            case 5:
                system("cls");
                limpiarArchivoVentas();
                break;
            case 0:
                cout << "Regresando al menu principal..." << endl;
                system ("pause");
                return;
            default:
                cout << "Opcion no valida." << endl;
                break;
        }
    }
}

void subMenuReportes(){

    int opc;

    while(true){
        cout << "**     MENU REPORTES     **"<< endl;
        cout << "___________________________"<< endl;
        cout << endl;
        cout << "1.                        ."<< endl;
        cout << "2.                        ."<< endl;
        cout << "3.                        ."<< endl;
        cout << "4.                        ."<< endl;
        cout << "___________________________"<< endl;
        cout << endl;
        cout << "0. VOLVER AL MENU PRINCIPAL"<< endl;
        cout << endl;
        cout << "Elija una opcion: ";
        cin >> opc;

        switch(opc){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 0:
                cout << "Regresando al menu principal..." << endl;
                system ("pause");
                return;
            default:
                cout << "Opcion no valida." << endl;
                break;
        }
    }
}

void subMenuConfiguracion(){
    int opc;

    while(true){
        cout << endl;
        cout << "**          MENU CONFIGURACION          **"<< endl;
        cout << "__________________________________________"<< endl;
        cout << endl;
        cout << "1. COPIA de SEGURIDAD: CLIENTES          ."<< endl;
        cout << "2. COPIA de SEGURIDAD: PRODUCTOS         ."<< endl;
        cout << "3. COPIA de SEGURIDAD: VENTAS            ."<< endl;
        cout << "4. RESTAURAR archivo: CLIENTES           ."<< endl;
        cout << "5. RESTAURAR archivo: PRODUCTOS          ."<< endl;
        cout << "6. RESTAURAR archivo: VENTAS             ."<< endl;
        cout << "__________________________________________"<< endl;
        cout << endl;
        cout << "0. VOLVER AL MENU PRINCIPAL"<< endl;
        cout << endl;
        cout << "Elija una opcion: ";
        cin >> opc;

        switch(opc){
            case 1:
                copiaDeSeguridadClientes();
                break;
            case 2:
                copiaDeSeguridadProductos();
                break;
            case 3:
                //copiaDeSeguridadVentas();
                break;
            case 4:
                restaurarClientes();
                break;
            case 5:
                //restaurarProductos();
                break;
            case 6:
                //restaurarVentas();
                break;
            case 0:
                cout << "Regresando al menu principal..." << endl;
                system ("pause");
                return;
            default:
                cout << "Opcion no valida." << endl;
                break;
        }
    }
}


#endif // SUBMENUES_H_INCLUDED
