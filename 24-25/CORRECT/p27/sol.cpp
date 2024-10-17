// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
void resolver(vector<int> const &v, int &suma, int &ini, int &longitud)
{
    int sumaMax = 0, sumaAct = 0;
    int maxIni = 0, maxFin = 0, actIni = 0, actFin = 0;

    for (int i = 0; i < v.size(); ++i)
    {
        sumaAct += v[i];
        if (sumaAct <= 0) // no nos importa si la suma de la secuencia es <= 0
        {
            sumaAct = 0;
            actIni = i + 1;
        }
        else
        {
            actFin = i;
            if (sumaAct > sumaMax) // si mejoramos la suma la guardamos
            {
                sumaMax = sumaAct;
                maxFin = i;
                maxIni = actIni;
            }
            else if(sumaAct == sumaMax) // si es equivalente
            {
                if (actFin - actIni < maxFin - maxIni) // nos quedamos con la mas corta
                {
                    maxIni = actIni;
                    maxFin = actFin;
                }
            }
        }
    }
    suma = sumaMax;
    ini = maxIni;
    longitud = maxFin - maxIni + 1;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada
    int nElems;
    cin >> nElems;
    if (!std::cin)
        return false;

    vector<int> v(nElems);
    for (int &elem : v)
        cin >> elem;

    int suma, ini, longitud;

    resolver(v, suma, ini, longitud);

    // escribir sol
    cout << suma << ' ' << ini << ' ' << longitud << '\n';

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