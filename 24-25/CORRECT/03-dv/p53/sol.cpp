// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// función que resuelve el problema
int resolver(vector<int> const &v, int ini, int fin, int num_elems) {
  if(ini == fin - 1) return v[ini];
  else{
    int mid = (ini + fin) / 2;
    int iz = resolver(v, ini, mid, num_elems);
    int dr = resolver(v, mid, fin, num_elems);
    int result = -1;
    if(iz == dr) result = iz;
    else {
      int cont_iz = 0;
      int cont_dr = 0;
      for(int i = ini; i < fin; ++i){
        if(v[i] == iz)
          ++cont_iz;
        else if(v[i] == dr)
          ++cont_dr;
      }
      if(cont_iz > num_elems / 2) result = iz;
      else if(cont_dr > num_elems / 2) result = dr;
    }
    return result;
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  vector<int> v;
  int elem;
  cin >> elem;
  while(elem != 0){
    v.push_back(elem);
    cin >> elem;
  }
  if(v.size() == 0) cout << "NO\n";
  else {
    sort(v.begin(), v.end());
    int sol = resolver(v, 0, v.size(), v.size());
    sol == -1 ? cout << "NO\n" : cout << sol << '\n';
  }
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