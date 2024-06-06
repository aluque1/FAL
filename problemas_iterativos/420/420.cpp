#include <iostream>

using namespace std;

// Ejercicio 420 El secreto de la bolsa
// Resuelto en la funcion resuelve()


void resuelve(){
  int suma_clave, sum = 0, cont_appear = 0, i_ini;

  cin >> suma_clave;

  string cotizacion;
  cin >> cotizacion;
  
  for(int i = cotizacion.size() - 1; i >= 0; --i){
    i_ini = i;
    sum += cotizacion[i] - '0';
    while(sum > suma_clave){
      sum -= cotizacion[i] - '0';
      --i;
    }
    if(sum == suma_clave) ++cont_appear;
    
    i = i_ini;
  }

  cout << cont_appear << endl;
}

int main(int argc, char const *argv[])
{
  int num_casos;
  cin >> num_casos;
  for(int i = 0; i < num_casos; ++i){
    resuelve();
  }

  return 0;
}