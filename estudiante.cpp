#include<iostream>
#include<vector>
#include<list>
#include "materia.cpp"
#include "metodos.cpp"


#define minimosueldo 700

using namespace std;



class persona{
    protected:
        int edad;
        string nombre;
        int id;
        int sexo;
    public:
        persona(int _edad=0,string _nombre="persona",int _id=0,int _sexo=0){
            this->edad = _edad;
            nombre = _nombre;
            this->id = _id;
            this->sexo = _sexo;
        }
        int devolverid(void){
            return id;
        }
        void inserid(int x){
            this->id = x;

        }
        int devolveredad(void){
            return this->edad;
        }
        void insertedad(int x){
            this->edad = x;
        }
        string nombres(void){
            return nombre;
        }
        void insernombre(string elemento){
            this->nombre = elemento;
        }
        int devolversexo(void){
            return this->sexo;
        }
        void insersexo(int x){
            this->sexo = x;
        }
        virtual  int promedio(void){return 0;}
        virtual void curso(void){cout<<"Ronald"<<endl;}


};

class estudiante : public persona{
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
            string materias;
            for(int i=0;i < materiass;i++){
                pesos.push_back(new materia);
                cout<<"Ingrese Materia "<<i+1<<":";
                cin>>materias;
                ps[i]->insermateria(materias);
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


class profesor : public persona {
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
            pesos.push_back(new materia);
            ps = pesos.end()-1;
            string elemento;
            cout<<"Ingrese Materia: ";
            cin>>elemento;
            int n ;
            cout<<"Ingrese Peso: ";
            (*ps)->insermateria(elemento);
            (*ps)->inserpeso(n);
            this->_size++;
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

