#include <iostream>

using namespace std;

// Ejercicio 354 ¡Los niños primero!
// Resuelto en la funcion resuelve()

int v[200000];

bool resuelve(){
  int num_espectadores, num_kids, altura_max_kids, altura_max_global = 0;
  
  cin >> num_espectadores;

  if(num_espectadores == 0) return false;

  cin >> v[0];
  altura_max_global = v[0];
  altura_max_kids = v[0];
  num_kids = 1;

  for(int i = 1; i < num_espectadores; ++i){
    cin >> v[i];
    if(v[i] > altura_max_global)
      altura_max_global = v[i];
    if(v[i] <= altura_max_kids){ // si hay altura menor que el niño mas alto
      num_kids = i + 1; // todos los niños hasta el actual son niños
      altura_max_kids = altura_max_global; // actualizamos la altura maxima de los niños con la mas alto hasta el momento
    }
  }

  cout << num_kids << endl;
  return true;
}

int main(int argc, char const *argv[])
{
  while(resuelve()){}

  return 0;
}