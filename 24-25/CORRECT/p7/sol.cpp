// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
vector<int> resolver(vector<int> const &v, int ini)
{
  vector<int> sol;
  int max = v[0];

  for (int i = 1; i < v.size(); ++i)
  {
    if (v[i] > max)
    {
      sol.push_back(i + ini);
      max = v[i];
    }
  }

  return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
  // leer los datos de la entrada
  int ini, fin;
  cin >> ini >> fin;

  vector<int> v(fin - ini + 1);

  for (int &elem : v)
    cin >> elem;

  vector<int> sol = resolver(v, ini);
  // escribir sol

  // siempre se tiene el primer año
  if (sol.size() > 0)
    cout << sol[0];
  for (int i = 1; i < sol.size(); ++i)
    cout << ' ' << sol[i];
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
  // system("PAUSE");
#endif

  return 0;
}