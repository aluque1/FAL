// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(vector<int> const &pesos, int max_viajes, int ini, int fin) {
  if (ini == fin)
    return ini;  // caso base : unico elemento
  else {
    int mitad = (ini + fin) / 2;
    int v = 1;
    int peso_acum = pesos[0];
    for (int i = 1; i < pesos.size(); ++i) {
      if (peso_acum + pesos[i] <= mitad)
        peso_acum += pesos[i];
      else {
        ++v;
        peso_acum = pesos[i];
      }
    }
    if (v <= max_viajes)
      return resolver(pesos, max_viajes, ini, mitad);
    else
      return resolver(pesos, max_viajes, mitad + 1, fin);
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int num_cuadros, max_viajes;
  cin >> num_cuadros >> max_viajes;
  if (num_cuadros == 0 && max_viajes == 0) return false;

  vector<int> pesos(num_cuadros);
  // Es el peso maximo y se usa como ini
  int max_peso = 0;
  int sum_pesos = 0;
  for (int &peso : pesos) {
    cin >> peso;
    max_peso = max(max_peso, peso);
    sum_pesos += peso;
  }
  cout << resolver(pesos, max_viajes, max_peso, sum_pesos) << '\n';
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
