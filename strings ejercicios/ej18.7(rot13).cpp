/*#include <iostream>
#include <string>
using namespace std;

string alfabeto="abcdefghijklmnopqrstuvwxyz";
class Rot13 {
    int clave=13;
public:
    void cifrado(string &msje) 
    {
      for (int i=0; i<msje.size(); i++){
        int pos=alfabeto.find(msje[i]);
        if (pos+clave > 25){
          msje[i]=alfabeto[pos+clave-26];
        }
        else{
        msje[i]=alfabeto[pos+clave];
        }
      }
    }
    void descifrado(string &msje) 
    {
      for (int i=0; i<msje.size(); i++){
        int pos=alfabeto.find(msje[i]);
        if (pos-clave < 0){
          msje[i]=alfabeto[pos-clave+26];
        }
        else{
          msje[i]=alfabeto[pos-clave];
        }
      }
    }
};
int main()
{
    Rot13 Emisor;
    Rot13 Receptor;
    string mensaje = "paz";
    Emisor.cifrado(mensaje);
    cout << mensaje<<endl;
    Receptor.descifrado(mensaje);
    cout << mensaje<<endl;
}*/