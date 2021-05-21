#include<time.h>
#include <math.h>
using namespace std;
int divi(int long a, int  n){//función módulo con restricción: n es positivo
  int r=a-((a/n)*n);
  if (r<0){
  return r+n;
 }
   return r;
}
int *Euclides_ext(int a, int b){//Euclides extendido
  int x0=1,y0=0,x=0,y=1;
  while(b>0){
  int aux=x;
  int q=a/b;
  int r=a%b;
  x=x0-q*x;
  x0=aux;
  aux=y;
  y=y0-q*y;
  y0=aux;
  a=b;
  b=r;
  }
  int result[]={a,x0,y0};
  int *p=result;
  return p;//devuelve un puntero a un array con el mcd, x, y
}
int Euclides(int a, int b){//mcd
  while(b>0){
  int r=a%b;
  a=b;
  b=r;
  }
  return a;
}
int inversa(int a, int b){//función inversa (pregunta si el mcd es 1)
  int mcd=Euclides(a,b);
  int inv=*(Euclides_ext(a,b)+1);
  if(mcd==1){
  if (inv<0){
    return(divi(inv,b));
  }
  return inv;
  }
  return -1;
}
int inversa_1(int a, int b){//función inversa (asumiendo que el mcd es 1)
  int mcd=*Euclides_ext(a,b);
  int inv=*(Euclides_ext(a,b)+1);
  if (inv<0){
    return(divi(inv,b));
  }
  return inv;
}
int Euler(int seed){
  srand (seed);
  int n=rand()%40;
  return n*n+n+41;
}
int long ExpMod(int a, int n, int m){
  int long res_mod;
  if (n%2==1){
  res_mod=a;}
  else{
  res_mod=1;}
  int long mod=a;
  n/=2;
  while(n>0){
    mod=divi(mod*mod,m);
    if (n%2==1){
      res_mod=divi(res_mod*mod,m);
    }
    n/=2;
  }
  return res_mod;
}
