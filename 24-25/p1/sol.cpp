#include <iostream>
#include <fstream>

using namespace std;

void resuelveCaso()
{
  int n;
  int max, numVeces = 0;

  cin >> n; // cogemos el primer numero
  max = n;  // igualamos max al primer numero que encontramos
  while (n != 0)
  {
    if (n > max)
    {
      max = n;
      numVeces = 1;
    }
    else if (max == n)
      ++numVeces;

    cin >> n;
  }

  cout << max << ' ' << numVeces << '\n';
}

int main()
{
// Para la entrada por fichero .
#ifndef DOMJUDGE
  std ::ifstream in("datos.txt");
  auto cinbuf = std ::cin.rdbuf(in.rdbuf());
#endif
  // Entrada con numero de casos
  int numCasos;
  std ::cin >> numCasos;
  for (int i = 0; i < numCasos; ++i)
    resuelveCaso();
// Para restablecer entrada .
#ifndef DOMJUDGE
  std ::cin.rdbuf(cinbuf);
  system(" PAUSE ");
#endif
  return 0;
}
