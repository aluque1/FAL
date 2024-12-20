// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
// PRE : { 0 < n <= longitud(v) }
int resolver(vector<int> const &v)
{
  int parejas = 0, i = 0, numOdd = 0;
  // INV : { 0 <= i < v.size ^ #e : 0 <= i < j < n : v[i] % 2 == 1 ^ v[j] % 2 == 0 }
  while(i < v.size()){
    if(v[i] % 2 == 1)
      ++numOdd;
    if(v[i] % 2 == 0)
      parejas += numOdd;
    ++i;
  }

  return parejas;
}
// POST : {#e : 0 <= i < j < n : v[i] % 2 == 1 ^ v[j] % 2 == 0}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
  // leer los datos de la entrada
  int numElems;
  cin >> numElems;
  vector<int> v(numElems);
  for (int &elem : v)
    cin >> elem;

  int sol = resolver(v);
  // escribir sol
  cout << sol << '\n';
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