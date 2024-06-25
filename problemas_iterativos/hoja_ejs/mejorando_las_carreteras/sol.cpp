#include <iostream>
#include <algorithm> // para poder usar sort

using namespace std;

int v[10000];

bool resuelve(){
  int n; 
  cin >> n;

  if(n == -1) return false;

  for(int i = 0; i < n; ++i)
    cin >> v[i];
  
  sort(v, v + n); // hace falta hacer sort porque no tenemos acotado el vector =!> se puede hacer vector de frecuencias

  int moda = v[0], curr_times = 1, max_times = 0;

  for(int i = 1; i < n; ++i){
    if(v[i] != v[i - 1])
      curr_times = 1;
    else {
      ++curr_times;
      if(curr_times > max_times){
        max_times = curr_times;
        moda = v[i];
      }
    }
  }

  cout << moda << endl;

  return true;
}

int main(int argc, char const *argv[])
{
  while(resuelve()){}
  return 0;
}
