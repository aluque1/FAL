#include <iostream>

using namespace std;

// Ejercicio 222 Serie de potencias
// Resuelto en la funcion serie_potencias()

/* Pre : {x >= 0 AND a >= 0} */
/* Complejidad O(n) donde es lineal en respecto a int a */

bool caso_de_prueba()
{
  int i = 0;
  int sumaAcu = 0;
  int potenciaAcu = 1;
  if (!cin)
    return false;
  else
  {
    int x, a;
    cin >> x >> a;
    while (i <= a)
    {
      sumaAcu += potenciaAcu;
      potenciaAcu *= x;
      i++;
    }
    cout << sumaAcu % 1000007 << "\n";
    return true;
  }
}
/* Post : {ret = sumaAcu : P.t. i : 0 <= i <= a : x^0 + x^1 + ... + x^i} */

int main()
{
  while (caso_de_prueba())
  {
  }
  return 0;
}