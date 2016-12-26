#include "mostrar.cpp"

using namespace std;

void tabla(void){
     cout<<"Desea ingresar profesores?"<<endl;
    char a;
    cin>>a;
    if(a=='y'){
        tablamaestros elemento;
        cout<<"Ponga la cantidad de: ";
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            elemento.ponerprofesor();
        }
        elemento.mostrarprofesores();
        cout<<"Desea buscar un profesor: ";
        string elemento2;
        cin>>elemento2;
        elemento.buscarprofesor(elemento2);
    }
    else{
        tablaestudiantes elemento;
        cout<<"Ponga la cantidad de: ";
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            elemento.poneralumno();
        }
        elemento.mostraralumnos();
        cout<<"Desea buscar un profesor: ";
        string elemento2;
        cin>>elemento2;
        elemento.buscaralumno(elemento2);

    }

}
