#include <iostream>

using namespace std;

int v[200000];

bool resuelve()
{
  int num_total, num_pag;
  cin >> num_total >> num_pag;
  if(num_pag == 0 && num_total == 0) return false;

  int sum_act = 0, sum_max = 0, pg_ini = 0;

  for(int i = 0; i < num_total; ++i)
    cin >> v[i];
  
  // bucle de inicializacion de intervalo
  for(int i = 0; i < num_pag; ++i)
    sum_act += v[i];

  sum_max = sum_act;

  // bucle de desplazamiento de intervalo
  for(int i = 0; i < (num_total - num_pag); ++i)
  {
    sum_act -= v[i];
    sum_act += v[i + num_pag];
    if(sum_act >= sum_max)
    {
      sum_max = sum_act;
      pg_ini = i;
    }
  }
  
  cout << pg_ini + 1 << endl;
  return true;
}

int main(int argc, char const *argv[])
{
  while(resuelve()){}

  return 0;
}