// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(vector<bool> const &v, int k) {
  int long_min = v.size() + 1;
  int long_act = 1;
  int num_trues = 0;
  int i = 0;
  int j = 0;
  bool true_ant = false;

  // Buscamos el primer intervalo con el numero de trues
  while (j < v.size() && long_min == v.size() + 1) {
    if (num_trues > 0) ++long_act;
    if (!true_ant) i = j;
    if (v[j]) {
      true_ant = true;
      ++num_trues;
      if (num_trues == k) long_min = min(long_min, long_act);
    }
    ++j;
  }

  ++i;
  // Buscamos el tramo mas corto con k trues
  while (j < v.size() && i < v.size()) {
    if (v[j] && v[i]) {
      ++i;
      ++j;
      long_min = min(long_act, long_min);
    } else if (!v[i]) {
      --long_act;
      ++i;
    } else if (!v[j]) {
      ++long_act;
      ++j;
    }
  }
  return long_min;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int num_elems, num_true, elem;
  cin >> num_elems;
  if (num_elems == -1) return false;

  vector<bool> v(num_elems);
  for (int i = 0; i < v.size(); ++i) {
    cin >> elem;
    elem == 0 ? v[i] = false : v[i] = true;
  }

  cin >> num_true;

  int sol = resolver(v, num_true);
  // escribir sol
  cout << sol << '\n';
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
