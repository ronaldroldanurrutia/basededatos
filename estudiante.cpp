#include<iostream>
#include<vector>
#include<list>
#include "materia.cpp"
#include "metodos.cpp"


#define minimosueldo 700

using namespace std;


template<typename T>
class persona{
    protected:
        T edad;
        string nombre;
        T id;
        T sexo;
    public:
        persona(T _edad=0,string _nombre="persona",T _id=0,T _sexo=0){
            this->edad = _edad;
            nombre = _nombre;
            this->id = _id;
            this->sexo = _sexo;
        }
        T  devolverid(void){
            return id;
        }
        void inserid(T x){
            this->id = x;

        }
        T devolveredad(void){
            return this->edad;
        }
        void insertedad(T x){
            this->edad = x;
        }
        string nombres(void){
            return nombre;
        }
        void insernombre(string elemento){
            this->nombre = elemento;
        }
        T devolversexo(void){
            return this->sexo;
        }
        void insersexo(T x){
            this->sexo = x;
        }
        virtual  T promedio(void){return 0;}
        virtual void curso(void){cout<<"Ronald"<<endl;}


};

class estudiante : public persona<int>{
    private:
        int examen;
        int practicas;
        int grado;
        int nota;
        vector<materia*>pesos;
        vector<materia*>:: iterator ps;
    public:
        estudiante(int _examen =0,int _practicas=0,int _grado =0){
            this->examen = _examen;
            this->practicas = _practicas;
            this->grado = _grado;
            this->nota = examen/2+practicas/2;
        }
        int devolverexamen(void){
            return this->examen;
        }
        void inserexamen(int x){
            this->examen = x;
        }
        int devolverpractica(void){
            return this->practicas;
        }
        void inserpracticas(int x){
            this->practicas = x;
        }
        int devolvergrado(void){
            return this->grado;
        }
        void insergrado(int x){
            this->grado = x;
        }
        void ponernota(void){
            this->nota = examen/2+practicas/2;
        }
        int devolvernota(void){
            return this->nota;
        }
        int promedio(){
            return (examen+practicas)/2;
        }
        void curso(){
            int materiass;
            cout<<"Ingrese cantidad de materias"<<endl;
            cin>>materiass;
            this->_size+=materiass;
            string materias;
            ps = pesos.begin();
            for(int i=0;i < materiass;i++){
                pesos.push_back(new materia);
                cout<<"Ingrese Materia "<<i+1<<":";
                cin>>materias;
                cout<<"Ingrese Peso"<<i+1<<":";
                int n;
                cin>>n;
                (*ps)->insermateria(materias);
                (*ps)->inserpeso(n);
            }
        }
        void quitarmateria(string materias){
            ps = pesos.begin();
            for(; ps != pesos.end() ; ps++){
                if((*ps)->devolvermateria() == materias){
                    delete(*ps);
                    ps = pesos.erase(ps);
                    return ;
                }
            }
        }
        void ponercursos(){
            ps = pesos.begin();
            for(;ps != pesos.end();ps++){
                cout<<(*ps)->devolvermateria()<<endl;
            }
        }


};


class profesor : public persona<int> {
    private:
        vector<materia*>pesos;
        vector<materia*>::iterator ps;
        int sueldo;
        int _size;

    public:
        profesor(int _size=0){
            this->_size = 0;
            this->sueldo=0;
        }
        void insersueldo(int _sueldo){
            this->sueldo = _sueldo;
        }
        int devolversueldo(void){
            return this->sueldo;
        }
        void curso(){
            int materiass;
            cout<<"Ingrese cantidad de materias"<<endl;
            cin>>materiass;
            this->_size+=materiass;
            string materias;
            ps = pesos.begin();
            for(int i=0;i < materiass;i++){
                pesos.push_back(new materia);
                cout<<"Ingrese Materia "<<i+1<<":";
                cin>>materias;
                cout<<"Ingrese Peso"<<i+1<<":";
                int n;
                cin>>n;
                (*ps)->insermateria(materias);
                (*ps)->inserpeso(n);
            }
        }
        void materias(void){
            for(int i=0;i<this->_size;i++){
                spaces1(pesos[i]->devolvermateria());
            }

        }
        void quitarmateria(string materias){
            ps = pesos.begin();
            for(;ps != pesos.end();ps++){
                if((*ps)->devolvermateria() == materias){
                    delete (*ps);
                    ps = pesos.erase(ps);
                    return ;
                }
            }

        }

        int promedio(void){
            int suma=0;
            for(int i=0;i< this->_size;i++){
                suma+=sueldo*(pesos[i]->devolverpeso());
            }
            sueldo = suma;
            return sueldo;
        }
        int cantidad(void){
            return this->_size;
        }


};

