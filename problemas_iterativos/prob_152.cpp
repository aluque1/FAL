#include <iostream>

using namespace std;

// Ejercicio 152 Va de modas...
// Resuelto en la funcion modas()

const int MAX = 10;
int numApariciones[MAX];

void resuelve_caso(int n){
  int num = 0;
  int moda = 0;
  for(int i = 0; i < n; ++i){
    cin >> num;
    numApariciones[num]++;
  }
  for (int i = 0; i < MAX; i++)
  {
    if (numApariciones[i] > numApariciones[moda])
    {
      moda = i;
    }
  }
  cout << moda << "\n";
}

int main()
{
  int n;
  while ((cin >> n) && n)
  {
    for (int i = 0; i < MAX; i++)
    {
      numApariciones[i] = 0;
    }
    resuelve_caso(n);
  }
  
}