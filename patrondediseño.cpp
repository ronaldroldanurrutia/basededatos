#include<iostream>
#include<vector>
#include "estudiante.cpp"

using namespace std;

template<typename RR>

class iteratorr{
    private:
        vector<estudiante*>v;
        vector<profesor*>v1;
        vector<estudiante*>::iterator v1s;
        vector<profesor*>::iterator vs;
        RR alumno;
        RR profesorr;
    public:

        iteratorr(const RR _constante =0,const RR _alumno=0){
            this->constante=_constante;
            this->profesorr=_alumno;
        }
        void pushestudiante(){
            v.push_back(new estudiante);
            this->alumno++;
        }
        void pushalumno(){
            v1.push_back(new profesor);
            this->profesorr++;
        }
       RR recorreralumno(){
            return this->alumno;
       }
       RR recorrerprofesor(){
            return this->profesorr;
       }


};

