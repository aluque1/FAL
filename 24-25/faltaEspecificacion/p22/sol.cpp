// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
// PRE : { 0 <= n <= longitud(v) ^ estrictamenteCreciente(v) ^ k >= 0 }
int resolver(vector<int> const &v, int k)
{
  int i = 0, j = 0, emparejados = 0;
  // I : { 0 <= i < j < v.size()}
  while (j < v.size())
  {
    if (v[j] - v[i] == k)
    {
      ++emparejados;
      ++i;
      ++j;
    }
    else if (v[j] - v[i] < k)
      ++j;
    else
      ++i;
  }

  return emparejados;
}
// POST : { #e : 0 <= i <= j < n : v[i] - v[j] == k}
// El coste de la funcion es O(n) ya que se recorre el array una sola vez con 2 punteros que van incrementando

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
  // leer los datos de la entrada
  int numElems, k;
  cin >> numElems;
  if (numElems == -1)
    return false;

  cin >> k;

  vector<int> v(numElems);

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
// system("PAUSE");
#endif

  return 0;
}
