// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct t_sol {
  bool cruce;
  int pos;
};

// función que resuelve el problema
t_sol resolver(vector<int> const& v1, vector<int> const& v2, int ini, int fin) {
  if (ini == fin) {  // caso base vector unico elemento
    if (v1[ini] == v2[ini]) {
      return {true, ini};
    } else {
      if (v1[ini] > v2[ini]) {
        return {false, ini - 1};
      } else {
        return {false, ini};
      }
    }
  } else {  // caso recursivo
    int mid = (ini + fin) / 2;
    if (v1[mid] < v2[mid]) {
      return resolver(v1, v2, mid + 1, fin);
    } else {
      return resolver(v1, v2, ini, mid);
    }
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int num_elems;
  cin >> num_elems;
  if (num_elems == 0) return false;

  vector<int> v1(num_elems);
  for (int& elem : v1) cin >> elem;

  vector<int> v2(num_elems);
  for (int& elem : v2) cin >> elem;
  /*
    tengo que devolver si se crucan
    SI se crucan, devuelvo SI y las posiciones en las que coinciden los
    vectores NO se crucan, devuelvo no y las posiciones en las que se deberian
    encontrar en valor comun

    SI el cruce se diese antes de los vectores se escribe
      SI -1 0
    SI el crice se diese despues de los vectores se escribe
      SI n-1 n
  */
  t_sol sol = resolver(v1, v2, 0, num_elems - 1);

  // escribir sol
  sol.cruce ? cout << "SI " << sol.pos << '\n'
            : cout << "NO " << sol.pos << ' ' << sol.pos + 1 << '\n';
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
