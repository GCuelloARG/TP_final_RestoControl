#ifndef DETALLE_H_INCLUDED
#define DETALLE_H_INCLUDED
#include "productos.h"

using namespace std;

class Detalle{
	private:
            Producto prod;
            int cant;
            float subTotal;
            bool estado;
	public:
            void setEstado(bool st){estado=st;}
            bool getEstado(){return estado;}
            void Cargar();
            void Mostrar();
};

class ArchivoDetalle{
	private:
            char nombre[30];
	public:
            ArchivoDetalle(const char *nom){
            strcpy(nombre, nom);
            }

            void copiaDeSeguridad(){
                FILE* p;
                FILE* pBackUp;

                p = fopen("detalle_ventas.dat", "rb");

                if (p == NULL) {
                    cout << "ERROR DE ARCHIVO" << endl;
                    return;
                }

                pBackUp = fopen("detalle_ventas_backup.bkp", "wb");
                if (pBackUp == NULL) {
                    cout << "ERROR DE ARCHIVO" << endl;
                    return;
                }

                Detalle reg;
                while (fread(&reg, sizeof reg, 1, p) == 1) {
                    if(reg.getEstado()==true){
                        fwrite(&reg, sizeof reg, 1, pBackUp);
                    }
                }

                fclose(p);
                fclose(pBackUp);
                cout << "Copia de seguridad de DETALLE de VENTAS realizada correctamente" << endl;
            }

            void restaurarDetalleVenta(){

                FILE* p;
                FILE* pBackUp;

                p = fopen("detalle_ventas.dat", "wb");
                if (p == NULL) {
                    cout << "ERROR DE ARCHIVO" << endl;
                    return;
                }

                pBackUp = fopen("detalle_ventas_backup.bkp", "rb");
                if (pBackUp == NULL) {
                    cout << "ERROR DE ARCHIVO" << endl;
                    return;
                }

                Detalle reg;
                while (fread(&reg, sizeof reg, 1, pBackUp) == 1){
                    fwrite(&reg, sizeof reg, 1, p);
                }

                fclose(p);
                fclose(pBackUp);

                cout << "Restauracion de DETALLE de VENTAS realizada correctamente" << endl;
            }
    };

#endif // DETALLE_H_INCLUDED
