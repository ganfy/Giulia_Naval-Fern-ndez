#include <iostream>
#include <string>
using namespace std;

class Cripto {
    int clave[2]={5,4};
public:
    void cifrado(string &msje) 
    {
      string aux(clave[0]*clave[1],'_');
      string esp(clave[0]*clave[1]-msje.size(),' ');//string con los espacios que faltan para "llenar la matriz"
      msje=msje+esp;//se completa el mensaje con los espacio
      int sig=0,pos=0,key=clave[0];
      for (int pos=0; pos<msje.size(); pos++){
        aux[sig]=msje[pos];//se avanza en el string simulando la espiral, se lee el mensaje de forma lineal
        if (sig+key>sig && (aux[sig+key]!='_' || sig+key>aux.size()-1)){ //"si está yendo hacia la derecha en el string y a donde quiere saltar ya está lleno con un caracter del mensaje o se pasa del largo de la variable"
          if (key==1){//si ya llenó todo lo que quedaba de forma secuencial (una columna)
            key=-1*clave[0]; //cambia de dirección
          }
          else{
            key=1; //llenar un bloque de caracteres de forma seguida (una columna)
          }
        }
        else if (sig+key<0 || aux[sig+key]!='_'){//"si a donde quiere saltar ya está lleno con un caracter del mensaje o se pasa del largo de la variable hacia la izquierda"
          if (key==-1){//si ya llenó todo lo que quedaba de forma secuencial (una columna)
            key=clave[0];//cambia de dirección
          }
          else{
            key=-1;//llenar un bloque de caracteres de forma seguida (una columna)
          }
        }
        sig=sig+key; //se avanza el índice que se leerá
      }
      msje=aux;//se sobrescribe el mensaje
    }
    void descifrado(string &msje) 
    {
      string aux(clave[0]*clave[1],'_');
      int sig=0,pos=0,key=clave[0];
      for (int pos=0; pos<msje.size(); pos++){
        aux[pos]=msje[sig]; //ahora se salta al leer el mensaje
        msje[sig]='_';//se reemplaza lo leído con un _ para no volver a leerlo
        if (sig+key>sig && (msje[sig+key]=='_' || sig+key>aux.size()-1)){
          if (key==1){
            key=-1*clave[0];
          }
          else{
            key=1;
          }
        }
        else if (sig+key<0 || msje[sig+key]=='_'){
          if (key==-1){
            key=clave[0];
          }
          else{
            key=-1;
          }
        }
        sig=sig+key;
      }
      msje=aux;
    }
};
int main()
{
    Cripto Emisor;
    Cripto Receptor;
    string mensaje = "Hola como estas si";
    Emisor.cifrado(mensaje);
    cout << mensaje<<endl;
    Receptor.descifrado(mensaje);
    cout << mensaje<<endl;
}