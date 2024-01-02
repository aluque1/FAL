#include <iostream>
#include <algorithm>

using namespace std;

// Ejercicio 152 Va de modas...
// Resuelto en la funcion modas()
// Al no estar especificado el rango de los numeros no se puede hacer un vector de frecuencias

int v[25000];

/* Pre : 0 < n <= longitud(v)*/
/*Complejidad : O(n) ya que se recorre todo el array
  y ya que la complejidad de sort() es O(n logn)*/
void resuelve_caso(int n){
  int contActual = 0;
  int contMax = 0;
  int moda = 0;

  sort(v, v+n);
  if(n == 1){
    cout << v[0] << "\n";
    return;
  }

  for(int i = 0; i < n; ++i){
    if(v[i] == v[i+1])
      ++contActual;
    else{
      if(contActual > contMax){
        contMax = contActual;
        moda = v[i]; 
      }
      contActual = 1;
    }
  }
  cout << moda << "\n";
}
/* Post : ret = i : i = moda(v[])*/

int main()
{
  int n;
  while ((cin >> n) && n)
  {
    for (int i = 0; i < n; ++i)
    {
      cin >> v[i];
    }
    resuelve_caso(n);
  }
  
}