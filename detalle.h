#ifndef DETALLE_H_INCLUDED
#define DETALLE_H_INCLUDED
#include "productos.h"
#include "ventas.h"

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

            void Mostrar(){
                cout << "ID PROD:" << id << endl;
                cout << "NOMBRE: " << nombre << endl;
                cout << "CANT:" << cant << endl;
                cout << "SUBTOTAL: $" << subTotal << endl;
                cout << endl;
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
        cout<<det.getNombre()<<endl;
        cout<<"CANTIDAD: ";
        cin>>cant;
        det.setCant(cant);
        det.setEstado(true);
        subtotal=prod.getPrecio()*cant;
        det.setSubTotal(subtotal);
        totalCompra+=subtotal;

        cout<<"Importe: $"<<subtotal<<endl;
        cout<<endl;

        //agregar a archivo
        bool grabo=arcDet.agregarRegistro(det);
        cout<<endl<<grabo<<endl;                //CONTROL

        /*//destruir obj detalle >> REVISAR. SALE ERROR CUANDO LLEGA A ESTA PARTE.
        QUIZAS SI USA PUNTERO NO HACE FALTA DESTRUIRLO
        delete det;*/
        }else{cout<<"No existe producto con ese ID";}
        cout<<"ID PRODUCTO: ";
        cin>>id;
    }
    cout<<endl<<" ** Venta cargada con exito **";
    return totalCompra;
}

void mostrarListaDetalles(){    // es por numero de venta
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

void limpiarArchivoDetalles(){  // BORRAR/COMENTAR
    FILE *p=fopen("detalles.dat","wb");
    cout<<endl<<"Archivo BORRADO"<<endl;
    fclose(p);
}

#endif // DETALLE_H_INCLUDED
