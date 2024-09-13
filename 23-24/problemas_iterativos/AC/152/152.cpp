#include <iostream>
#include <algorithm> // Se usa para la funcion sort

using namespace std;

// Ejercicio 152 Va de modas...
// Resuelto en la funcion resuelve_caso()
// Al no estar especificado el rango de los numeros no se puede hacer un vector de frecuencias

int v[25000];

/* 
    { Pre : 0 < n <= longitud(v) <= 25000 } 
    { Post : ret = i : i = moda(v[]) } 
    { Coste : O(n) ya que se hace un recorrido de todo el array. La complejidad de sort no es limitante
      ya que es O(n logn) }
*/
bool resuelve_caso(){

  int n, moda, cont_actual = 1, cont_max = 1;

  cin >> n;
  if(n == 0)
    return false;
  else if (n == 1)
    cin >> moda;
  else {
    for(int i = 0; i < n; ++i)
      cin >> v[i];

    sort(v, v + n); // ordenamos el vector para que los numeros iguales esten juntos

    for(int i = 0; i < n; ++i){
      if(v[i] == v[i+1])
        ++cont_actual;
      else {
        if(cont_actual > cont_max){
          cont_max = cont_actual;
          moda = v[i];
        }
        cont_actual = 1;
      } 
    }
  }

  cout << moda << "\n";
  return true;
}

int main()
{
  while (resuelve_caso()){}
}