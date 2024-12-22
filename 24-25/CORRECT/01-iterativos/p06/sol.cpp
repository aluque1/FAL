// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
long resolver(vector<int> const &v, int &numMinimos)
{
  long sumaTotal = v[0], valorMin = v[0];
  for (int i = 1; i < v.size(); ++i)
  {
    sumaTotal += v[i];

    if (v[i] == valorMin)
      ++numMinimos;
    else if (v[i] < valorMin)
    {
      numMinimos = 1;
      valorMin = v[i];
    }
  }
  return sumaTotal - (valorMin * numMinimos);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
  // leer los datos de la entrada
  int numElems, numMinimos = 1;
  cin >> numElems;

  vector<int> v(numElems);
  for (int &elem : v)
    cin >> elem;

  long sol = resolver(v, numMinimos);
  // escribir sol

  cout << sol << ' ' << numElems - numMinimos << '\n';
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
  // system("PAUSE");
#endif

  return 0;
}