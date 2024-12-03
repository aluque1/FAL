// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// función que resuelve el problema
char resolver(vector<char> const& v, int ini, int fin, char char_ini,
              char char_fin) {
  // caso base: vector unico
  if (ini + 1 == fin) {
    if (v[ini] == char_ini)
      return char_fin;
    else
      return char_ini;
  } else {
    int mid = (ini + fin) / 2;
    char char_mid = (char_ini + char_fin) / 2;
    if(v[mid] > char_mid) return resolver(v, ini, mid, char_ini, char_mid);
    else return resolver(v, mid, fin, char_mid, char_fin);
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  char char_ini, char_fin;
  cin >> char_ini >> char_fin;
  int ascii_fin = char_fin - char_ini;
  vector<char> v(ascii_fin);

  for (char& elem : v) cin >> elem;

  char sol = resolver(v, 0, ascii_fin, char_ini, char_fin);

  cout << sol << '\n';
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