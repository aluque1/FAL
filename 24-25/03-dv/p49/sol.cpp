// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct t_sol {
  int minimo;
  int maximo;
  bool parcial;
};

// función que resuelve el problema
t_sol resolver(vector<int> const &v, int ini, int fin) {
  if (ini == fin)
    return {0, 0, true};
  else if (ini + 1 == fin) {
    if (v[ini] <= v[fin])  // los 2 elems estan parcialmente ordenados
      return {v[ini], v[fin], true};
  } else {
    int mid = (ini + fin) / 2;
    auto iz = resolver(v, ini, mid);
    auto dr = resolver(v, mid + 1, fin);
    if (iz.parcial && dr.parcial && iz.minimo <= dr.minimo &&
        dr.maximo >= iz.maximo) {
      return {0, 0, true};
    } else {
      return {0, 0, false};
    }
  }
  // No se ha llegado a cumplir ninguna condicion => no esta parcialmente orde
  return {0, 0, false};
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int elem;
  vector<int> v;

  cin >> elem;
  if (elem == 0) return false;
 
  while(elem != 0){
    v.push_back(elem);
    cin >> elem;
  }

  resolver(v, 0, v.size() - 1).parcial ? cout << "SI\n" : cout << "NO\n";

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
