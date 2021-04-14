/*#include <iostream>
using namespace std;

int main(){
  string palabras[]={"Mississippi", "California", "Tennessee", "Washington", "Oklahoma", "Nebraska"};
  string ahorcado[]={"\t 0","\n\t/","|","\\","\n\t |","\n\t/"," \\"};
  string intentos;
  bool juego=true;
  while(juego){
    int errores=0;
    string palabra=palabras[rand()%6];
    string pal_escondida(palabra.size(),'X');
    while (errores<7){
      //system("cls");
      char l;
      cout<<pal_escondida<<endl;
      cout<<"Ingrese una letra: "; cin>>l;
      intentos += l;
      int buscar = palabra.find_first_of(l);
      if (buscar!=-1){
        while (buscar!=-1){
        pal_escondida[buscar]=l;
        buscar=palabra.find_first_of(l,buscar+1);
        }
      }
      else {
        errores++;
      }
    for (int i=0; i<errores; i++){
      cout<<ahorcado[i];
    }
    cout<<endl;
    if (pal_escondida==palabra || errores==7){
      if (pal_escondida==palabra){
        cout<<"Felicidades!!! Adivino mi palabra. Desea jugar otra vez?";
      }
      if (errores==7){
      cout<<"Lo sentimos. Perdió. Desea jugar otra vez?";
      }
      string rpta;
      while (rpta!="si" && rpta!="no"){
      cout<<"Responda si/no: "; cin>>rpta;
      }
      if (rpta=="no"){
      juego=false;}
      break;
      }
    }
  }
  cout<<"fin";
}*/