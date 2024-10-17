// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
/* 
El coste de la funcion resuelve es O(n) ya que se hace una suma acumulada de los
elementos del vector de derecha a izquierda 
*/
vector<long long int> resolver(vector<int> const &v)
{
  vector<long long int> sol(v.size() + 1, 0);
  for (int i = v.size() - 1; i >= 0; --i)
    sol[i] += sol[i + 1] + v[i];

  return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
  // leer los datos de la entrada
  int etapas, consultas;
  cin >> etapas;
  if (etapas == -1)
    return false;

  vector<int> km(etapas);
  for (int &elem : km)
    cin >> elem;

  cin >> consultas;
  vector<int> dias(consultas);
  for (int &elem : dias)
    cin >> elem;

  vector<long long int> sol = resolver(km);

  // escribir sol
  for (int i = 0; i < dias.size(); ++i)
  {
    cout << sol[dias[i] - 1] << '\n';
  }
  cout << "---\n";

  return true;
}

int main()
{
// Para la entrada por fichero.
// Comentar para acepta el reto
#ifndef DOMJUDGE
  std::ifstream in("datos.txt");
  auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std::cin to casos.txt
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
