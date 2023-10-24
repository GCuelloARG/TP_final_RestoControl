#include <iostream>
#include "submenues.h"
#include "ventas.h"

using namespace std;

int main()
{
    int opc;
    while (true) {
        cout << endl;
        cout << "***    MENU PRINCIPAL    ***" << endl;
        cout << endl;
        cout << "1. CLIENTES                ." << endl;
        cout << "2. PRODUCTOS               ." << endl;
        cout << "3. VENTAS                  ." << endl;
        cout << "4. REPORTES                ." << endl;
        cout << "5. CONFIGURACION           ." << endl;
        cout << "----------------------------" << endl;
        cout << "0. Salir" << endl;
        cout << endl;
        cout << "Elija una opcion: ";
        cin >> opc;

        switch (opc) {
            case 1:
                subMenuClientes();
                break;
            case 2:
                subMenuProductos();
                break;
            case 3:
                subMenuVentas();
                break;
            case 4:
                subMenuReportes();
                break;
            case 5:
                subMenuConfiguracion();
                break;
            case 0:
                cout << "Saliendo del programa. Hasta luego!" << endl;
                system("pause");
                return 0;
            default:
                cout << "Opcion no valida." << endl;
                system("pause");
                break;
        }
    }
}
