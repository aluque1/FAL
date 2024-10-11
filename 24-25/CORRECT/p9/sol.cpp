// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
void resolver(vector<int> const &v, vector<long long int> &acum)
{
  acum[0] = 0; // En el primer año no hay nada que acumular

  for (int i = 1; i < acum.size(); ++i)
    acum[i] = acum[i - 1] + v[i - 1];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
  // leer los datos de la entrada
  int ini, fin;
  cin >> ini >> fin;

  if (ini == 0 && fin == 0)
    return false;

  int numElems = fin - ini + 1;
  vector<int> v(numElems);
  for (int &elem : v)
    cin >> elem;

  vector<long long int> acum(v.size() + 1);
  resolver(v, acum);

  // escribir sol
  int numQ;
  cin >> numQ;
  for(int i = 0; i < numQ; ++i){
    int fIni, fFin;
    cin >> fIni >> fFin;
    cout << acum[fFin - ini + 1] - acum[fIni - ini] << '\n';
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
  // system("PAUSE");
#endif

  return 0;
}
