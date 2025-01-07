// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// función que resuelve el problema
void resolver(vector<pair<char, int>> &v, int &ini_verde, int &fin_verde) {
  ini_verde = 0;
  fin_verde = v.size() - 1;
  int k = 0;  // K se usa para recorrer los elementos "verdes"
  while (k <= fin_verde) {
    if (v[k].first == 'v')
      ++k;
    else if (v[k].first == 'a') {
      swap(v[ini_verde], v[k]);
      ++k;
      ++ini_verde;
    } else {
      swap(v[fin_verde], v[k]);
      --fin_verde;
    }
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int num_cintas;
  cin >> num_cintas;
  if (!std::cin) return false;

  vector<pair<char, int>> v(num_cintas);
  for (pair<char, int> &cinta : v) cin >> cinta.first >> cinta.second;

  int ini_verde, fin_verde;

  resolver(v, ini_verde, fin_verde);

  // Ordenamos los distintos segmentos del vector
  sort(v.begin(), v.begin() + ini_verde);
  // Debe ser 1 + q para evitar v.begin() - 1 cuando q vale 0
  sort(v.begin() + ini_verde, v.begin() + 1 + fin_verde);
  sort(v.begin() + 1 + fin_verde, v.end());

  // escribir sol
  cout << "Azules: ";
  for (int i = 0; i < ini_verde; ++i) cout << v[i].second << ' ';
  cout << '\n';
  cout << "Verdes: ";
  for (int i = ini_verde; i <= fin_verde; ++i) cout << v[i].second << ' ';
  cout << '\n';
  cout << "Rojas: ";
  for (int i = fin_verde + 1; i < v.size(); ++i) cout << v[i].second << ' ';
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