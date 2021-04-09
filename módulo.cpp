#include <iostream>
using namespace std;
int divi(int a, int n){
 if ((a-((a/n))*n)<0){
   if (a<0 && n<0){
     return (a-((a/n)+1)*n);
   }
   return (a-((a/n)-1)*n);
 }
 return (a-((a/n))*n);
}
int main() {
 cout <<divi(-255,-11);
}
