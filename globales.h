#ifndef UNTITLED_H_INCLUDED
#define UNTITLED_H_INCLUDED
#include <iostream>
#include <ctime>

using namespace std;


void cargarCadena(char *pal, int tam){
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++){
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }

    pal[i]='\0';
    fflush(stdin);
}

class Fecha{
    private:
        int dia,mes, anio;
    public:
        void Cargar(){
            cout<<endl;
            cout<<"Dia (dd): ";
            cin>>dia;
            setDia(dia);
            cout<<"Mes (mm): ";
            cin>>mes;
            setMes(mes);
            cout<<"Anio (aaaa): ";
            cin>>anio;
            setAnio(anio);
        }
        void Mostrar(){
            cout<<dia<<" / ";
            cout<<mes<<" / ";
            cout<<anio;
        }
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}

        void setDia(int d){
            while(d<1||d>31){
                cout<<"Dia entre 1 y 31: ";
                cin>>d;
            }
            dia=d;
        }
        void setMes(int m){
            while(m<1||m>12){
                cout<<"Mes entre 1 y 12: ";
                cin>>m;
            }
            mes=m;
        }
        void setAnio(int a){
            while(a<1920||a>2030){
                cout << "Ingrese un anio valido: ";
                cin >> a;
            }
           anio=a;
        }
};

void fechaActual(Fecha& reg) {
        time_t tiempo = time(nullptr);
        tm* fecha = localtime(&tiempo);

    reg.setAnio(fecha->tm_year + 1900);
    reg.setMes(fecha->tm_mon + 1);
    reg.setDia(fecha->tm_mday);
}




#endif // UNTITLED_H_INCLUDED
