#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

class Cliente{
private:
    int id;
    char nombre[30];
    char direccion[30];
    int tel;
    bool estado;
public:
    void setId(int n){id=n;}
    void setNombre(const char *nomb){
        strcpy(nombre,nomb);
    }
    void setDireccion(const char *dir){
        strcpy(direccion, dir);
    }
    void setTel(int t){tel=t;}
    void setEstado(bool st){estado=st;}

    int getId(){return id;}
    const char *getNombre(){return nombre;}
    const char *getDireccion(){return direccion;}
    int getTel(){return tel;}

    void Cargar(int id){

            int t;

            setId(id);
            cout << "Nombre: ";
            cargarCadena(nombre,29);
            cout << "Direccion: ";
            cargarCadena(direccion,29);
            cout << "Telefono: ";
            cin >> t;
            setTel(t);
            estado=(true);
        }

    void Mostrar(){
            cout << "ID Cliente: ";
            cout << id << endl;
            cout << "Nombre: ";
            cout << nombre << endl;
            cout << "Direccion: ";
            cout << direccion << endl;
            cout << "Telefono: ";
            cout << tel << endl;
            cout << endl;
        }


};

class archivoCliente{
    private:
        char nombre[30];
    public:
        archivoCliente(const char *nomb){
            strcpy(nombre, nomb);
        }

        bool agregarRegistro(Cliente reg){
            FILE *p=fopen(nombre,"ab");
                if(p==NULL){
                    cout<<"ERROR DE ARCHIVO-ag"<<endl;
                    return false;
                }

            bool escribio=fwrite(&reg, sizeof reg, 1, p);
            fclose(p);
            return escribio;
        }



        int buscarRegistro(int id){
            Cliente reg;
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

        Cliente leerRegistro(int pos){
            Cliente reg;
            //reg.setEstado(false);

            FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                cout<<"ERROR DE ARCHIVO-leer"<<endl;
                return reg;
            }

            fseek(p,sizeof(Cliente)*pos,0);
            fread(&reg, sizeof (Cliente),1,p);
            fclose(p);

            return reg;
        }


};


#endif // CLIENTES_H_INCLUDED
