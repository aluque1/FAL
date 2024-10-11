// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(vector<long long int> &v, int numErroneo) // no lo pasamos como const ya que lo modificamos
{
  int val = 0; /* Nuevo indice que vamos a usar, no se actualiza cuando encontramos un valor erroneo => proximo recorrido reescribimos
              el siguiente numero en la posicion del erroneo */
  for (int i = 0; i < v.size(); ++i)
  {
    if (v[i] != numErroneo)
    {
      v[val] = v[i];
      ++val;
    }
  }

  v.resize(val);
  return v.size();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
  // leer los datos de la entrada
  int numElems;
  int numErroneo;

  cin >> numElems >> numErroneo;

  vector<long long int> v(numElems);

  for (long long int &elem : v)
    cin >> elem;

  int sol = resolver(v, numErroneo);
  // escribir sol

  cout << sol << '\n';
  for (int i = 0; i < v.size(); ++i)
    cout << v[i] << " ";
  cout << '\n';
}

int main()
{
// Para la entrada por fichero.
// Comentar para acepta el reto
#ifndef DOMJUDGE
  std::ifstream in("datos.txt");
  auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std::cin to casos.txt
#endif

  int numCasos;
  std::cin >> numCasos;
  for (int i = 0; i < numCasos; ++i)
    resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
  std::cin.rdbuf(cinbuf);
// system("PAUSE");
#endif

  return 0;
}