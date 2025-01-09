// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

bool resolver(vector<int> const &v, int p){
  int max = v[0], i;
  for(i = 1; i <= p; ++i)
    if(max < v[i]) max = v[i];      // cogemos el maximo antes del punto p

  while(i < v.size() && v[i] > max) // mientras no hayamos recorrido todo el vecctor y no haya un numero menor
    ++i;

  return i == v.size();             // va a devolver true si hemos llegado al final del vector => P.t v[i] p < i < v.size()  
}

void resuelveCaso()
{
  int numElems, point;
  cin >> numElems >> point;

  vector<int> v(numElems);
  for(int& i: v)
    cin >> i;

  bool sol = resolver(v, point);

  sol ? cout << "SI\n" : cout << "NO\n";
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
