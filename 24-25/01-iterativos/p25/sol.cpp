// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(vector<int> const& v, int const k) {
  /*  para la longitud k; calcular numero de intervalos de longitud k tal que la
  cantidad de valores positivos en la mitad izqe es mayor o igual que la
  caltidad de valores positivos en el lado derecho */
  int numIntervalos = 0, dr = 0, iz = 0;

  // Iniziamos con el primer intervalo
  for (int i = 0; i < k / 2; ++i) {
    if (v[i] > 0) ++iz;  // si el valor es positivo incrementamos iz
  }

  for (int i = k / 2; i < k; ++i) {
    if (v[i] > 0) ++dr;  // si el valor es positivo incrementamos dr
  }

  if (iz >= dr)
    ++numIntervalos;  // si el intervalo es valido incrementamos el numero de
                      // intervalos

  int i = 1;
  int j = i + k - 1;
  int mid = j / 2;
  while (j < v.size()) {
    if (v[i - 1] > 0 && iz > 0)  // perdemos un numero positivo del intervalo iz
      --iz;
    if (v[mid] > 0) {  // numero que pasa de dr a iz es positivo
      ++iz;
      if (dr > 0) --dr;
    }
    if (v[j] > 0)  // numero que entra en el intervalo dr es positivo
      ++dr;

    if (iz >= dr) ++numIntervalos;

    ++i;
    ++j;
    ++mid;
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
  for (int& elem : v) cin >> elem;

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
