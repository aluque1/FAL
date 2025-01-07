// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// función que resuelve el problema
pair<int, bool> resolver(vector<int> const &v, int ini, int fin) {
  if (ini == fin)
    return {0, true};  // unico elem
  else if (ini + 1 == fin) {
    if (v[ini] % 2 == 0 && v[fin] % 2 == 0)
      return {2, true};
    else if (v[ini] % 2 == 0 || v[fin] % 2 == 0)
      return {1, true};
    else
      return {0, true};
  } else {
    int mid = (ini + fin) / 2;
    auto iz = resolver(v, ini, mid);
    auto dr = resolver(v, mid + 1, fin);
    return {iz.first + dr.first,
            abs(iz.first - dr.first) <= 2 && iz.second && dr.second};
  }
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int num_elems;
  cin >> num_elems;
  if (num_elems == 0) return false;

  vector<int> v(num_elems);
  for (int &elem : v) cin >> elem;

  resolver(v, 0, v.size() - 1).second ? cout << "SI\n" : cout << "NO\n";

  return true;
}

int main() {
// Para la entrada por fichero.
// Comentar para acepta el reto
#ifndef DOMJUDGE
  std::ifstream in("datos.txt");
  auto cinbuf = std::cin.rdbuf(
      in.rdbuf());  // save old buf and redirect std::cin to casos.txt
#endif

  while (resuelveCaso());

  // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE  // para dejar todo como estaba al principio
  std::cin.rdbuf(cinbuf);
  system("PAUSE");
#endif

  return 0;
}
