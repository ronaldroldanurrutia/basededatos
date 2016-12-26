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



materia1& operator +(const materia1 &m1,const materia1 &m2){
    return *(new materia1(m1.materia + "+" + m2.materia, m1.peso + m2.peso) ) ;
}
ostream& operator << (ostream &o,const materia1 &p){
    o << "(" << p.materia << "," << p.peso << ")" ;
    return o ;
}

