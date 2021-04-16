/*#include <iostream>
#include <cstring>
using namespace std;

int main(){
  string cad;
  int l;
  cout<<"ingrese un texto: "; getline(cin,cad);//a
  cout<<"ingrese el largo de cada bloque: "; cin>>l;//b
  int n_bloques=cad.size()/l;
  if (cad.size()%l!=0) n_bloques++;
  string esp(n_bloques*l-cad.size(),'X'); //d
  cad.append(esp);//d
  for (int i=4; i<cad.size(); i+=5){//e
    cad.insert(i,"*");
  }
  char *cstr = new char [cad.size()+1];
  strcpy (cstr, cad.c_str());
  string arr[n_bloques];//f
  int ind=0;
  char *ptr = strtok (cstr,"*");
  while (ptr!=0)
  {
    cout << ptr << '\n';//c
    arr[ind]=ptr;//f
    ind++;
    ptr = strtok(NULL,"*");
  }
  delete[] cstr;
  for (int i=0; i<n_bloques; i++){//g
    cout<<arr[i];
  }
}*/