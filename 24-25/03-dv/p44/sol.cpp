// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(vector<int> const& v, int ini, int fin, int num_cantado) {
  if (ini + 1 == fin) {  // vector unico elemento
    if (ini + num_cantado == v[ini])
      return v[ini];
    else
      return -1;
  } else {
    int mid = (ini + fin) / 2;
    if (v[mid] > mid + num_cantado)
      return resolver(v, ini, mid, num_cantado);
    else
      return resolver(v, mid, fin, num_cantado);
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  int num_carton, num_cantado;
  cin >> num_carton >> num_cantado;
  vector<int> v(num_carton);

  for (int& elem : v) cin >> elem;

  int sol = resolver(v, 0, v.size(), num_cantado);

  // escribir sol
  sol != -1 ? cout << sol << '\n' : cout << "NO\n";
}

int main() {
// Para la entrada por fichero.
// Comentar para acepta el reto
#ifndef DOMJUDGE
  std::ifstream in("datos.txt");
  auto cinbuf = std::cin.rdbuf(
      in.rdbuf());  // save old buf and redirect std::cin to casos.txt
#endif

  int numCasos;
  std::cin >> numCasos;
  for (int i = 0; i < numCasos; ++i) resuelveCaso();

  // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE  // para dejar todo como estaba al principio
  std::cin.rdbuf(cinbuf);
  system("PAUSE");
#endif

  return 0;
}