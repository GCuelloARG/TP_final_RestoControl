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
        cout << "**       MENU VENTAS       **"<< endl;
        cout << "_____________________________"<< endl;
        cout << endl;
        cout << "1. CARGAR venta             ."<< endl;
        cout << "2. BUSCAR venta             ."<< endl;
        cout << "3. VER ventas               ."<< endl;
        cout << "4. ANULAR venta             ."<< endl;
        cout << "_____________________________" << endl;
        cout << endl;
        cout << "0. VOLVER AL MENU PRINCIPAL"<< endl;
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
        cout << "**      MENU CLIENTES      **"<< endl;
        cout << "_____________________________"<< endl;
        cout << "1. CARGAR Cliente           ."<< endl;
        cout << "2. BUSCAR Cliente           ."<< endl;
        cout << "3. VER Clientes             ."<< endl;
        cout << "4. MODIFICAR DATOS Cliente  ."<< endl;
        cout << "5. BORRAR Cliente           ."<< endl;
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
        cout << "**      MENU PRODUCTOS      **"<< endl;
        cout << "______________________________"<< endl;
        cout << "1. CARGAR producto           ."<< endl;
        cout << "2. BUSCAR producto           ."<< endl;
        cout << "3. VER productos             ."<< endl;
        cout << "4. MODIFICAR  PRECIO producto."<< endl;
        cout << "5. BORRAR producto           ."<< endl;
        cout << "______________________________"<< endl;
        cout << endl;
        cout << "0.  VOLVER AL MENU PRINCIPAL  "<< endl;
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
        cout << "**          MENU REPORTES          **"<< endl;
        cout << "_____________________________________"<< endl;
        cout << endl;
        cout << "1. INFORME venta del DIA            ."<< endl;
        cout << "2. Ver VENTAS por MES y ANIO        ."<< endl;
        cout << "3. Ver VENTAS por CLIENTE           ."<< endl;
        cout << "_____________________________________"<< endl;
        cout << endl;
        cout << "0. VOLVER AL MENU PRINCIPAL"<< endl;
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
        cout << "**          MENU CONFIGURACION          **"<< endl;
        cout << "__________________________________________"<< endl;
        cout << endl;
        cout << "1. COPIA de SEGURIDAD: Ventas            ."<< endl;
        cout << "2. COPIA de SEGURIDAD: Clientes          ."<< endl;
        cout << "3. COPIA de SEGURIDAD: Productos         ."<< endl;
        cout << "4. RESTAURAR Ventas                      ."<< endl;
        cout << "5. RESTAURAR Clientes                    ."<< endl;
        cout << "6. RESTAURAR Productos                   ."<< endl;
        cout << "__________________________________________"<< endl;
        cout << endl;
        cout << "0. VOLVER AL MENU PRINCIPAL"<< endl;
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
