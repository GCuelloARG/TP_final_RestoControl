#include <iostream>
#include "submenues.h"
#include "ventas.h"

using namespace std;

int main()
{
    int opc;
    while (true) {
        cout << "\t        ---- RestoControl 2023 ----" <<endl;
        cout << endl;
        cout << "\t*****          MENU  PRINCIPAL          *****"<< endl;
        cout << "\t:::::::::::::::::::::::::::::::::::::::::::::"<< endl;
        cout << "\t::          1. Menu VENTAS                 ::"<< endl;
        cout << "\t::          2. Menu CLIENTES               ::"<< endl;
        cout << "\t::          3. Menu PRODUCTOS              ::"<< endl;
        cout << "\t::          4. Menu REPORTES               ::"<< endl;
        cout << "\t::          5. Menu CONFIGURACION          ::"<< endl;
        cout << "\t:::::::::::::::::::::::::::::::::::::::::::::"<< endl;
        cout << "\t0. Salir" << endl;
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
                subMenuReportes();
                break;
            case 5:
                subMenuConfiguracion();
                break;
            case 0:
                gotoxy(10,3);
                cout<<"Saliendo del programa. Hasta pronto!"<<endl;
                gotoxy(16,6);
                cout<<"- RestoControl 2023 -"<<endl;
                gotoxy(10,9);
                cout<<"** Balzarini, Cuello, R.Varangot ** \n\n\n";
                gotoxy(1,20);
                system("pause");
                return 0;
            default:
                cout<<"Opcion no valida."<<endl;
                system ("pause");
                system("cls");
                break;
        }
    }
}
