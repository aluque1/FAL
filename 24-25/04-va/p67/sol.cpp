// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75
#include <limits.h>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int estimar(vector<pair<int, int>> const &objetos, int const presupuesto, int k,
            int precio) {
  int i = k + 1;
  int suma = precio;
  int superficie_posible = 0;

  while (i < objetos.size() && suma + objetos[i].first <= presupuesto) {
    suma += objetos[i].first;
    superficie_posible += objetos[i].second;
    ++i;
  }

  // Si no hemos llegado al final de los objetos y no hemos superado el
  // presupuesto, calculamos la superficie posible
  if (i < objetos.size() && suma < presupuesto) {
    superficie_posible +=
        (presupuesto - suma) * objetos[i].second / objetos[i].first;
  }

  return superficie_posible;
}

// función que resuelve el problema
void resolver(int k, vector<pair<int, int>> const &objetos,
              int const presupuesto, int &precio, int &superficie_max,
              int &superficie_act) {
  // Cogemos el objeto que estamos planteando (k)
  precio += objetos[k].first;
  superficie_act += objetos[k].second;
  if (precio <= presupuesto) {
    if (k == objetos.size() - 1)
      superficie_max = max(superficie_act, superficie_max);
    else
      resolver(k + 1, objetos, presupuesto, precio, superficie_max,
               superficie_act);
  }
  precio -= objetos[k].first;
  superficie_act -= objetos[k].second;

  // no cogemos el objeto que estamos planteando (k)
  if (k == objetos.size() - 1)
    superficie_max = max(superficie_act, superficie_max);
  else if (estimar(objetos, presupuesto, k, precio) +
               superficie_act >= superficie_max)
    resolver(k + 1, objetos, presupuesto, precio, superficie_max,
             superficie_act);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int num_objetos, presupuesto;
  cin >> num_objetos >> presupuesto;
  if (!std::cin) return false;

  vector<pair<int, int>> objetos(num_objetos, {0, 0});
  int coste;
  int superficie;
  for (int i = 0; i < num_objetos; ++i) {
    cin >> coste >> superficie;
    objetos[i] = {coste, superficie};
  }

  int precio = 0, superficie_max = 0, superficie_act = 0;
  // Inizializamos la superficie maxima a una solucion posible
  int i = 0;
  while (i < objetos.size() && precio + objetos[i].first <= presupuesto) {
    precio += objetos[i].first;
    superficie_max += objetos[i].second;
    ++i;
  }
  precio = 0;  // volvemos a inicializar el precio

  resolver(0, objetos, presupuesto, precio, superficie_max, superficie_act);
  // escribir sol
  cout << superficie_max << '\n';

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