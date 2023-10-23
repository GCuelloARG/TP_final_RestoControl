#ifndef SUBMENUES_H_INCLUDED
#define SUBMENUES_H_INCLUDED
#include <iostream>
using namespace std;

void subMenuClientes(){
    int opc;

    cout << endl;
    cout << "**     MENU CLIENTES     **" << endl;
    cout << endl;
    cout << "1. CARGAR Cliente         ."<< endl;
    cout << "2. BUSCAR Cliente         ."<< endl;
    cout << "3. VER Clientes           ."<< endl;
    cout << "4. BORRAR Cliente         ."<< endl;
    cout << "---------------------------" << endl;
    cout << "5. Salir"<< endl;
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
            cout << "Saliendo... Hasta luego!" << endl;
            system ("pause");
            return;
        default:
            cout << "Opcion no valida." << endl;
            break;
    }
}

void subMenuProductos(){
    int opc;

    cout << "**    MENU PRODUCTOS    **" << endl;
    cout << endl;
    cout << "1. CARGAR producto       ."<< endl;
    cout << "2. BUSCAR producto       ."<< endl;
    cout << "3. VER productos         ."<< endl;
    cout << "4. BORRAR producto       ."<< endl;
    cout << "--------------------------" << endl;
    cout << "5. Salir"<< endl;
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
            cout << "Saliendo... Hasta luego!" << endl;
            system ("pause");
            return;
        default:
            cout << "Opcion no valida." << endl;
            break;
    }
}

void subMenuVentas(){
    int opc;

    cout << "**    MENU VENTAS    **" << endl;
    cout << endl;
    cout << "1. CARGAR venta       ."<< endl;
    cout << "2. BUSCAR venta      ."<< endl;
    cout << "3. VER ventas         ."<< endl;
    cout << "4. BORRAR venta       ."<< endl;
    cout << "-----------------------" << endl;
    cout << "5. Salir"<< endl;
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
            cout << "Saliendo... Hasta luego!" << endl;
            system ("pause");
            return;
        default:
            cout << "Opcion no valida." << endl;
            break;
    }
}

void subMenuReportes(){
    int opc;

    cout << "**    MENU REPORTES    **" << endl;
    cout << "1.                     ."<< endl;
    cout << "2.                     ."<< endl;
    cout << "3.                     ."<< endl;
    cout << "4.                     ."<< endl;
    cout << "------------------------" << endl;
    cout << "5. Salir"<< endl;
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
            cout << "Saliendo... Hasta luego!" << endl;
            system ("pause");
            return;
        default:
            cout << "Opcion no valida." << endl;
            break;
    }
}





#endif // SUBMENUES_H_INCLUDED
