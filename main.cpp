#include <iostream>
#include "submenues.h"
#include "ventas.h"

using namespace std;

int main()
{
    int opc;
    while (true) {
        cout << endl;
        cout << "***     MENU PRINCIPAL     ***"<< endl;
        cout << "______________________________"<< endl;
        cout << endl;
        cout << "1. VENTAS                    ."<< endl;
        cout << "2. CLIENTES                  ."<< endl;
        cout << "3. PRODUCTOS                 ."<< endl;
        cout << "4. CONFIGURACION             ."<< endl;
        cout << "______________________________"<< endl;
        cout << "0. SALIR" << endl;
        cout << endl;
        cout << "Elija una opcion: ";
        cin >> opc;
        system("cls");
        switch (opc) {
            case 1:
                subMenuVentas();
                break;
            case 2:
                subMenuClientes();
                break;
            case 3:
                subMenuProductos();
                break;
            case 4:
                subMenuConfiguracion();
                break;
            case 0:
                cout << "Saliendo del programa. Hasta luego!" << endl;
                system("pause");
                return 0;
            default:
                cout << "Opcion no valida." << endl;
                system ("pause");
                system("cls");
                break;
        }
    }
}
