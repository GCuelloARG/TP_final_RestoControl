#ifndef SUBMENUES_H_INCLUDED
#define SUBMENUES_H_INCLUDED
#include <iostream>
#include "ventas.h"

using namespace std;

void subMenuClientes(){

    ArchivoCliente archi("clientes.dat");
    int opc;

    system("cls");
    cout << endl;
    cout << "**     MENU CLIENTES     **" << endl;
    cout << endl;
    cout << "1. CARGAR Cliente         ."<< endl;
    cout << "2. BUSCAR Cliente         ."<< endl;
    cout << "3. VER Clientes           ."<< endl;
    cout << "4. BORRAR Cliente         ."<< endl;
    cout << "---------------------------"<< endl;
    cout << "0. Salir"<< endl;
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
            MostrarListaClientes();
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

void subMenuProductos(){

    int opc;

    system("cls");
    cout << endl;
    cout << "**    MENU PRODUCTOS    **" << endl;
    cout << endl;
    cout << "1. CARGAR producto       ."<< endl;
    cout << "2. BUSCAR producto       ."<< endl;
    cout << "3. VER productos         ."<< endl;
    cout << "4. BORRAR producto       ."<< endl;
    cout << "--------------------------" << endl;
    cout << "0. Salir"<< endl;
    cout << endl;
    cout << "Elija una opcion: ";
    cin >> opc;
    system("cls");

    switch(opc){
        case 1:

            nuevoProd();
            break;
        case 2:
            MostrarID();
            break;
        case 3:
            MostrarListaProductos();
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

void subMenuVentas(){

    Venta venta;
    int opc;
    while(true){
        cout << endl;
        cout << "**     MENU VENTAS     **" << endl;
        cout << endl;
        cout << "1. CARGAR venta         ."<< endl;
        cout << "2. BUSCAR venta         ."<< endl;
        cout << "3. VER ventas           ."<< endl;
        cout << "4. BORRAR venta         ."<< endl;
        cout << "-------------------------" << endl;
        cout << "0. Salir"<< endl;
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

    system("cls");
    cout << endl;
    cout << "**    MENU REPORTES    **" << endl;
    cout << "1.                     ."<< endl;
    cout << "2.                     ."<< endl;
    cout << "3.                     ."<< endl;
    cout << "4.                     ."<< endl;
    cout << "------------------------" << endl;
    cout << "0. Salir"<< endl;
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

void subMenuConfiguracion(){
    /// aca vamos a tener que operar solamente sobre archivos; crear un obj de cada ArchivoClase
    int opc;

    system("cls");
    cout << endl;
    cout << "**          MENU CONFIGURACION          **" << endl;
    cout << endl;
    cout << "1. COPIA de SEGURIDAD: CLIENTES          ."<< endl;
    cout << "2. COPIA de SEGURIDAD: PRODUCTOS         ."<< endl;
    cout << "3. COPIA de SEGURIDAD: VENTAS            ."<< endl;
    cout << "4. RESTAURAR archivo: CLIENTES           ."<< endl;
    cout << "5. RESTAURAR archivo: PRODUCTOS          ."<< endl;
    cout << "6. RESTAURAR archivo: VENTAS             ."<< endl;
    cout << "7. BACK UP archivo: CLIENTES             ."<< endl;
    cout << "8. BACK UP archivo: PRODUCTOS            ."<< endl;
    cout << "9. BACK UP archivo: VENTAS               ."<< endl;
    cout << "------------------------------------------"<< endl;
    cout << "0. Salir"<< endl;
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
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
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


#endif // SUBMENUES_H_INCLUDED
