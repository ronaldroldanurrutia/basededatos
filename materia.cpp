#include<iostream>


using namespace std;



class materia1{
    private:
        string materia;
        int peso;

    public:
        materia1(string _materia = "matematica" , int pesos =0){
            materia = _materia;
            this->peso = pesos;
        }
        string devolvermateria(void){
            return materia;
        }
        void insermateria(string _materia){
            materia = _materia;
        }
        int devolverpeso(void){
            return this->peso;
        }
        void inserpeso(int weight){this->peso = weight;}
        friend materia1& operator +(const materia1 &m1,const materia1 &m2);
        friend ostream& operator << (ostream &o,const materia1 &p);
};

template<typename T>
T suma(T elemento1,T elemento2){
    return elemento1 + elemento2;

}

materia1& operator +(materia1 &m1,materia1 &m2){
    string elemento;
    elemento = suma<string>(m1.devolvermateria(),"+");
    elemento = suma<string>(elemento,m2.devolvermateria());
    int n = suma<int>(m1.devolverpeso(),m2.devolverpeso());
    return *(new materia1(elemento,n)) ;
}
ostream& operator << (ostream &o,const materia1 &p){
    o << "(" << p.materia << "," << p.peso << ")" ;
    return o ;
}



