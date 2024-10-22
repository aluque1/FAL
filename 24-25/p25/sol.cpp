// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(vector<int> const &v, int const k)
{
  /*  para la longitud k; calcular numero de intervalos de longitud k tal que la
  cantidad de valores positivos en la mitad izqe es mayor o igual que la caltidad de
  valores positivos en el lado derecho */

  /* Tener 2 whiles, uno que compruebe cuantos valores positivos en el intervalo iz
  y otro que compruebe cuantos valores positivos en el lado der */
  int numIntervalos = 0;
  while ()
  {
  }

  while (/* condition */)
  {
    /* code */
  }

  return numIntervalos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
  // leer los datos de la entrada
  int nElems, k;
  cin >> nElems;
  if (nElems == 0)
    return false;

  cin >> k;

  vector<int> v(nElems);
  for (int &elem : v)
    cin >> elem;

  int sol = resolver(v, k);

  // escribir sol
  cout << sol << '\n';
  return true;
}

int main()
{
// Para la entrada por fichero.
// Comentar para acepta el reto
#ifndef DOMJUDGE
  std::ifstream in("datos.txt");
  auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std::cin to casos.txt
#endif

  while (resuelveCaso())
    ;

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
  std::cin.rdbuf(cinbuf);
  system("PAUSE");
#endif

  return 0;
}
