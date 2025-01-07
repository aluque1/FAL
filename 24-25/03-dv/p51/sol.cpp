// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(vector<int> &v, int ini, int fin) {
  if (ini == fin) return 0;
  if (ini + 1 == fin) {
    return 0;
  } else {
    int mid = (ini + fin - 1) / 2;
    int iz = resolver(v, ini, mid + 1);
    int dr = resolver(v, mid + 1, fin);
    int aux = 0;
    int i = ini;
    int j = mid + 1;
    while (i < mid && j < fin) {
      if (v[i] > v[j]) {
        aux += (mid - i + 1);
        ++j;
      } else
        ++i;
    }
    sort(v.begin() + ini, v.begin() + fin);
    return aux + iz + dr;
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int num_naves;
  cin >> num_naves;
  if (!std::cin) return false;

  vector<int> v(num_naves);
  for (int &elem : v) cin >> elem;

  cout << resolver(v, 0, v.size()) << '\n';

  // escribir sol

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