// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75
#include <limits.h>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

/*
  Una solucion es valida si:
  1. No hemos cogido ya el producto
  2. No hemos comprado mas de 3 cosas en el super actual
  3. Si cogiendo el articulo i en el supermercado k no nos pasamos del minimo de
  la compra actual
*/
bool es_valida(int k, int i, vector<bool> const &producto_cogido,
               vector<int> &num_compras) {
  if (producto_cogido[k]) return false;
  if (num_compras[i] >= 3) return false;
  return true;
}

// función que resuelve el problema
void resolver(int k, bool &existe_sol, int compra_act, int &compra_min,
              vector<vector<int>> const &productos,
              vector<bool> &producto_cogido, vector<int> &num_compras,
              vector<int> const &sumas) {
  for (int i = 0; i < num_compras.size(); ++i) {
    if (es_valida(k, i, producto_cogido, num_compras)) {
      compra_act += productos[i][k];
      producto_cogido[k] = true;
      ++num_compras[i];

      if (k == producto_cogido.size() - 1) {
        existe_sol = true;
        compra_min = min(compra_act, compra_min);
      } else if (compra_act + sumas[k + 1] < compra_min) {
        resolver(k + 1, existe_sol, compra_act, compra_min, productos,
                 producto_cogido, num_compras, sumas);
      }
      --num_compras[i];
      producto_cogido[k] = false;
      compra_act -= productos[i][k];
    }
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  int num_supermercados, num_productos;
  cin >> num_supermercados >> num_productos;

  bool existe_sol = false;
  int compra_min = 0;
  // Si ya hemos comprado ese producto
  vector<bool> producto_cogido(num_productos, false);
  // numero de compras que se ha hecho en cada supermercado
  vector<int> num_compras(num_supermercados, 0);
  // vector de sumas parciales
  vector<int> sumas(num_productos, INT_MAX);

  vector<vector<int>> productos(num_supermercados, vector<int>(num_productos));
  for (int i = 0; i < num_supermercados; ++i) {
    for (int j = 0; j < num_productos; ++j) {
      cin >> productos[i][j];
      compra_min += productos[i][j];
      sumas[j] = min(sumas[j], productos[i][j]);
    }
  }

  for (int i = sumas.size() - 1; i > 0; --i) sumas[i - 1] += sumas[i];

  if (num_productos > 0)
    resolver(0, existe_sol, 0, compra_min, productos, producto_cogido,
             num_compras, sumas);

  existe_sol ? cout << compra_min << '\n' : cout << "Sin solucion factible\n";
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