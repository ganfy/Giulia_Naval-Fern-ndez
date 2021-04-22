#include <iostream>
#include <string>
#include "criptoanálisis.h"
using namespace std;

class Cripto {
    int clave=12;
public:
    void cifrado(string &msje) 
    {
      for (int i=0; i<msje.size();i++){
        int pos=alfabeto.find(msje[i]);
        msje[i]=alfabeto[divi(pos+clave,26)];//usa la función propia de módulo para encontrar la letra dentro del alfabeto para cifrar
      }
    }
    void descifrado(string &msje) 
    {
      for (int i=0; i<msje.size();i++){
        int pos=alfabeto.find(msje[i]);
        msje[i]=alfabeto[divi(pos-clave,26)];
      }
    }
};
int main()
{
    Cripto Emisor;
    Cripto Receptor;
    string mensaje = "martatieneunmarcapasos";
    Emisor.cifrado(mensaje);
    cout << mensaje<<endl;
    Receptor.descifrado(mensaje);
    cout << mensaje<<endl;
//rompiendo el cifrado:
    Criptoanálisis("rfwyfynjsjzsrfwhfufxtx");
}