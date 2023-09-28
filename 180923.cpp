#include <iostream>

using namespace std;

// Ejercicio 266 copistas daltonicos

/*  
    En este problema la complejidad es mas complicado que un simplre O(n) ya que tienes el tamaño de x,
    el tamaño de y y el numero de copistas (tx, ty, nc)
    
    Esto es porque tenemos una matriz x * y => la complejidad seria O(nc · tx · ty) pero no nos sirve porque nc 
    podria ser un millon lo que haria que todo se fuese a la mierda

    lo suyo seria tener un algoritmo con O(nc + tx · ty)
*/

// Especificacion de algoritmos. 

/* Ejemplo 1 en lenguaje natural */

// Precondicion: El numero n no puede ser negativo
int esPar(int n);
// Postcondicion: Devuelve true si n es par

/* Ejemplo 1 en lenguaje logico */

// { Pre: n >= 0 }
int esPar(int n); /* return ret */
// { Post: ret = !(n & 1) }

/* Ejemplo 2 */

// { Pre: 0 < n <= longitud(v) }
int min(int n, int v[]); /* return ret */
// { Post: ret = P.t. i : 0 <= i < n : }

/* 
{ Pre: 
        0 < n <= longitud(v) ^ 
        P.t. i : 0 <= i < n - 1: v[i] <= v[i+1] 
} usar P.t. para todo 
*/
int minFacil(int n, int v[]); /* return ret */ // el array esta crecientemente ordenado

/* 
{ Pre:
        0 <= n <= longitud(v)
    
} */
bool hayCeros(int n, int v[]); /* return ret */
/* 
{ Post: 
        ret = Ex. i : 0 <= i < n : v[i] = 0
} */


int sumaTodo(int n, int v[]); /* return ret */
/* 
{ Post: 
        ret = Prod :   0 <= i < n : v[i]
} */