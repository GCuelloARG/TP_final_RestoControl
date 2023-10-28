#ifndef SUBMENUES_H_INCLUDED
#define SUBMENUES_H_INCLUDED
#include <iostream>
#include "ventas.h"

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

                break;
            case 3:
                mostrarListaClientes();
                break;
            case 4:
                archi.bajaLogica();
                break;
            case 5:
                limpiarArchivoClientes(); /// OCULTO / Para limpiar todos los registros del archivo
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
                mostrarID();
                break;
            case 3:
                mostrarListaProductos();
                break;
            case 4:
                archi.bajaLogica();
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

    Venta venta;
    int opc;
    while(true){
        cout << endl;
        cout << "**       MENU VENTAS       **"<< endl;
        cout << "_____________________________"<< endl;
        cout << endl;
        cout << "1. CARGAR venta             ."<< endl;
        cout << "2. BUSCAR venta             ."<< endl;
        cout << "3. VER ventas               ."<< endl;
        cout << "4. BORRAR venta             ."<< endl;
        cout << "_____________________________" << endl;
        cout << endl;
        cout << "0. VOLVER AL MENU PRINCIPAL"<< endl;
        cout << endl;
        cout << "Elija una opcion: ";
        cin >> opc;

        switch(opc){
            case 1:
                system("cls");
                /// nuevaVenta(); >> desarrollar
                break;
            case 2:
                system("cls");
                ///listarPorNumVen();  >> desarrollar
                break;
            case 3:
                system("cls");
                ///MostrarListaVentas();
                break;
            case 4:
                system("cls");
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
    /// aca vamos a tener que operar solamente sobre archivos, salvo case 7; crear un obj de cada ArchivoClase
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
        cout << "7. ESTABLECER DATOS INICIO               ."<< endl;
        cout << "__________________________________________"<< endl;
        cout << endl;
        cout << "0. VOLVER AL MENU PRINCIPAL"<< endl;
        cout << endl;
        cout << "Elija una opcion: ";
        cin >> opc;

        switch(opc){
            case 1:
                //archiCli.copiaDeSeguridad();
                break;
            case 2:
                //archiProd.copiaDeSeguridad();
                break;
            case 3:
                //archiVen.copiaDeSeguridad();
                break;
            case 4:
                //archiCli.restaurarClientes();
                break;
            case 5:
                //archiProd.restaurarProductos();
                break;
            case 6:
                //archiVen.restaurarVentas();
                break;
            case 7:
                //establecerInicio();
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
