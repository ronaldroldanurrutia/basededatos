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
        vector<materia1*>pesos;
        vector<materia1*>::iterator ps;
        materia1 elemento;
    public:
        estudiante(int _examen =0,int _practicas=0,int _grado =0){
            this->examen = _examen;
            this->practicas = _practicas;
            this->grado = _grado;
            this->nota = examen/2+practicas/2;
            elemento.insermateria("");
            elemento.inserpeso(0);
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
            cout <<"hola";
            cin>>materiass;

            for(int i=0;i < materiass;i++){
                string materias;
                cout<<"Ingrese Materia "<<i+1<<":";
                cin>>materias;
                cout<<"Ingrese Peso"<<i+1<<":";
                int n;
                cin>>n;
                pesos.push_back(new materia1(materias,n));
                materia1 elemento2(materias,n);
                elemento = elemento+elemento2;

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
            file << "No hay esa materia" << endl;
        }
        void ponercursos(){
            ps = pesos.begin();
            file << "Curso/s:\n" ;
            for(;ps != pesos.end();ps++){
                file << (*ps)->devolvermateria() << endl;
            }
            int sueldo =0;
            for(ps = pesos.begin() ; ps != pesos.end() ; ps++){
                sueldo+=(*ps)->devolverpeso()*minimosueldo;

            }
            file << "sueldo: " << sueldo;
            file << endl ;
            file << elemento << endl ;
        }


};


class profesor : public persona<int> {
    private:
        vector<materia1*>pesos;
        vector<materia1*>::iterator ps;
        int sueldo;
        int _size;
        materia1 elemento ;


    public:
        profesor(int _size=0){
            this->_size = 0;
            this->sueldo=0;
            elemento.insermateria("");
            elemento.inserpeso(0);
        }
        void insersueldo(int _sueldo){
            this->sueldo = _sueldo;
        }
        int devolversueldo(void){
            return this->sueldo;
        }
        void curso(){
            int materiass;
            cout<<"Ingrese cantidad de materias" ;
            cin>>materiass;
            string materias;
            for(int i=0;i < materiass;i++){
                pesos.push_back(new materia1);
                ps = pesos.end() -1 ;
                cout<<"Ingrese Materia "<<i+1<<":";
                cin>>materias;
                cout<<"Ingrese Peso"<<i+1<<":";
                int n;
                cin>>n;
                materia1 elemento2(materias,n);
                elemento = elemento+elemento2;
                (*ps)->insermateria(materias);
                (*ps)->inserpeso(n);
            }
            file <<elemento<<endl;
        }
        void materias(void){
            for(int i=0;i<this->_size;i++){
                spaces1(pesos[i]->devolvermateria(),0);
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
            file << "No esta" << endl;

        }
        void ponercursos(){
            ps = pesos.begin();
            file << "Curso:\n" ;
            for(;ps != pesos.end();ps++){
                file << (*ps)->devolvermateria() << endl;
            }
            int sueldo =0;
            for(ps = pesos.begin() ; ps != pesos.end() ; ps++){
                sueldo+=(*ps)->devolverpeso()*minimosueldo;

            }
            file << "sueldo: " << sueldo;
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

