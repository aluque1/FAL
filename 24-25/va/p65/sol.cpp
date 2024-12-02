// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

using t_matrix = vector<vector<int>>;

bool esValida(vector<int> marca_supermecados, int k, int i,
              vector<bool> marca_productos) {
  if (marca_productos[k]) return false;
  if (marca_supermecados[i] >= 3) return false;
  return true;
}

// función que resuelve el problema
void hacer_compra(t_matrix &precios, vector<int> &marca_supermercados,
                  vector<int> &sum_acum, vector<bool> &marca_productos,
                  int precio, int &precio_min, bool &existe_sol, int k) {
  for (int i = 0; i < marca_supermercados.size(); ++i) {
    if (esValida(marca_supermercados, k, i, marca_productos)) {
      precio += precios[i][k];
      marca_productos[k] = true;
      ++marca_supermercados[i];
      if (k == marca_productos.size() - 1) {
        existe_sol = true;
        precio_min = min(precio, precio_min);
      } else if (precio + sum_acum[k + 1] < precio_min)
        hacer_compra(precios, marca_supermercados, sum_acum, marca_productos,
                     precio, precio_min, existe_sol, k + 1);
      precio -= precios[i][k];
      marca_productos[k] = false;
      --marca_supermercados[i];
    }
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  int num_supermercados, num_productos, precio_min = 0;
  bool existe_sol = false;

  cin >> num_supermercados >> num_productos;

  t_matrix precios(num_supermercados, vector<int>(num_productos));
  vector<int> marca_supermercados(num_supermercados, 0);
  vector<bool> marca_productos(num_productos, false);
  vector<int> sum_acum(num_productos, __INT_MAX__);

  for (int i = 0; i < num_supermercados; ++i) {
    for (int j = 0; j < num_productos; ++j) {
      cin >> precios[i][j];
      precio_min += precios[i][j];
      sum_acum[j] = min(sum_acum[j], precios[i][j]);
    }
  }

  for (int i = sum_acum.size() - 1; i > 0; --i) sum_acum[i - 1] += sum_acum[i];

  if (num_productos > 0)
    hacer_compra(precios, marca_supermercados, sum_acum, marca_productos, 0,
                 precio_min, existe_sol, 0);

  // escribir sol
  existe_sol ? cout << precio_min << '\n' : cout << "Sin solucion factible\n";
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
  //system("PAUSE");
#endif

  return 0;
}
