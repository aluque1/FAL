// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct t_sol {
  int long_max = 0;
  int num_llanos = 0;
  vector<int> ini;
};

// función que resuelve el problema
t_sol resolver(vector<int> const& alturas, int longitud) {
  t_sol sol;
  int long_act = 1;
  int altura_max = alturas[alturas.size() - 1];
  for (int i = alturas.size() - 2; i >= 0; --i) {
    // Si el numero actual es igual al anterior y tenemos vistas
    if (alturas[i] == alturas[i + 1] && alturas[i] >= altura_max) {
      ++long_act;
      // Hemos llegado a la longitud minima asi que guardamos el ini del tramo
      if (long_act == longitud) sol.ini.push_back(i + (longitud - 1));
    } else
      long_act = 1;
    // Si la longitud actual es mayor que la longitud minima, cogemos el maximo
    if (long_act >= longitud) sol.long_max = max(long_act, sol.long_max);
    // Si tenemos una nueva altura maxima la guardamos
    altura_max = max(alturas[i], altura_max);
  }
  sol.num_llanos = sol.ini.size();
  return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int num_elems, longitud;
  cin >> num_elems >> longitud;
  if (!std::cin) return false;

  vector<int> alturas(num_elems);

  for (int& alt : alturas) cin >> alt;

  t_sol sol = resolver(alturas, longitud);

  // escribir sol
  cout << sol.long_max << ' ' << sol.num_llanos << ' ';
  for (int elem : sol.ini) cout << elem << ' ';

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