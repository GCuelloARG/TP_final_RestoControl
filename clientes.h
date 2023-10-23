#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

class Clientes{
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

            int t, o;

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


#endif // CLIENTES_H_INCLUDED
