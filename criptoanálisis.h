#include <stdlib.h>  
using namespace std; 
const string alfabeto={"abcdefghijklmnopqrstuvwxyz"};

int divi(int a, int n){//función módulo positivo
  int r=a-((a/n)*n);
 if (r<0){
   if (n<0){
    return r-n;}
  return r+n;
 }
  return r;
}

char más_frecuente(string msje){
  int may_frec=1;// cantidad de veces en que aparece el carácter más frecuente
  char más_frec;//carácter más frecuente
  for (int i=0; i<msje.size(); i++){
    int cont=0;//apariciones de la letra
    int buscar = msje.find_first_of(msje[i],i+1);//busca si la letra se repite más adelante en el mensaje
      while (buscar!=-1 && alfabeto.find(msje[i])!=-1){//mientras encuentre una repetición y el caracter esté en el alfabeto
        cont++;//incrementa el contador
        msje[buscar]='*';//reemplaza las repeticiones para no volver a considerarlas
        buscar=msje.find_first_of(msje[i],buscar+1);//busca otra repetición a partir de la sig. posición
      }
      if (cont>may_frec){//si aparece más veces que la mayor frecuencia actual...
        may_frec=cont;//...ahora este número es la mayor frecuencia
        más_frec=msje[i];//el caracter más frecuente es el de la posición actual
      }
  }
  return más_frec;
}

int Posible_clave(string msje, char pos_descif){
  char más_frec=más_frecuente(msje);
  int pos_clave=alfabeto.find(más_frec)-alfabeto.find(pos_descif);//diferencia entre la posición de la letra cifrada y su posible desciframiento 
  if (pos_clave<0){
    return pos_clave+26;
  }
  return pos_clave; //valor absoluto de esta diferencia por si es negativa
}

void Criptoanálisis(string msje){
  string letras_frec="eaosrnidlctumpbgvyqhfzjxkw";//alfabeto ordenado según la frecuencia de cada letra en el idioma español de forma descendente
  string tiene_sentido;
  string msje_descifrado=msje;
  int i=0, clave;
  while (tiene_sentido!="si"){//condición para dejar de probar claves
  clave=Posible_clave(msje, letras_frec[i++]);
  for (int i=0; i<msje.size();i++){
    int pos=alfabeto.find(msje[i]);
    msje_descifrado[i]=alfabeto[divi(pos-clave,26)];
      }
    cout<<msje_descifrado<<"\tTiene sentido? ";
    cin>>tiene_sentido;
  }
  cout<<"\nClave:"<<clave;
}
