// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <fstream>
#include <iostream>

using namespace std;

// función que resuelve el problema
int resolver(int n) {
  if(n < 10) // Caso base
    return n;
  else // caso recursivo
    return resolver(n/10) + n % 10;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  int num, numero;
  cin >> num >> numero;
  int suma = resolver(numero);
  for (int i = 0; i < num; ++i)
  {
    cin >> numero;
    if(resolver(numero) == suma) cout << numero << ' ';
  }
  cout << '\n';
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