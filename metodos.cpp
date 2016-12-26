#include<iostream>
#define whites 10
#define blacks 20




using namespace std;

void espacios(int n){
    for(int i=0;i<n;i++){
        cout<<" ";
    }

}
int longitud(string n){
    return n.size();

}
int numero(int n){
    if(n==0){
        return 1;
    }
    int suma=0;
    for(;n!=0;){
        suma++;
        n/=10;
    }
    return suma;
}
void spaces(int elemento){
    cout<<elemento;
    espacios(whites-numero(elemento));

}
void spaces1(string elemento){
    cout<<elemento;
    espacios(whites-longitud(elemento));

}

