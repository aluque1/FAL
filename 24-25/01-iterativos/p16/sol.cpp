// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

/* PRE : { 0 <= n < v.size() } */
bool porLosPelos(vector<int> const &v)
{
  bool pelos = true;
  /* INV : { i <= i < j < v.size() ^ P.t. i, j : 0 <= i < j < v.size() : (v[i] <= v[j] ^ v[j] - v[i] <= 1) } */
  for (int i = 0; i < (v.size() - 1); ++i)
  {
    if (v[i] > v[i + 1] || (v[i + 1] - v[i]) > 1)
      pelos = false;
  }
  return pelos;
}
/* POST : { P.t. i, j : 0 <= i < j < v.size() : (v[i] <= v[j] ^ v[j] - v[i] <= 1) } */

/* PRE : { 0 <= n < v.size() ^ d > 0 } */
bool dDivertido(vector<int> v, int const d)
{
  // en teoria ya esta ordenado aunque sea "por los pelos"
  int max = 1;
  int prev = v[0];
  bool diver = true;
  for (int i = 1; i < v.size(); ++i)
  {
    if (prev == v[i])
      ++max;
    else
      max = 1;
    if (max > d)
      return false;
    prev = v[i];
  }
  return diver;
}

/* POST : {} */

// función que resuelve el problema
pair<bool, bool> resolver(vector<int> const &v, int const d)
{
  return {porLosPelos(v), dDivertido(v, d)};
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
  // leer los datos de la entrada
  int d, numElems;
  cin >> d >> numElems;

  vector<int> v(numElems);
  for (int &elem : v)
    cin >> elem;

  pair<bool, bool> sol = resolver(v, d);
  // escribir sol
  sol.first && sol.second ? cout << "SI\n" : cout << "NO\n";
}

int main()
{
// Para la entrada por fichero.
// Comentar para acepta el reto
#ifndef DOMJUDGE
  std::ifstream in("datos.txt");
  auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std::cin to casos.txt
#endif

  int numCasos;
  std::cin >> numCasos;
  for (int i = 0; i < numCasos; ++i)
    resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
  std::cin.rdbuf(cinbuf);
  system("PAUSE");
#endif

  return 0;
}