#ifndef DETALLE_H_INCLUDED
#define DETALLE_H_INCLUDED
#include "productos.h"
#include "ventas.h"
#include "rlutil.h"

using namespace std;

class Detalle{
	private:
            int id;
            int cant;
            int numVen;
            char nombre[30];
            float pu;
            float subTotal;
            bool estado;
	public:
            void setID(int i){id=i;}
            void setCant(int c){cant=c;}
            void setNumVen(int nv){numVen=nv;}
            void setNombre(const char *nomb){
                strcpy(nombre,nomb);
            }
            void setPu(float n){pu=n;}
            void setSubTotal(float st){subTotal=st;}
            void setEstado(bool e){estado=e;}

            int getId(){return id;}
            int getCant(){return cant;}
            int getNumVen(){return numVen;}
            const char *getNombre(){return nombre;}
            float getSubt(){return subTotal;}
            float getPu(){return pu;}
            bool getEstado(){return estado;}

            void Cargar(){
               cout<<"ID: ";
               cin>>id;
               cout<<"Cantidad: ";
               cin>>cant;
            }

            void Mostrar(int x, int y){
                gotoxy(x+1, y);
                cout << id<<"\t"<<nombre;
                gotoxy(x+28,y);
                cout<<"$"<<pu;
                gotoxy(x+36, y);
                cout<<cant<<"\t   $"<<subTotal<< endl;
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
                    FILE *p=fopen("detalles.dat", "wb");
                    return 0;
                    if(p==NULL){
                        cout << "ERROR DE ARCHIVO -contar" <<endl;
                        system("pause");
                        return -2;
                    }
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

float cargarDetalle(int nv){
    ArchivoProducto arcProd("productos.dat");
    ArchivoDetalle arcDet("detalles.dat");
    Detalle det;
    Producto prod;
    det.setNumVen(nv);
    int id, cant,x=2,y=4;
    float subtotal, totalCompra=0;
        gotoxy(42, 3);
        cout<<"\t\t Ingrese ID del Producto."<<endl;
        gotoxy(42, 4);
        cout<<"\t\t      (0 para salir)\n"<<endl;

    gotoxy(1, 3);
    cout<<"ID  NOMBRE                 P.U.  Cant   SubT";
    gotoxy(x,y);
    cin>>id;
    while(id!=0){
        det.setID(id);
        int pos=arcProd.buscarRegistro(id);

            prod=arcProd.leerRegistro(pos);
            if(pos>=0&&prod.getEstado()==true){
            det.setNombre(prod.getNombre());
            gotoxy(x+3,y);
            cout<<det.getNombre();
            gotoxy(x+25,y);
            cout<<"$"<<prod.getPrecio();
            det.setPu(prod.getPrecio());
            gotoxy(x+33,y);
            cin>>cant;
            det.setCant(cant);
            det.setEstado(true);
            subtotal=prod.getPrecio()*cant;
            det.setSubTotal(subtotal);
            totalCompra+=subtotal;
            gotoxy(x+38,y);
            cout<<"$"<<subtotal;
            arcDet.agregarRegistro(det);
            y++;

        }else{
            cout<<"\nNo existe producto con ese ID"<<endl;
            system("pause");
            limpiarMensaje(x, y);

        }
            gotoxy(x,y);
            cin>>id;
    }
    gotoxy(x+19,y+2);
    cout<<"Total: $"<<totalCompra<<endl;
    cout<<endl<<"\n\n ** Venta cargada con exito **"<<endl;
    system("pause");
    system("cls");
    return totalCompra;
}


void limpiarArchivoDetalles(){  // BORRAR/COMENTAR
    FILE *p=fopen("detalles.dat","wb");
    cout<<endl<<"Archivo BORRADO"<<endl;
    fclose(p);
}

#endif // DETALLE_H_INCLUDED
