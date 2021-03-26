#include <iostream>
#include <string>
using namespace std;

char alfabeto[27];
class Cripto {
    int clave[2]={6,9};
public:
    void cifrado(string &msje) 
    {
      string esp(((clave[0])*(clave[1])-msje.size()),' ');
      string aux=msje+esp;
      msje="";
      for (int i = 0; i < clave[1]; i++) {
        for (int j = 0; j < clave[0]; j++) {
          msje = msje + aux[i + j*(clave[1])];
          }
      }
    };
    void descifrado(string &msje) 
    {
      string aux=msje;
      msje = "";
        for (int i = 0; i < clave[0]; i++) {
            for (int j = 0; j < clave[1]; j++) {
                msje = msje + aux[i + j*(clave[0])];
            }
        }
    };
};
int main()
{
    Cripto Emisor;
    Cripto Receptor;
    string mensaje = "Me diste ganas de cambiarme de carrera";
    Emisor.cifrado(mensaje);
    cout << mensaje<<endl;
    Receptor.descifrado(mensaje);
    cout << mensaje<<endl;
}
