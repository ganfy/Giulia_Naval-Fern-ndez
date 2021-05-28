#include <iostream>
#include <string>
#include <sstream>
#include "algebra.h"
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;

string alfabeto="abcdefghijklmnopqrstuvwxz ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
class RSA {
  ZZ d,p,q,oN;
  public:
  ZZ e,n;
  RSA(int bits){
    Generar_claves(bits);
    cout<<p<<" "<<q<<" "<<n<<" "<<oN<<" "<<e<<" "<<d<<endl;
  }
  RSA(ZZ e, ZZ n){
    this->e=e;
    this->n=n;
  }
  string cifrado(string m)
    {   ostringstream c;
        int num_dig=Num2Str(alfabeto.size()-1).size();
        int k=Num2Str(n).size()-1;
        while(divi((m.size()*num_dig),k)!=0)
            m+=' ';
        for (int i=0; i<m.size(); i++){
        int l=alfabeto.find(m[i]);
        c<<Completar0s(l,num_dig);
        }
        string C=c.str();
        string Cifrado="";
        for (int i=0; i<C.size(); i=i+k){
            string bloque=C.substr(i,k);
            ZZ cypher=ExpMod(conv<ZZ>(Str2Num(bloque)),e,n);
            Cifrado+= Completar0s(cypher,k+1);
        }
        return Cifrado;
    }
  string descifrado(string m)
    {   string Descifrado="",D="";
        int num_dig=Num2Str(alfabeto.size()-1).size();
        int k=Num2Str(n).size();
        for (int i=0; i<m.size(); i=i+k){
            string bloque=m.substr(i,k);
            ZZ decode=ExpMod(conv<ZZ>(Str2Num(bloque)),d,n);
            D+= Completar0s(decode,k-1);
        }
        for (int i=0; i<D.size(); i=i+num_dig){
            string bloque=D.substr(i,num_dig);
            int pos=Str2Num(bloque);
            char a=alfabeto[pos];
            Descifrado+=a;
        }
        return Descifrado;
    }
  void Generar_claves(long bits){
      ZZ min,max;
      min=pow(2,bits-1);max=pow(2,bits)-1;
    p=GenPrimo(min,max);
    q=GenPrimo(min,max);
    while (p==q){
      q=GenPrimo(min,max);
    }
    n=p*q;
    oN=(p-1)*(q-1);
    e=divi(conv<ZZ>(rand()),oN);
    cout<<p+conv<ZZ>(rand())<<endl;
    ZZ ee=Euclides(e,oN);
    while(ee!=1){
      e=divi(conv<ZZ>(rand()),oN);
      ee=Euclides(e,oN);
    }
    d=inversa_1(e,oN);
  }
};

int main()
{
  RSA Receptor(16);
  RSA Emisor(Receptor.e,Receptor.n);
  string m="COMEHERE";
  string m_C=Emisor.cifrado(m);
  string m_D=Receptor.descifrado(m_C);
  cout<<m_C<<" "<<m_D<<endl;
  cout<<ExpMod(conv<ZZ>(160276),conv<ZZ>(351381),conv<ZZ>(942841));
}
