/**
 * 201023
 * T(n) = a · T(n/b) + (t1 · n^k)
 * 
 * a < b^k -> O(n^k)
 * a == b^k -> O(n^k log n)
 * a > b^k -> O(n^logb a)
 * 
 */