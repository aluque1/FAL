// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

struct sol {
  int num;
  int pot;
};

// función que resuelve el problema
pair<int, sol> resolver(int n) {
  if (n < 10)
    return {9 - n, {9 - n, 1}};
  else {
    pair<int, sol> s = resolver(n / 10);
    s.second.pot *= 10;
    s.second.num = s.second.num + (9 - (n % 10)) * s.second.pot;
    return {s.first * 10 + 9 - (n % 10), s.second};
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  int n;
  cin >> n;
  pair<int, sol> s = resolver(n);
  // escribir sol
  cout << s.first << ' ' << s.second.num << '\n';
}

int main() {
// Para la entrada por fichero.
// Comentar para acepta el reto
#ifndef DOMJUDGE
  std::ifstream in("datos.txt");
  auto cinbuf = std::cin.rdbuf(
      in.rdbuf()); // save old buf and redirect std::cin to casos.txt
#endif

  int numCasos;
  std::cin >> numCasos;
  for (int i = 0; i < numCasos; ++i)
    resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
  std::cin.rdbuf(cinbuf);
  system("PAUSE");
#endif

  return 0;
}