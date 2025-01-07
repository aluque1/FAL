// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(vector<pair<string, int>> &v, int const altura_bajos) {
  int i = 0;
  int j = v.size() - 1;
  while (i <= j) {
    // El elemento del indice iz es bajo => bien colocado
    if (v[i].second <= altura_bajos) ++i;
    // El elemento del indice dr es alto => bien colocado
    else if (v[j].second > altura_bajos)
      --j;
    // Ambos elementos estan mal entonces los intercambiamos
    else {
      swap(v[i], v[j]);
      ++i;
      --j;
    }
  }
  // Devolvemos el punto en el que esta el ultimo bajo
  return i;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int num_viajeros, altura_bajos;
  cin >> num_viajeros;
  if (!std::cin) return false;
  cin >> altura_bajos;

  vector<pair<string, int>> v(num_viajeros);
  for (auto &viajero : v) cin >> viajero.first >> viajero.second;

  int particion = resolver(v, altura_bajos);

  sort(v.begin(), v.begin() + particion);
  sort(v.begin() + particion, v.end());

  // escribir sol
  cout << "Bajos: ";
  if(particion > 0) cout << v[0].first << ' ';
  for (int i = 1; i < particion; ++i) cout << v[i].first << ' ';
  cout << '\n';
  cout << "Altos: ";
  if(particion < v.size()) cout << v[particion].first << ' ';
  for (int i = particion + 1; i < v.size(); ++i) cout << v[i].first << ' ';
  cout << '\n';

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