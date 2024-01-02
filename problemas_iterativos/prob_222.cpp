#include <iostream>

using namespace std;

// Ejercicio 222 Serie de potencias
// Resuelto en la funcion serie_potencias(in x, int a)

/* Post : {ret = sumaAcu : P.t. i : 0 <= i <= a : x^0 + x^1 + ... + x^i} */

#include <iostream>
using namespace std;

int serie_potencias(int x, int a) // TLE
{
  int sumaAcu = 0;
  int potenciaAcu = 1;
  for (int i = 0; i <= a; ++i)
  {
    sumaAcu += potenciaAcu;
    potenciaAcu *= x;
  }
  return sumaAcu % 1000007;
}

bool casoDePrueba()
{
  // leer el inicio del caso de prueba (cin)
  if (!cin)
    return false;
  else
  {
    // leer los datos del caso de prueba
    int x, a;
    cin >> x >> a;
    int sol = serie_potencias(x, a);
    cout << sol << "\n";
    return true;
  }
}

int main()
{

  while (casoDePrueba())
  {
  }

  return 0;
}