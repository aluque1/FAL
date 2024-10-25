// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(vector<int> const &v, int const k) {
  /*  para la longitud k; calcular numero de intervalos de longitud k tal que la
  cantidad de valores positivos en la mitad izqe es mayor o igual que la
  caltidad de valores positivos en el lado derecho */
  int numIntervalos = 0, dr = 0, iz = 0;
  for (int i = 0; i < k / 2; ++i) {
    if (v[i] > 0) ++iz;
  }
  for (int i = k / 2; i < k; ++i) {
    if (v[i] > 0) ++dr;
  }

  if (iz >= dr) ++numIntervalos;

  for (int i = 1; i <= v.size() - k; ++i) {
    if (v[i - 1] > 0 && iz > 0)  // hemos dejado atras un positivo
      --iz;
    if (v[(i + k) / 2] > 0) { /* el nuevo elem del lado iz es positivo => lado der un positivo menos */
      ++iz;
      if (dr > 0) --dr;
    }
    if (v[i + k - 1] > 0)  // el nuevo elem de lado dr es positivo
      ++dr;

    if (iz >= dr) ++numIntervalos; // NO FUNCIONA
  }

  return numIntervalos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int nElems, k;
  cin >> nElems;
  if (nElems == 0) return false;

  cin >> k;

  vector<int> v(nElems);
  for (int &elem : v) cin >> elem;

  int sol = resolver(v, k);

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
