// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct sol {
  bool interesante;
  int sumIz;
};

// función que resuelve el problema
sol resolver(int n, int sumDr) {
  // caso base
  if (n < 10) {
    if (n == 0) // si tiene un 10 ya no es interesante
      return {false, 0};
    else if (sumDr % n != 0) // la suma por la derecha es no divisible por n
      return {false, 0};
    else
      return {true, n};
  }
  // caso recursivo
  else {
    if (sumDr % (n % 10)) // si la suma por la derecha no es divisible por n
      return {false, 0};

    sol s = resolver(n / 10, sumDr + (n % 10)); // llamamos recursivamente
    if (!s.interesante)
      return {false, 0};
    else if (s.sumIz % (n % 10) != 0) // Si la suma por la izquierda no es divisible por n
      return {false, 0};
    else 
      return {true, s.sumIz + (n % 10)};
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  int n;
  cin >> n;

  sol s = resolver(n, 0);
  // escribir sol
  s.interesante ? cout << "SI\n" : cout << "NO\n";
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