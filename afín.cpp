#include <iostream>
#include <string>
#include "álgebra.h"
using namespace std;

void Generar_claves(int &a, int &b);
string alfabeto="abcdefghijklmnopqrstuvwxyz";

class Afín {
public:
  int a,b,inv_a;
  Afín(){
    Generar_claves(a,b);//cambia los valores de los atributos
  }
  Afín(int a, int b){
    inv_a=inversa_1(a,alfabeto.size());//halla la inversa de la clave a
    this->b=b;
  }
  string cifrado(string msje) 
    {
      for (int i=0; i<msje.size();i++){
        int pos=alfabeto.find(msje[i]);
        msje[i]=alfabeto[divi(a*pos+b,alfabeto.size())];
      }
      return msje;
    }
  string descifrado(string msje) 
    {
      for (int i=0; i<msje.size();i++){
        int pos=alfabeto.find(msje[i]);
        msje[i]=alfabeto[divi(inv_a*(pos-b),alfabeto.size())];
      }
      return msje;
    }
};
int main()
{
    Afín Emisor;
    cout<<Emisor.a<<" "<<Emisor.b<<endl;
    Afín Receptor(Emisor.a,Emisor.b);
    string mensaje= "textoprueba";
    string m_c= Emisor.cifrado(mensaje);    
    string m_d= Receptor.descifrado(m_c);
    cout<<m_c<<endl<<m_d;
}

void Generar_claves(int &a,int &b){
  srand(time(NULL));
  a=rand()%100; //a=número aleatorio
  b=divi(rand()%100,alfabeto.size());//b=núm aleatorio (mod TamAlf)
  int aa=Euclides(a,alfabeto.size()); //mcd(a,TamAlf) 
  while(aa!=1){
    a=rand()%100;
    aa=Euclides(a,alfabeto.size());
  }
}