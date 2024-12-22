// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// función que resuelve el problema
int resolver(vector<int> const &v)
{
    int max = 0;
    int curr = 1;
    int moda = v[0];
    for (int i = 1; i < v.size(); ++i)
    {
        if (v[i - 1] == v[i])
        {
            ++curr;
            if (curr > max) // > porque queremos el primero que pase
            {
                max = curr;
                moda = v[i];
            }
        }
        else
            curr = 1;
    }
    return moda;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada
    int nElems;
    cin >> nElems;
    if (nElems == -1)
        return false;

    vector<int> v(nElems);
    for (int &elem : v)
        cin >> elem;

    sort(v.begin(), v.end());

    // escribir sol
    cout << resolver(v) << '\n';

    return true;
}

int main()
{
// Para la entrada por fichero.
// Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso())
        ;

        // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
