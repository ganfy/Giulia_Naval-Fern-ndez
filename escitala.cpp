#include <iostream>
#include <string>
#include <math.h>
using namespace std;

char alfabeto[27];
int gen_key(int size){
  int key=ceil(float(size)/6)*10+6;
  return key;
}
class Cripto {
    int clave;
public:
    void cifrado(string &msje) 
    {
      clave=gen_key(msje.size());
      string esp(((clave/10)*(clave%10)-msje.size()),' ');
      string aux=msje+esp;
      msje="";
      for (int i = 0; i < clave%10; i++) {
        for (int j = 0; j < clave/10; j++) {
          msje = msje + aux[i + j*(clave%10)];
          }
      }
    };
    void descifrado(string &msje) 
    {
      clave=gen_key(msje.size());
      string aux=msje;
      msje = "";
        for (int i = 0; i < clave/10; i++) {
            for (int j = 0; j < clave%10; j++) {
                msje = msje + aux[i + j*(clave/10)];
            }
        }
    };
};
int main()
{
    Cripto Emisor;
    Cripto Receptor;
    string mensaje = "hola como estas";
    Emisor.cifrado(mensaje);
    cout << mensaje<<endl;
    Receptor.descifrado(mensaje);
    cout << mensaje<<endl;
}
