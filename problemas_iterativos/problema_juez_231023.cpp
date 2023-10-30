#include <iostream>
#include <algorithm>

using namespace std;

int v[200000];


/**
 * 0 < n <= longitud(v) ^ ordenado(v) 
 */
long long numParejas(int v[], int n, int k) /* return ret */
{
    int b = n - 1;
    int a = b - 1;
    long long parejas = 0;

    while (b >= 1)
    {
        if (v[a] + v[b] <= k)
        {
            parejas += b;
             --b;
             a = b - 1;
        }
        else if(a == -1)
        {
            --b;
            a = b - 1;
        }
        else
            --a;
    }
    return parejas;
}
/**
 * ret = # i,j : 0 <=i < j < n : v[i] + v[j] <= k  
 */

int main()
{
    int n, k;
    while ((cin >> n >> k) && n)
    {
        for (int i = 0; i < n; i++)
            cin >> v[i];
        cout << numParejas(v, n, k) << endl;
    }
    return 0;
}