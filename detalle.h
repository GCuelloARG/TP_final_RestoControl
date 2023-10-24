#ifndef DETALLE_H_INCLUDED
#define DETALLE_H_INCLUDED
#include "productos.h"

class Detalle{
	private:
            Producto prod;
            int cant;
            float subTotal;
            bool estado;
	public:

            Cargar();
            Mostrar();
};

class ArchivoDetalle{
	private:
            char nombre[30];
	public:
            ArchivoDetalle(const char *nom){
            strcpy(nombre, nom);
            }

            int buscarRegistro(int id){
            Detalle reg;
            FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                cout<<"ERROR DE ARCHIVO"<<endl;
                return -2;
            }
            int cont=0;
            while(fread(&reg, sizeof reg, 1, p)==1){
                if(id==reg.getId()){
                    fclose(p);
                    return cont;
                }
                cont++;
            }
            fclose(p);
            return -1;
            }

            ArchivoDetalle leerRegistro(int pos){
                Detalle reg;
                reg.setEstado(false);

                FILE *p=fopen(nombre, "rb");
                if(p==NULL){
                    cout<<"ERROR DE ARCHIVO"<<endl;
                    return reg;
                }

                fseek(p, sizeof reg*pos, 0);
                fread(&reg, sizeof reg, 1, p);
                fclose(p);

                return reg;
            }

            bool modificarRegistro(int pos, Detalle reg){

                FILE *p=fopen("detalle_ventas.dat", "rb+");
                if(p==NULL){
                    cout<<"ERROR DE ARCHIVO"<<endl;
                    return false;
                }

                fseek(p, sizeof reg*pos, 0);
                bool escribio=fwrite (&reg, sizeof reg, 1, p);
                fclose(p);

                return escribio;
            }


            int contarRegistros(){

                FILE *p=fopen("detalle_ventas.dat", "rb");
                if(p==NULL){
                    cout << "ERROR DE ARCHIVO" <<endl;
                    system("pause");
                    return -2;
                }

                fseek(p, 0,2);
                int tam=ftell(p);
                fclose(p);

                return tam/sizeof reg;
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
