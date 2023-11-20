#include <iostream>

using namespace std;

void generaHelados(string prefix, int c, int v) // si caemos en fuerza bruta el problema tiene un 0 
{
    // CASO BASE
    if (c + v == 0) // aqui ya tenemos un helado formado
    {
        cout << prefix << endl;
        return;
    }

    // CASO RECURSIVO
    int k = prefix.size();
    // 1. Empiezo con bola de chocolate
    if (c > 0)
    {
        if (k < 2 || prefix[k - 1] != 'C' || prefix[k - 2] != 'C')
        {
            generaHelados(prefix + "C", c - 1, v);
        }
    }

    // 1. Empie<o con bola de vainilla
    if (v > 0)
    {
        if(k > 2 || prefix[k - 1] != 'V' || prefix[k - 2] != 'V')
        {
            generaHelados(prefix + "V", c, v - 1);
        }
    }

    /*
        es una recursion distinta ya que en vuelta atras tambien hay que pasar informacion
        como por ejemplo en este caso un string que es el que se va a ir formando
    */
}

int main(int argc, char const *argv[])
{

    return 0;
}
