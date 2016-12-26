#include<iostream>
#include<vector>

using namespace std;


class materia{
    private:
        string materia;
        int peso;

    public:
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
};

