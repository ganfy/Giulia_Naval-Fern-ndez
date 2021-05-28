#include<time.h>
#include <math.h>
#include <vector>
#include <string>
#include <sstream>
#include <NTL/ZZ.h>
#include <fstream>
using namespace std;
using namespace NTL;
ZZ divi(ZZ a, ZZ n){//función módulo con restricción: n es positivo
  ZZ r=a-((a/n)*n);
  if (r<0){
  return r+n;
 }
   return r;
}

int divi(int a, int n){
  int r=a-((a/n)*n);
  if (r<0){
  return r+n;
 }
   return r;
}
vector<ZZ> Euclides_ext(ZZ a, ZZ b){//Euclides extendido
  ZZ x0=conv<ZZ>(1),y0=conv<ZZ>(0),x=conv<ZZ>(0),y=conv<ZZ>(1);
  while(b>0){
  ZZ aux=x;
  ZZ q=a/b;
  ZZ r=divi(a,b);
  x=x0-q*x;
  x0=aux;
  aux=y;
  y=y0-q*y;
  y0=aux;
  a=b;
  b=r;
  }
  ZZ result[]={a,x0,y0};
  vector<ZZ>p(result,result+3);
  return p;
}
ZZ Euclides(ZZ a, ZZ b){//mcd
  while(b>0){
  ZZ r=divi(a,b);
  a=b;
  b=r;
  }
  return a;
}
ZZ inversa(ZZ a, ZZ b){//función inversa (pregunta si el mcd es 1)
  vector<ZZ> dxy = Euclides_ext(a,b);
  ZZ mcd=dxy.at(0);
  ZZ inv=dxy.at(1);
  if(mcd==1){
  if (inv<0){
    return(divi(inv,b));
  }
  return inv;
  }
  ZZ r;
  r=0;
  return r;
}
ZZ inversa_1(ZZ a, ZZ b){//función inversa (asumiendo que el mcd es 1)
  ZZ inv=Euclides_ext(a,b).at(1);
  if (inv<0){
    return(divi(inv,b));
  }
  return inv;
}
ZZ Euler(int seed){
  srand (seed);
  ZZ n=divi(conv<ZZ>(rand()),conv<ZZ>(40));
  return n*n+n+41;
}
ZZ ExpMod(ZZ a, ZZ n, ZZ m){
  ZZ res_mod;
  if (divi(n,conv<ZZ>(2))==1){
  res_mod=a;}
  else{
  res_mod=1;}
  ZZ mod=a;
  n/=2;
  while(n>0){
    mod=divi(mod*mod,m);
    if (divi(n,conv<ZZ>(2))==1){
      res_mod=divi(res_mod*mod,m);
    }
    n/=2;
  }
  return res_mod;
}

string Num2Str(ZZ a){
    ostringstream str;
    str<<a;
    return str.str();
}
string Num2Str(long a){
    ostringstream str;
    str<<a;
    return str.str();
}

int Str2Num(string a){
    istringstream num(a);
    int n;
    num>>n;
    return n;
}

string Completar0s(ZZ n, int digs){
    string num = Num2Str(n);
    int n_ceros = digs-num.size();
    string ceros(n_ceros,'0');
    num = ceros+num;
    return num;
}
string Completar0s(int n, int digs){
    string num = Num2Str(n);
    int n_ceros = digs-num.size();
    string ceros(n_ceros,'0');
    num = ceros+num;
    return num;
}

bool MillerRabin(ZZ d, ZZ n)
{
    ZZ a = conv<ZZ>(2 + divi(conv<ZZ>(rand()),conv<ZZ>(n-4)));

    ZZ x = ExpMod(a, d, n);

    if (x == 1  || x == n-1)
       return true;

    while (d != n-1)
    {
        x = divi((x*x),n);
        d *= 2;

        if (x == 1)      return false;
        if (x == n-1)    return true;
    }

    return false;
}

ZZ GenPrimo(ZZ min, ZZ max){
    srand (time(NULL));
    ZZ p;
    bool es_primo=false;
    while(!es_primo){
    p=divi(conv<ZZ>(rand()),max-min+1)+min;
    ZZ d = p-1;
    while (divi(d,conv<ZZ>(2)) == 0)
        d /= 2;
    bool primo;
    for (int i=0; i<3;i++){
        primo=MillerRabin(d,p);
    }
    es_primo=primo;
    if (es_primo)
        return p;
    }
}

int ReadFile() {
	fstream datos;
	datos.open("datos", ios::out);
	if (!datos) {
		cout << "File not created!";
	}
	else {
		cout << "File created successfully!";
		datos.close();
	}
	return 0;
}

