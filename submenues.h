#ifndef SUBMENUES_H_INCLUDED
#define SUBMENUES_H_INCLUDED
#include <iostream>
using namespace std;

void subMenuClientes(){
    int opc;

    system("cls");
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
            cout << "Regresando al menu principal..." << endl;
            system ("pause");
            return;
        default:
            cout << "Opcion no valida." << endl;
            break;
    }
}

void subMenuVentas(){

    ArchivoVenta archi("ventas.dat");
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
        cout << "5. Salir"<< endl;
        cout << endl;
        cout << "Elija una opcion: ";
        cin >> opc;

        switch(opc){
            case 1:
                system("cls");
                archi.agregarRegistro();
                break;
            case 2:
                system("cls");
                ///archi.listarPorNumero(nv);   >> desarrollar
                break;
            case 3:
                system("cls");
                /// archi.listarRegistros();    >> desarrollar
                break;
            case 4:
                system("cls");
                archi.bajaLogica();
                break;
            case 5:
                cout << "Regresando al menu principal..." << endl;
                system ("pause");
                return;
            default:
                cout << "Opcion no valida." << endl;
                break;
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
            cout << "Regresando al menu principal..." << endl;
            system ("pause");
            return;
        default:
            cout << "Opcion no valida." << endl;
            break;
    }
}

void subMenuConfiguracion(){
    int opc;

    system("cls");
    cout << endl;
    cout << "**          MENU CONFIGURACION          **" << endl;
    cout << endl;
    cout << "1. COPIAS de SEGURIDAD                   ."<< endl; /// que tal si lo hacemos asi, que entre a copias y elija copia de que?
    cout << "2. RESTAURAR archivos                    ."<< endl; /// asi no aparece copia clientes, copia productos, copia ventas, restarurar.. etcs
    cout << "3. BACK UP archivos                      ."<< endl;
    cout << "4.                                       ."<< endl;
    cout << "------------------------------------------"<< endl;
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
            cout << "Regresando al menu principal..." << endl;
            system ("pause");
            return;
        default:
            cout << "Opcion no valida." << endl;
            break;
    }
}


#endif // SUBMENUES_H_INCLUDED
