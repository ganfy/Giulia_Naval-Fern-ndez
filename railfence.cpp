#include <iostream>
#include <string>
using namespace std;

class CriptoRailFence {
    int clave=2;
public:
    void cifrado(string &msje) 
    {
      string aux=msje; //se copia el mensaje
      msje=""; //se "borra" el mensaje
      for (int i = 0; i < clave; i++) { //"filas"
        int t=0;//un contador que ayudará a distinguir si sube o baja en el zigzag
        int jump=0;
        for (int j = i; j < aux.size(); j=j+jump) { //veces que se "salta" de índice en el string sin salirse de este
          msje = msje + aux[j]; //se sobrescribe el mensaje
          t++;
          if (clave-1==i || i==0){ //cuando está en el borde superior o inferior de la "matriz"
              jump=2*clave-2;
            }
          else if (t%2==0){  //cuando sube, salta los caracteres que forman el pico hacia arriba
            jump=2*i;
          }
          else{ //cuando baja, salta los caracteres que forman el pico hacia abajo
            jump=2*(clave-i)-2;
            
          }
          }
      }
    }
    void descifrado(string &msje) 
    {
      string aux(msje.size(),' '); //string de espacios para llenar con el mensaje descifrado
      int ind=0;//para avanzar en el mensaje
      for (int i = 0; i < clave; i++) {
        int t=0;
        int jump=0;
        for (int j = i; j < aux.size(); j=j+jump) {
          aux[j] = msje[ind]; //en lugar de leer "dando saltos", llenamos la variable auxiliar "saltando" de índice
          t++;ind++;
          if (clave-1==i || i==0){
              jump=2*clave-2;
            }
          else if (t%2==0){
            jump=2*i;
          }
          else{
            jump=2*(clave-i)-2;
            
          }
          }
      }
      msje=aux; //se reemplaza el mensaje cifrado con lo que se obtuvo en la variable auxiliar
    }
};
int main()
{
    CriptoRailFence Emisor;
    CriptoRailFence Receptor;
    string mensaje = "Mismo texto distinta clave ";
    Emisor.cifrado(mensaje);
    cout << mensaje<<endl;
    Receptor.descifrado(mensaje);
    cout << mensaje<<endl;
}