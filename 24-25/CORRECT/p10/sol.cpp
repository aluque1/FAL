// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct tEdificio
{
  string nombre;
  int altura;
  int masAlto = -1; // si no se vende ningun piso es -1
};

vector<string> resolver(const vector<tEdificio> &v)
{
  int maxAltura = -1;
  vector<string> edificiosConVistas;
  // Recorremos el vector de fin a principio
  for (int i = v.size() - 1; i >= 0; --i)
  {
    if (maxAltura < v[i].masAlto)
      edificiosConVistas.push_back(v[i].nombre);
    if (maxAltura < v[i].altura)
      maxAltura = v[i].altura;
  }

  return edificiosConVistas;
}

bool resuelveCaso()
{
  int numCasos;
  cin >> numCasos;
  if (numCasos == 0)
    return false;

  vector<tEdificio> pisosEnVenta(numCasos);

  for (int i = 0; i < numCasos; ++i)
  {
    cin >> pisosEnVenta[i].nombre >> pisosEnVenta[i].altura >> pisosEnVenta[i].masAlto;
  }

  vector<string> sol = resolver(pisosEnVenta);

  // escribir solucion
  sol.size() == 0 ? cout << "Ninguno" : cout << sol.size() << '\n';
  for (int i = 0; i < sol.size(); ++i)
    cout << sol[i] << ' ';
  cout << '\n';

  return true;
}

int main()
{
// Para la entrada por fichero .
#ifndef DOMJUDGE
  std ::ifstream in("datos.txt");
  auto cinbuf = std ::cin.rdbuf(in.rdbuf());
#endif

  // Entrada con centinela
  while (resuelveCaso())
  {
  }

// Para restablecer entrada .
#ifndef DOMJUDGE
  std ::cin.rdbuf(cinbuf);
  // system(" PAUSE ");
#endif
  return 0;
}
