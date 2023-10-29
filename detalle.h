#ifndef DETALLE_H_INCLUDED
#define DETALLE_H_INCLUDED
#include "productos.h"

using namespace std;

class Detalle{
	private:
            int id;
            int cant;
            //agregar nombre y setearlo desde producto
            float subTotal;
            bool estado;
	public:

            void setID(int i){id=i;}
            void setEstado(bool st){estado=st;}
            void setCant(int c){cant=c;}
            int getId(){return id;}
            int getCant(){return cant;}
            bool getEstado(){return estado;}
            float getSubt(){return subTotal;}
            void Cargar(){
               cout<<"ID";
               cin>>id;
               cout<<"Cant";
               cin>>cant;
            }

            void Mostrar(){
                cout << id << endl;
                cout << cant << endl;
                cout << subTotal << endl;
            }

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
                cout<<"ERROR DE ARCHIVO - buscar"<<endl;
                return -2;
            }
            int cont=0;
            while(fread(&reg, sizeof reg,1,p)==1){
                if(id==reg.getId()){
                    fclose(p);
                    return cont;
                    }
                    cont++;
                }
            fclose(p);
            return -1;
            }

        int contarRegistros(){
            FILE *p=fopen(nombre, "rb");
            if(p==NULL){
                cout << "ERROR DE ARCHIVO -contar" <<endl;
                system("pause");
                return -2;
            }
            fseek(p, 0,2);
            int tam=ftell(p);
            fclose(p);
            return tam/sizeof(Detalle);
        }

        Detalle leerRegistro(int pos){
            Detalle reg;
            FILE *p=fopen(nombre,"rb");
            if (p==NULL){
                cout <<"ERROR DE ARCHIVO -leer"<<endl;
                return reg;
            }
            fseek(p,sizeof(Detalle)*pos, 0);
            fread(&reg, sizeof (Detalle),1,p);
            fclose(p);
            return reg;
        }

        bool agregarRegistro(Detalle reg){
            FILE *p=fopen(nombre,"ab");
                if(p==NULL){
                    cout<<"ERROR DE ARCHIVO-ag"<<endl;
                    return false;
                }
            bool escribio=fwrite(&reg, sizeof reg, 1, p);
            fclose(p);
            return escribio;
        }
    };

void cargarDetalle(){
    ArchivoProducto arcProd("productos.dat");
    ArchivoDetalle arcDet("detalles.dat");

    Detalle det;
    Producto prod;
    int id, cant;
    cout<<endl<<"ID PRODUCTO: ";
    cin>>id;
    while(id!=0){
        det.setID(id);
        int pos=arcProd.buscarRegistro(id);
        prod=arcProd.leerRegistro(pos);
        cout<<prod.getNombre()<<endl;
        cout<<"CANTIDAD: ";
        cin>>cant;
        det.setCant(cant);
        det.setEstado(true);
        cout<<endl;

        //agregar a archivo
        arcDet.agregarRegistro(det);

        /*
        //destruir obj detalle >> REVISAR. SALE ERROR CUANDO LLEGA A ESTA PARTE. QUIZAS SI USA PUNTERO NO HACE FALTA DESTRUIRLO
        delete det;*/

        cout<<"ID PRODUCTO: ";
        cin>>id;
    }

    cout<<endl<<" ** Venta cargada con exito **";
    cout<<endl;
}

void mostrarListaDetalles(){
    Detalle det;
    ArchivoDetalle arcDet("detalles.dat");
    int cantReg=arcDet.contarRegistros();
    for(int i=0;i<cantReg;i++){
        det=arcDet.leerRegistro(i);
        if(det.getEstado()==true){
            det.Mostrar();
        }
    }
    system("pause");
    system("cls");
}


#endif // DETALLE_H_INCLUDED
