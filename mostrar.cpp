#include "estudiante.cpp"




using namespace std;

class tablamaestros{
    private:
        int _size;
        vector<profesor*>Pr;
        vector<profesor*>::iterator pr;
    public:
        tablamaestros(const int _tam=0){
            this->_size = _tam;
        }
        void ponerprofesor(void){

            Pr.push_back(new profesor);
            pr = Pr.end()-1;
            string elemento;
            this->_size++;
            int n;
            cout<<"Ingrese Nombre: ";
            cin>>elemento;
            (*pr)->insernombre(elemento);
            cout<<"Ingrese Edad: ";
            cin>>n;
            (*pr)->insertedad(n);
            cout<<"Ingrese Id: ";
            cin>>n;
            (*pr)->inserid(n);
            cout<<"Ingrese sexo: ";
            cin>>elemento;
            while(elemento!="masculino" && elemento!="femenino"){
                cout<<"Ingrese de nuevo: ";
                cin>>elemento;
                cout<<endl;
            }
            if(elemento=="masculino"){
                 (*pr)->insersexo(1);
            }
            else{
                 (*pr)->insersexo(2);
            }
            cout<<"Ingrese Sueldo: ";
            cin>>n;
            (*pr)->insersueldo(n);
            (*pr)->curso();
        }
        void mostrarprofesores(void){
            pr = Pr.begin();
            for(int i=0;i<this->_size;i++){
                    file << "profesor" << i+1 << endl;
                    spaces1("nombres",13);
                    file << ": ";
                    spaces1((*pr)->nombres(),0);
                    file << endl;
                    spaces1("edad",19);
                    file << ": ";
                    spaces((*pr)->devolveredad(),0);
                    file << endl;
                    spaces1("id",25);
                    file << ": ";
                    spaces((*pr)->devolverid(),0);
                    file << endl;
                    spaces1("sexo",20);
                    file << ": ";
                    spaces((*pr)->devolversexo(),0);
                    file << endl;
                    spaces1("sueldo",17);
                    file << ": ";
                    spaces((*pr)->devolversueldo(),0);

                    file <<endl;
                    (*pr)->ponercursos() ;
                    pr++;
                }



        }
        void cursosysueldos(void){
            pr = Pr.begin();
            int i=0;
            for(;i < this->_size;i++){
                file << "profesor" << i+1 << ":" << endl ;
                (*pr)->ponercursos();
                pr++;
            }
        }
        void buscarprofesor(string profesor){
            for(pr = Pr.begin();pr!=Pr.end();pr++){
                if((*pr)->nombres()==profesor){
                    spaces1("nombres",13);
                    file << ": ";
                    spaces1((*pr)->nombres(),0);
                    file << endl;
                    spaces1("edad",19);
                    file << ": ";
                    spaces((*pr)->devolveredad(),0);
                    file << endl;
                    spaces1("id",25);
                    file << ": ";
                    spaces((*pr)->devolverid(),0);
                    file << endl;
                    spaces1("sexo",19);
                    file << ": ";
                    spaces((*pr)->devolversexo(),0);
                    file << endl;
                    spaces1("sueldo",17);
                    file << ": ";
                    spaces((*pr)->devolversueldo(),0);
                    return ;
                }
            }
            file <<"No Existe"<<endl;

        }
        void buscarmaterias(string profesor){
            for(pr=Pr.begin();pr !=Pr.end();pr++){
                if((*pr)->nombres()==profesor){
                    file <<"Nombre: "<<(*pr)->nombres()<<endl;
                    (*pr)->materias();
                    file <<endl;
                    return ;
                }

            }
            file <<"No se encuentra "<<endl;

        }
        void ordenarpornombre(void){
            for(int i=0;i<this->_size-1;i++){
                for(int j=0;j<this->_size-1-i;j++){
                    if(Pr[j]->nombres()>Pr[j+1]->nombres()){
                        vector<profesor*>l;
                        l.push_back(new profesor);
                        l[0] = Pr[j+1] ;
                        Pr[j+1] = Pr[j] ;
                        Pr[j] = l[0] ;

                    }
                }

            }
        }
        void ordenaredad(void){
            for(int i=0;i<this->_size-1;i++){
                for(int j=0;j<this->_size-1-i;j++){
                    if(Pr[j]->devolveredad()>Pr[j+1]->devolveredad()){
                        vector<profesor*>l;
                        l.push_back(new profesor);
                        l[0] = Pr[j];
                        Pr[j]=Pr[j+1];
                        Pr[j+1] = l[0];
                    }
                }
            }
        }
        void ordenarporsueldo(void){
            for(int i=0;i<this->_size-1;i++){
                for(int j=0;j<this->_size-1-i;j++){
                    if(Pr[j]->devolversueldo()>Pr[j+1]->devolversueldo()){
                        vector<profesor*>l;
                        l.push_back(new profesor);
                        l[0] = Pr[j];
                        Pr[j]=Pr[j+1];
                        Pr[j+1] = l[0];
                    }
                }
            }

        }
        void borrarprofesor(string nombre){
            pr = Pr.begin();
            for(int i=0;i<this->_size;i++){
                if((*pr)->nombres()==nombre){
                    delete (*pr);
                    pr = Pr.erase(pr);
                }
                pr++;
            }
            file <<"No se encuentra"<<endl;
            return ;

        }
        void tam(void){
            cout<<"Hay :"<<this->_size<<"maestros"<<endl;
        }



};
class tablaestudiantes{
    private:
        int _size;
        vector<estudiante*>Es;
        vector<estudiante*>::iterator es;
    public:
        tabla(int _tam =0){
            this->_size = _tam;
        }
        void poneralumno(void){
            Es.push_back(new estudiante);
            es = Es.end()-1;
            string elemento;
            this->_size++;
            int n;
            cout<<"Ingrese Nombre: ";
            cin>>elemento;
            (*es)->insernombre(elemento);
            cout<<"Ingrese Edad: ";
            cin>>n;
            (*es)->insertedad(n);
            cout<<"Ingrese Id: ";
            cin>>n;
            (*es)->inserid(n);
            cout<<"Ingrese sexo: ";
            cin>>elemento;
            while(elemento!="masculino" && elemento!="femenino"){
                cout<<"Ingrese de nuevo: ";
                cin>>elemento;
                cout<<endl;
            }
            if(elemento=="masculino"){
                (*es)->insersexo(1);
            }
            else{
                (*es)->insersexo(2);
            }
            cout<<"Ingrese Examen: ";
            cin>>n;
            (*es)->inserexamen(n);
            cout<<"Ingrese Practicas: ";
            cin>>n;
            (*es)->inserpracticas(n);
            cout<<"Ingrese Grado: ";
            cin>>n;
            (*es)->insergrado(n);
            (*es)->curso();


        }
        void tamdelalista(void){
            cout<<"El tam es : "<<this->_size<<endl;

        }
        void borraralumno(string nombre){
            es = Es.begin() ;
            for(int i=0;this->_size;i++){
                if(Es[i]->nombres()==nombre){
                        delete (*es);
                        es = Es.erase(es);
                }
                es++;
            }
            file <<"No se encuentra"<<endl;
            return ;

        }
        void ordenarpornombre(void){
            for(int i=0;i<this->_size-1;i++){
                for(int j=0;j<this->_size-1-i;j++){
                    if(Es[j]->nombres()>Es[j+1]->nombres()){
                        vector<estudiante*>l;
                        l.push_back(new estudiante);
                        l[0] = Es[j];
                        Es[j]=Es[j+1];
                        Es[j+1] = l[0];
                    }
                }

            }
        }
        void ordenarporedad(void){
            for(int i=0;i<this->_size-1;i++){
                for(int j=0;j<this->_size-1-i;j++){
                    if(Es[j]->devolveredad()>Es[j+1]->devolveredad()){
                        vector<estudiante*>l;
                        l.push_back(new estudiante);
                        l[0] = Es[j];
                        Es[j]=Es[j+1];
                        Es[j+1] = l[0];
                    }
                }

            }
        }
        void mostraralumnos(void){
            int i=1;
            for(es = Es.begin();es != Es.end() ;es++,i++){
                    file << "alumno" << i << endl;
                    spaces1("nombres",13);
                    file << ": ";
                    spaces1((*es)->nombres(),0);
                    file << endl;
                    spaces1("edad",19);
                    file << ": ";
                    spaces((*es)->devolveredad(),0);
                    file << endl;
                    spaces1("id",25);
                    file << ": ";
                    spaces((*es)->devolverid(),0);
                    file << endl;
                    spaces1("sexo",19);
                    file << ": ";
                    spaces((*es)->devolversexo(),0);
                    file << endl;
                    spaces1("examen",17);
                    file << ": ";
                    spaces((*es)->devolverexamen(),0);
                    spaces1("practica",14) ;
                    file << ": ";
                    spaces((*es)->devolverpractica(),0);
                    spaces1("grado",17);
                    file << ": ";
                    spaces((*es)->devolvergrado(),0);
                    file <<endl;
            }
        }
        void buscaralumno(string alumno){
            for(es = Es.begin();es != Es.end();es++){
                if((*es)->nombres()==alumno){
                    spaces1("nombres",13);
                    file << ": ";
                    spaces1((*es)->nombres(),0);
                    file << endl;
                    spaces1("edad",19);
                    file << ": ";
                    spaces((*es)->devolveredad(),0);
                    file << endl;
                    spaces1("id",25);
                    file << ": ";
                    spaces((*es)->devolverid(),0);
                    file << endl;
                    spaces1("sexo",19);
                    file << ": ";
                    spaces((*es)->devolversexo(),0);
                    file << endl;
                    spaces1("examen",17);
                    file << ": ";
                    spaces((*es)->devolverexamen(),0);
                    spaces1("practica",14) ;
                    file << ": ";
                    spaces((*es)->devolverpractica(),0);
                    spaces1("grado",17);
                    file << ": ";
                    spaces((*es)->devolvergrado(),0);
                    return ;
                }
            }
            file <<"No existe"<<endl;
        }




};





