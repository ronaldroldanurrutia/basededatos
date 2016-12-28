#include "mostrar.cpp"

using namespace std;

void tabla(void){
    cout<<"Desea ingresar profesores?"<<endl;
    char a;
    cin>>a;
    if(a=='y'){
        tablamaestros elemento;
        cout<<"Ponga la cantidad de profesores : ";
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
        cout << "Desea quitar ?" ;
        cin>>elemento2;
        elemento.borrarprofesor(elemento2);
        elemento.mostrarprofesores();
    }
    else{
        tablaestudiantes elemento;
        cout<<"Ponga la cantidad de alumnos : ";
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            elemento.poneralumno();
        }
        elemento.mostraralumnos();
        cout<<"Desea buscar un alumno : ";
        string elemento2;
        cin>>elemento2;
        elemento.buscaralumno(elemento2);
        cout << "Desea quitar ?";
        char a;
        cin>> a;
        if(a == 'y'){
            cout << "Ponga al alumno : ";
            cin>>elemento2;
            elemento.borraralumno(elemento2);
            elemento.mostraralumnos() ;
        }
    }

}
