// { Pre : 0 <= n <= longitud(v) }
int numPares(int v[], int n); /* return ret */
// { Post : ret = # i : 0 <= i < n : v[i] mod 2 = 0} <--- el # se usa para representar el conteo


// { Pre : 0 <= n <= longitud(v) }
bool creciente(int v[], int n); /* return ret */
// { Post : ret = true : P.t. 0 <= i < (n - 1) : v[i] <= v[i+1]}


// b. Ex. w = 0 <= w < n: a[w] = 2*w -----> 

// c. m = # w : 1 <= w < n : a[w-1] < a[w] -----> El numero de elementos del array a[] donde el elemento es mayor que el anterior

// d. m = max u, v : 0 <= u < v < n : a[u] + a[v] -----> Calcular la suma de cualquier pareja de del array y quedarse con la mas grande

// e. p = Prod u, v : 0 <= u < v < n : a[v] - a[u] -----> Coge todas las parejas, las resta y hace el producto de todas las restas

// f. r = max u, v : 0 <= u < v < n : (Sum w : u <= w < v : a[w]) -----> Coge el intervalo que de la suma maxima. Esto no es trivial ya que
//          los elementos del array podrian ser negativos

// g. l = max u, v : (0 <= u < v < n) ^
//                   (P.t. w : u <= w < v : a[w] = 0)
//                 : v - u + 1 -----> Calcular el tramo maximo de 0s consecutivos del array a


// { Pre: 0 <= n <= longitud(v) }
bool bienFormada(int v[], int n); /* return ret */
// { Post: ret = Ex. k : (0 <= k < n)
//                     : todosPares(v, 0, k) ^
//                       todosImpares(v, k, n)
// donde : 
//      todosPares(v, a, b) = P.t i : a <= i < b : v[i] mod 2 = 0 <-----+ nos fijamos que a esta dentro de v[i] mienstras b no lo esta
//      todosImpares(v, a, b) = P.t i : a <= i < b : v[i] mod 2 = 1 <---+   
// }