#include "estudiante.cpp"





using namespace std;

int global =0;
int mundo = 0;
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
            pr = Pr.end();
            Pr.push_back(new profesor);
            (*pr)->curso();
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
            global++;

        }
        void mostrarprofesores(void){

            spaces1("nombres");
            spaces1("edad");
            spaces1("id");
            spaces1("sexo");
            spaces1("sueldo");
            cout<<endl;
            for(int i=0;i<this->_size;i++){
                    cout<<(*pr)->nombres();
                    espacios(whites-longitud((*pr)->nombres()));
                    cout<<(*pr)->devolveredad();
                    espacios(whites-numero((*pr)->devolveredad()));
                    cout<<(*pr)->devolverid();
                    espacios(whites-numero((*pr)->devolverid()));
                    cout<<(*pr)->devolversexo();
                    espacios(whites-numero((*pr)->devolversexo()));
                    cout<<(*pr)->devolversueldo()<<endl;
                }


        }
        void buscarprofesor(string profesor){
            spaces1("nombres");
            spaces1("edad");
            spaces1("id");
            spaces1("sexo");
            spaces1("sueldo");
            for(pr = Pr.begin();pr!=Pr.end();pr++){
                if((*pr)->nombres()==profesor){
                    cout<<(*pr)->nombres();
                    espacios(whites-longitud((*pr)->nombres()));
                    cout<<(*pr)->devolveredad();
                    espacios(whites-numero((*pr)->devolveredad()));
                    cout<<(*pr)->devolverid();
                    espacios(whites-numero((*pr)->devolverid()));
                    cout<<(*pr)->devolversexo();
                    espacios(whites-numero((*pr)->devolversexo()));
                    cout<<(*pr)->devolversueldo()<<endl;
                    return ;
                }
            }
            cout<<"No Existe"<<endl;

        }
        void buscarmaterias(string profesor){
            for(pr=Pr.begin();pr !=Pr.end();pr++){
                if((*pr)->nombres()==profesor){
                    cout<<"Nombre: "<<(*pr)->nombres()<<endl;
                    (*pr)->materias();
                    cout<<endl;
                    return ;
                }

            }
            cout<<"No se encuentra "<<endl;

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
        void ordenarpornota(void){
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
        void borrarprofesor(string nombre){
            pr = Pr.begin();
            for(int i=0;i<this->_size;i++){
                if((*pr)->nombres()==nombre){
                    delete (*pr);
                    pr = Pr.erase(pr);
                }
                pr++;
            }
            cout<<"No se encuentra"<<endl;
            return ;

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
            cout<<"No se encuentra"<<endl;
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
            spaces1("nombres");
            spaces1("edad");
            spaces1("id");
            spaces1("sexo");
            spaces1("examen");
            spaces1("practica");
            spaces1("grado");
            cout<<endl;
            for(es = Es.begin();es != Es.end() ;es++){
                    cout<<(*es)->nombres();
                    espacios(whites-longitud((*es)->nombres()));
                    cout<<(*es)->devolveredad();
                    espacios(whites-numero((*es)->devolveredad()));
                    cout<<(*es)->devolverid();
                    espacios(whites-numero((*es)->devolverid()));
                    cout<<(*es)->devolversexo();
                    espacios(whites-numero((*es)->devolversexo()));
                    cout<<(*es)->devolverexamen();
                    espacios(whites-numero((*es)->devolverexamen()));
                    cout<<(*es)->devolverpractica();
                    espacios(whites-numero((*es)->devolverpractica()));
                    cout<<(*es)->devolvergrado();
                    espacios(whites-numero((*es)->devolvergrado()));
                    cout<<endl;
            }
        }
        void buscaralumno(string alumno){
            spaces1("nombres");
            spaces1("edad");
            spaces1("id");
            spaces1("sexo");
            spaces1("examen");
            spaces1("practica");
            spaces1("grado");
            cout<<endl;
            for(es = Es.begin();es != Es.end();es++){
                if((*es)->nombres()==alumno){
                    cout<<(*es)->nombres();
                    espacios(whites-longitud((*es)->nombres()));
                    cout<<(*es)->devolveredad();
                    espacios(whites-numero((*es)->devolveredad()));
                    cout<<(*es)->devolverid();
                    espacios(whites-numero((*es)->devolverid()));
                    cout<<(*es)->devolversexo();
                    espacios(whites-numero((*es)->devolversexo()));
                    cout<<(*es)->devolverexamen();
                    espacios(whites-numero((*es)->devolverexamen()));
                    cout<<(*es)->devolverpractica();
                    espacios(whites-numero((*es)->devolverpractica()));
                    cout<<(*es)->devolvergrado();
                    espacios(whites-numero((*es)->devolvergrado()));
                    return ;
                }
            }
            cout<<"No existe"<<endl;
        }




};





