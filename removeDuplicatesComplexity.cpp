/****************************************************************************************************
 * Program that calls 10 times the algorithms shown in removeDuplicatesCheck doubling the size of 
 * the array on which to perfom the algorithms. This program shows the time that needs each algorithm
 * in each iteration, to show the difference in time that takes between an O(n^2) vs O(n*log n) 
 * performing the same operation. The initial size of the array is 500 elements.
 * 
 * Code by Sergi Magret Goy on 27/12/2018.
 ****************************************************************************************************/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <chrono>
#include "funcions.cpp"

using namespace std;

void mostrarCapcalera(){
    cout << endl << setw(10) << "n" << setw(12) << "O(n^2)" << setw(15) << "O(n log n)" << endl << endl;
    cout << setw(2) << setfill(' ') << " " << setw(44) << setfill('-') << "-" << endl;
}

int main(){
    mostrarCapcalera();
    unsigned n = 500;
    cout << setfill(' ');
    for(int i = 1; i<=10; i++){
        int a[n], b[n];
        emplenarTaula(a, n , n/3);
        unsigned m = 0;

        cout << setw(10) << n;
        chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
            removeDuplicatesNaive(a, n, b, m);
        chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
        chrono::duration<double> time_span = chrono::duration_cast< chrono::duration<double> >(t2 - t1);
        cout << setw(12) << time_span.count();

        chrono::high_resolution_clock::time_point t3 = chrono::high_resolution_clock::now();
            removeDuplicatesDivideAndConquer(a, n, b, m);
        chrono::high_resolution_clock::time_point t4 = chrono::high_resolution_clock::now();
        time_span = chrono::duration_cast< chrono::duration<double> >(t4 - t3);
        cout << setw(15) << time_span.count() << endl;

        n = n*2;

    }
    return 0;
}
