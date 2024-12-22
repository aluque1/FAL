#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void resuelveCaso()
{
  int numElems;
  cin >> numElems;

  vector<string> v(numElems);

  for (string &i : v)
    cin >> i;

  string min = v[0];

  for(int i = 1; i < numElems; ++i){
    if(min > v[i])
      min = v[i];
  }

  cout << min << '\n';
}

int main()
{
// Para la entrada por fichero .
#ifndef DOMJUDGE
  std ::ifstream in("datos.txt");
  auto cinbuf = std ::cin.rdbuf(in.rdbuf());
#endif

  //Entrada con numero de casos
  int numCasos;
  cin >> numCasos;
  for(int i = 0; i < numCasos; ++i)
    resuelveCaso();
    
// Para restablecer entrada .
#ifndef DOMJUDGE
  std ::cin.rdbuf(cinbuf);
  // system(" PAUSE ");
#endif
  return 0;
}
