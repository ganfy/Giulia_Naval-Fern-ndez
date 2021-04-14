#include <iostream>
#include <iomanip>
using namespace std;

void ordenamientoSeleccion( string [], const int, bool (*)( string, string ) );
bool ascendente( string a, string b ){
return a < b; 
} 
bool descendente( string a, string b ){
return a > b;
} 

int main(){
const int tamanioArreglo = 10;
int orden; 
int contador; 
string a[ tamanioArreglo ] = { "borgoña","celeste","verde","azul","ocre","indigo","blanco","anaranjado","negro","plateado" };
cout << "Escriba 1 para orden ascendente,\n"<< "Escriba 2 para orden descendente: ";cin >> orden;
cout << "\nElementos de datos en el orden original\n";
for ( contador = 0; contador < tamanioArreglo; contador++ )
cout << a[ contador ]<<" ";
if ( orden == 1 ) {
  ordenamientoSeleccion( a, tamanioArreglo, ascendente );
  cout << "\nElementos de datos en orden ascendente\n";
  } 
else{
  ordenamientoSeleccion( a, tamanioArreglo, descendente );
  cout << "\nElementos de datos en orden descendente\n";} 
for ( contador = 0; contador < tamanioArreglo; contador++ )
cout << a[contador]<<" ";
}
void ordenamientoSeleccion( string trabajo[], const int tamanio,bool (*compara)( string, string ) )
{
int menorOMayor; 
for ( int i = 0; i < tamanio - 1; i++ )
{
menorOMayor = i; 
for ( int index = i + 1; index < tamanio; index++ )
if ( !(*compara)( trabajo[ menorOMayor ], trabajo[ index ] ) )
menorOMayor = index;
trabajo[menorOMayor].swap(trabajo[ i ] );} 
} 