/*********************************************************************************************************
 * Program that removes the duplicates in an array, leaving the array in the same order but with only one
 * copy of each number, that means the result of both algorithms keeps only the first copy of each number.
 * 
 * The program takes as input the size of the array and a maximum value for the random numbers generated
 * (0..n-1).
 * 
 * Example: array of size 10, 5 differents values.
 * The array is filled and the result for example is: [0, 2, 4, 2, 3, 4, 1, 4, 2, 3].
 * Then the output of both alrothms is: [0, 2, 4, 3, 1].
 *
 * Code by Sergi Magret Goy on 27/12/2018.
 ********************************************************************************************************* */

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "funcions.cpp"

using namespace std;

int main(){
    cout << "Program to check the correct behaviour of the two alorithms:" << endl;
    cout << "1. Remove duplicates from an array full of integers with O(n^2)" << endl;
    cout << "2. Remove duplicates from an array full of integers with O(n*log n)" << endl;
    cout << "Size of the array: "; unsigned n; cin >> n;
    cout << "Number of differents values:"; unsigned valorsDiferens; cin >> valorsDiferens;
    cout << "Generating " << n << " random values from 0 to " << valorsDiferents-1 << "..." << endl;

    int a[n];
    int b[n];
    emplenarTaula(a, n, valorsDiferents);
    cout << "Original array:" << endl;
    mostrarTaula(a, n);

    cout << "Output of the 1st alrotithm O(n^2):" << endl;
    unsigned m = 0;
    removeDuplicatesNaive(a, n ,b, m);
    mostrarTaula(b, m);

    cout << endl << "Result of the 2nd algorithm O(n*log n):" << endl;

    m = 0;
    removeDuplicatesDivideAndConquer(a, n, b, m);
    mostrarTaula(b, m);


    return 0;
}
