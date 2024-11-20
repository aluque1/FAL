// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(vector<int> const &v, int p, int ini, int fin) {
  if (ini == fin)
    return ini;
  else {
    int mid = (ini + fin) / 2;
    int paradas = 0, aguante = v[0];
    for (int i = 1; i < v.size(); ++i) {
      if(aguante + v[i] <= mid)
        aguante += v[i];
      else{
        ++paradas;
        aguante = v[i];
      }
    }
    if(paradas <= p) return resolver(v, p, ini, mid);
    else return resolver(v, p, mid + 1, fin);
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int n, p;
  cin >> n >> p;
  if (n == 0 && p == 0)
    return false;
  vector<int> v(n);
  int max = 0, sum = 0;
  for (int &elem : v) {
    cin >> elem;
    if (elem > max) 
      max = elem; // El elemento maximo se guarda
    sum += elem;  // Y tambien guardamos la suma
  }

  int sol = resolver(v, p, max, sum);

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
      in.rdbuf()); // save old buf and redirect std::cin to casos.txt
#endif

  while (resuelveCaso())
    ;

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
  std::cin.rdbuf(cinbuf);
  system("PAUSE");
#endif

  return 0;
}
