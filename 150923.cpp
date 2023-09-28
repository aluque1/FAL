
#include <iostream>

using namespace std;

// Ejercicio 242 Erasmus
// resuelto en la funcion erasmus(int v[], int n)

int v[100000]; // para FAL declaramos el vector como variable global para que no de error de compilacion por exceso de memoria


long long erasmus(int n, int v[]){
    long long ret = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i+1; j < n ; ++j)
        {
            ret += v[i] * v[j];
        }
        
    }
    


    return ret;
}


bool resuelve(){
    //1. Lectura
    int n; 
    cin >>n;
    if (n == 0)
    {
        return false;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    
    //2. Calculo
    long long ret = erasmus(n, v);

    //3. Escribir el resultado
    cout << ret << endl;
    return true;
}

int main(int argc, char const *argv[])
{
    while (resuelve())
    {
        ;
    }
    
    return 0;
}



