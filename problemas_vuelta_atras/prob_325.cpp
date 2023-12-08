#include <iostream>
using namespace std;

// Problema 325 - Helados de cucurucho
// Resuelto en la funcion genera_bolas(string prefix, int c, int v)

// PE - Presentation Error

void genera_helados(string prefix, int c, int v)
{
    // CASO BASE
    //Has to be a space between each helado, no space at the end of the line and ordered alphabetically
    if (c == 0 && v == 0){
        cout << prefix;
    }

    // CASO RECURSIVO
    // 1. Empiezo con bola de chocolate
    if (c > 0)
    {
        genera_helados(prefix + "C", c - 1, v);
    }
    // 1. Empiezo con bola de vainilla
    if (v > 0)
    {
        genera_helados(prefix + "V", c, v - 1);
    }
}

int main(int argc, char const *argv[])
{
    int casos, c, v;
    string prefix;

    cin >> casos;

    for (int i = 0; i < casos; ++i)
    {
        cin >> c >> v;
        if (c + v > 0)
        {
            genera_helados(prefix, c, v);
            if (i != casos - 1)
                cout << "\n";
        }
    }
    return 0;
}
