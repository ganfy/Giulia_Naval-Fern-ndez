/*#include <iostream>
#include <cstring>
using namespace std;

int main(){
  string cad;
  char *tknPtr;
  cout<<"ingrese un texto: "; getline(cin,cad);
  int p=cad.find_first_of(".,;:");
  while (p!=-1){
    cad[p]=' ';
    p=cad.find_first_of(".,;:",p+1);
  }
  char *cstr = new char [cad.size()+1];
  strcpy (cstr, cad.c_str());
  char *ptr = strtok (cstr," ");
  while (ptr!=0)
  {
    cout << ptr << '\n';
    ptr = strtok(NULL," ");
  }

  delete[] cstr;
}*/