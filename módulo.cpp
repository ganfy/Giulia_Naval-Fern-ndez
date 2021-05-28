#include <iostream>
using namespace std;

int divi(int long a, int  n){//función módulo con restricción: n es positivo
  int r=a-((a/n)*n);
  if (r<0){
  return r+n;
 }
   return r;
}
int main() {
 cout <<divi(-255,11);
}
