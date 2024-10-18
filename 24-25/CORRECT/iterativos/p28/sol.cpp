// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// función que resuelve el problema
vector<int> resolver(vector<int> const &v1, vector<int> const &v2)
{
  int i = 0, j = 0;
  vector<int> sol;
  while (i < v1.size() && j < v2.size())
  {
    if (v1[i] < v2[j])
      ++i;
    else if (v1[i] > v2[j])
      ++j;
    else
    {
      sol.push_back(v1[i]);
      ++i;
      ++j;
    }
  }
  return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
  // leer los datos de la entrada
  int elem;
  vector<int> v1;
  while ((cin >> elem) && elem != 0)
    v1.push_back(elem);

  vector<int> v2;
  while ((cin >> elem) && elem != 0)
    v2.push_back(elem);

  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());

  vector<int> sol = resolver(v1, v2);
  // escribir sol
  for (int i = 0; i < sol.size(); ++i)
    cout << sol[i] << ' ';
  cout << '\n';
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