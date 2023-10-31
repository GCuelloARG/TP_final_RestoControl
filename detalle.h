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
            float subTotal;
            bool estado;
	public:
            void setID(int i){id=i;}
            void setCant(int c){cant=c;}
            void setNumVen(int nv){numVen=nv;}
            void setNombre(const char *nomb){
                strcpy(nombre,nomb);
            }
            void setSubTotal(float st){subTotal=st;}
            void setEstado(bool e){estado=e;}

            int getId(){return id;}
            int getCant(){return cant;}
            int getNumVen(){return numVen;}
            const char *getNombre(){return nombre;}
            float getSubt(){return subTotal;}
            bool getEstado(){return estado;}

            void Cargar(){
               cout<<"ID: ";
               cin>>id;
               cout<<"Cantidad: ";
               cin>>cant;
            }

            void Mostrar(int x, int y){
                gotoxy(x, y);
                cout << id<<"\t"<<nombre;
                gotoxy(x+21, y);
                cout<<cant<<"\t\t"<<subTotal<< endl;
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
    int id, cant;
    float subtotal, totalCompra=0;
    cout<<endl<<"ID PRODUCTO: ";
    cin>>id;
    while(id!=0){
        det.setID(id);
        int pos=arcProd.buscarRegistro(id);
        if(pos>=0){
            prod=arcProd.leerRegistro(pos);
            //falta validar prod
            det.setNombre(prod.getNombre());
            cout<<"Producto: "<<det.getNombre()<<endl;
            cout<<"Precio unitario $"<<prod.getPrecio()<<endl;
            cout<<"Cantidad: ";
            cin>>cant;
            det.setCant(cant);
            det.setEstado(true);
            subtotal=prod.getPrecio()*cant;
            det.setSubTotal(subtotal);
            totalCompra+=subtotal;
            cout<<"Importe: $"<<subtotal<<endl;
            cout<<endl;
            arcDet.agregarRegistro(det);

        }else{cout<<"No existe producto con ese ID"<<endl;}
            cout<<"ID PRODUCTO: ";
            cin>>id;
    }
    cout<<endl<<" ** Venta cargada con exito **"<<endl;
    return totalCompra;
}


void limpiarArchivoDetalles(){  // BORRAR/COMENTAR
    FILE *p=fopen("detalles.dat","wb");
    cout<<endl<<"Archivo BORRADO"<<endl;
    fclose(p);
}

#endif // DETALLE_H_INCLUDED
