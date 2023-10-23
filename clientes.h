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
            cout << "Tipo (1-21): ";
            cin >> t;
            setTipo(t);
            cout << "Anio de origen: ";
            cin >> o;
            setOrigen(o);
            estado=(true);
        }

};


#endif // CLIENTES_H_INCLUDED
