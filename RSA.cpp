#include <iostream>
#include <string>
#include "álgebra.h"
using namespace std;

class RSA {
  int d,p,q,oN;
  public:
  int e,n;
  RSA(){
    Generar_claves();
    cout<<p<<" "<<q<<" "<<n<<" "<<oN<<" "<<e<<" "<<d<<endl;
  }
  RSA(int e, int n){
    this->e=e;
    this->n=n;
  }
  int cifrado(int m) 
    {
      int C=ExpMod(m,e,n);
      return C;
    }
  int descifrado(int m) 
    {
      int D=ExpMod(m,d,n);
      return D;
    }
  void Generar_claves(){
    p=Euler(time(NULL));
    q=Euler(time(NULL)+2);
    while (p==q){
      q=Euler(time(NULL)+2);
    }
    n=p*q;
    oN=(p-1)*(q-1);
    e=rand()%oN;
    int ee=Euclides(e,oN); 
    while(ee!=1){
      e=rand()%oN;
      ee=Euclides(e,oN);
    }
    d=inversa_1(e,oN);
  }
};

int main()
{
  RSA Receptor;
  RSA Emisor(Receptor.e,Receptor.n);
  int m=2555;
  int m_C=Emisor.cifrado(m);
  int m_D=Receptor.descifrado(m_C);
  cout<<m_C<<" "<<m_D<<endl;
}