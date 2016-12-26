#include<iostream>
#include<vector>
#include "estudiante.cpp"

using namespace std;

int main(){
        vector<estudiante*>v;
        vector<estudiante*>:: iterator vs;
        v.push_back(new estudiante);
        vs = v.end() -1;
        (*vs)->insertedad(20);
        cout<<(*vs)->devolveredad()<<endl;
        return 0;


}
