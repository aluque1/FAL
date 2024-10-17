// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
/*
Como sabemos cual es el rango de valores que se pueden conseguir vamos a usar un
vector de frecuencia para contar cuantas veces aparece cada numero y con eso generar
nuestro vector de modas
*/
vector<int> resolver(vector<int> const &v, int d)
{
    vector<int> frec(d, 0);
    vector<int> sol;
    int maximo;
    // contamos cuantas veces aparece cada numero
    for (int i = 0; i < v.size(); ++i)
        ++frec[v[i] - 1];

    // encontramos cuanto es el maximo que sale un numero
    maximo = frec[0];
    for (int i = 0; i < frec.size(); ++i)
        maximo = max(maximo, frec[i]);

    // recorremos de derecha a izquerda porque si hay mas de un elem se quieren de mayor a menor
    for (int i = frec.size() - 1; i >= 0; --i)
    {
        if (frec[i] == maximo)
            sol.push_back(i + 1);
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada
    int nElems, max;
    cin >> nElems;
    if (nElems == -1)
        return false;
    cin >> max;

    vector<int> v(nElems);
    for (int &elem : v)
        cin >> elem;

    vector<int> sol = resolver(v, max);

    // escribir sol
    for (int i = 0; i < sol.size(); ++i)
        cout << sol[i] << ' ';
    cout << '\n';
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
