// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

// función que resuelve el problema
void resolver(vector<int> &v)
{
  sort(v.begin(), v.end());
  int posActual = 1;
  int prevElem = v[0];
  for (int i = 0; i < v.size(); ++i)
  {
    if (v[i] != prevElem)
    {
      v[posActual] = v[i];
      ++posActual;
      prevElem = v[i];
    }
  }
  v.resize(posActual);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
  // leer los datos de la entrada
  int nElems;
  cin >> nElems;

  if (!std::cin)
    return false;

  vector<int> v(nElems);

  for (int &elem : v)
    cin >> elem;

  resolver(v);

  for (int i = 0; i < v.size(); ++i)
    cout << v[i] << " ";

  cout << '\n';

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