// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
pair<bool, int> resolver(vector<int> const &v)
{
  int i = v.size() - 1;
  int suma = 0;
  bool pastoso = false;
  while (i >= 0 && !pastoso)
  {
    if (v[i] == suma)
      pastoso = true;
    else {
      suma += v[i];
      --i;
    }
  }
  return {pastoso, i};
}

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

  pair<bool, int> sol = resolver(v);
  // escribir sol

  sol.first ? cout << "Si " << sol.second << '\n' : cout << "No\n";
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