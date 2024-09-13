#include <iostream>

using namespace std;

// Problema Numero sin uno
// Resuelto en la funcion cambio(int n)

int v[1000000];

/*
    Pre : { 0 <= n <= longitud(v) <= 1000000 }
    Complejidad:
      En ambos casos tenemos un caso base con tiempo cte ya que es un return. En la parte recursiva tenemos un caso cte 
      y otro que es una llamada recursiva con n-1. Por lo tanto, la complejidad es O(n).
    Post : { return ret : sum i : 0 <= i < n : v[i] }
*/

// Buscamos por la izquierda par encontrar la primera temperatura mayor o igual a temp
int seqSearchIz(int i, int temp, int const &num_elems)
{
  if(i == num_elems) return i; // hemos llegado al final del array sin encontrar el elemento
  else{
    if(v[i] >= temp) return i; // hemos encontrado el elemento o una temperatura mayor
    else seqSearchIz(i+1, temp, num_elems); // no se ha encontrado el elemento, seguimos buscando
  }
}

// Buscamos por la derecha para encontrar la ultima temperatura mayor o igual a temp
int seqSearchDr(int i, int temp, int const &num_elems){
  if(i < 0) return num_elems; // hemos llegado al final del array sin encontrar el elemento
  else{
    if(v[i] >= temp) return i; // hemos encontrado el elemento o una temperatura menor
    else seqSearchDr(i-1, temp, num_elems); // no se ha encontrado el elemento, seguimos buscando
  }
}

void resuelveCaso()
{
  int num_elems, temp_obj;
  cin >> num_elems >> temp_obj;
  
  for(int i = 0; i < num_elems; ++i)
    cin >> v[i];
  
  cout << seqSearchIz(0, temp_obj, num_elems) << " " << seqSearchDr(num_elems-1, temp_obj, num_elems) << endl;
}

int main(int argc, char const *argv[])
{
  int num_casos;
  cin >> num_casos;
  for(int i = 0; i < num_casos; ++i)
    resuelveCaso();
  return 0;
}
