#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(){
  string entrada;
  int n_int;
  //int n_int=0, base=1;
  cout<<"Ingrese un número: "; cin>>entrada;
  istringstream n_string(entrada);
  n_string>>n_int;
/*
  for (int f=n_string.size()-1; f>=0; f--){
    n_int+= ((int)n_string[f]) *base;
    base*=10;
    cout<<((int)n_string[f]);
  }*/
  cout<<endl<<n_int;

}