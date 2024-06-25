#include <iostream>

using namespace std;

int v[1000000];

int tramoMasCorto(int n, int k){
  int i = 0, j = 0, sum = 0, tramoMin = n + 1, tramoAct;

  while(i < n && j < n){
    if(sum < k){
      sum += v[i];
      ++tramoAct;
      ++i;
    } else if(sum > k){
      sum -= v[j];
      --tramoAct;
      ++j;
    } else {
      if(tramoAct < tramoMin) tramoMin = tramoAct;
      tramoAct = 1;
      sum -= v[j];
      ++j;
    }
  }
  return tramoMin;
}

bool resuelveCaso(){
  int n, k;
  cin >> n;
  if(n == -1) return false;

  for(int i = 0; i < n; ++i)
    cin >> v[i];
  cin >> k;

  cout << tramoMasCorto(n, k) << endl;

  return true;
}

int main(){
  while(resuelveCaso()){}
  return 0;
}