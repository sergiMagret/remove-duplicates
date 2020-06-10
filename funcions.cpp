/*************************************************************************************
 * Functions used in the removeDuplicatesCheck and removeDuplicatesComplexity programs.
 * Commented couts are left in purpose in case anybody wants to see the process that 
 * takes place when executing the program.
 *
 * Code by Sergi Magret Goy on 27/12/2018. 
 *************************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

static void mostrarTaulaEntre(int a[], unsigned ini, unsigned final){
//Pre: 0<=ini<=final;
//Post: mostra per pantalla a[ini..final];
    for(unsigned i = ini; i <= final; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

static void mostrarTaula(int a[], unsigned n){
//Pre: a té mida n;
//Post: mostra la taula a per pantalla;
    for(unsigned i = 0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

static void fusio(int a[], unsigned n, int esq, int ini2, int dre){
// Pre: 0<=esq<ini2<=dre<n i a ordenat creixentment de esq a ini2-1 i de ini2 fins dret i a=A
// Post: a[esq..dre] conté una permutació ordenada dels valors de A[esq..dre]

    // Primer es copia a la taula auxiliar, fins a ini2-1 en ordre ascendent
    int aux[dre-esq+1]; // cal taula auxiliar (dret-esq+1 posicions)
    int n_elem = dre-esq+1; int i_aux=0; // indexació d’aux

    //cout << "Before merge, original array: "; mostrarTaulaEntre(a,esq, dre); cout << endl;

    for (int k=esq; k<ini2; k++) {
        aux[i_aux]=a[k]; i_aux++;
    }

    // A partir de ini2 esta en ordre descendent
    for (int k=dre; k>=ini2; k--) { // A l’inrevès
        aux[i_aux]=a[k]; i_aux++;
    }
    //cout << "Before merge, aixiliary array: "; mostrarTaula(aux, n_elem); cout << endl;

    int i = 0, j = n_elem-1, k = esq;

    while (i <= j) { // Recorrem la taula auxiliar,
        if (aux[i] <= aux[j]) { // Volem estable, per tant <=
            a[k] = aux[i];
            i++;
        }else{
            a[k] = aux[j];
            j--;
        }
        k++;
    }
    
    //cout << "After merge, original array: "; mostrarTaulaEntre(a, esq, dre); cout << endl;
    //cout << "After merge, auxiliary array: "; mostrarTaula(aux, n_elem); cout << endl;
}

static void iMergeSort(int a[], unsigned n, int esq, int dre){
// Pre: 0<=esq<=dre<n<=MAX i a=A
// Post: a[esq..dre] conté una permutació ordenada dels valors de A[esq..dre]
    int mig;
    if (esq<dre){
        mig=(esq+dre)/2;
        cout << "1: "; mostrarTaulaEntre(a, esq, dre); cout << endl;
        iMergeSort(a,n,esq,mig);
        cout << "2: "; mostrarTaulaEntre(a, esq, dre); cout << endl;
        iMergeSort(a,n,mig+1,dre);
        cout << "3: "; mostrarTaulaEntre(a, esq, dre); cout << endl;
        fusio(a,n,esq,mig+1,dre);
        cout << "4: "; mostrarTaulaEntre(a, esq, dre); cout << endl;
  }
}


static void mergeSort(int t[], unsigned n){
// pre: t[0..n-1] conté els valors a ordenat
// post: t[0..n-1] està ordenada creixentment
    iMergeSort(t, n, 0, n-1);
}

static void removeDuplicatesNaive(int a[], unsigned n, int b[], unsigned& m){
//Pre:  a  i  b  tenen mida  n  /\  a = A
//Post: b  conté els elements de  A  sense repetits i en el mateix ordre en les  m  primeres posicions;
//cost O(n^2)
    for(unsigned i = 0; i<n; i++){
        int num = a[i];
        unsigned j = 0;
        while(j < m && b[j] != num) j++;
        if(j == m){
            b[m] = num;
            m++;
        }
    }
}

static void removeDuplicatesDivideAndConquer(int a[], unsigned n, int b[], unsigned& m){
//Pre:  a  i  b  tenen mida  n  /\  a = A
//Post: b  conté els elements de  A  sense repetits i en el mateix ordre, en les  m  primeres posicions; 
//cost O(n log n)

    // Busquem el màxim
    int max = -1;
    for(unsigned i = 0; i < n; i++) if(a[i]>max) max = a[i];

    // Creem un vector amb tots els numeros que hi poden haver
    int posicions[max+1];
    for(int i = 0; i <= max; i++) posicions[i]  = -1;

    // Mirem en quin ordre els anem trobant al vector original
    int ordre = 0;
    for(unsigned i = 0; i < n; i++){
        if(posicions[a[i]] == -1){
            posicions[a[i]] = ordre;
            ordre++;
        }
    }

    // Ordenem la taula original
    mergeSort(a, n);

    // Eliminem els repetits i el resultat el posem a una taula auxiliar auxT
    int lastAdded;
    int auxT[n];
    m = 0;
    if(0<n){
        auxT[0] = a[0];
        m++;
        lastAdded = a[0];
    }

    for(unsigned i = 1; i<n; i++){
        if(a[i] != lastAdded){
            auxT[m] = a[i];
            lastAdded = a[i];
            m++;
        }
    }

    // Tornem a posar els elements en el seu ordre original
    for(unsigned i = 0; i<m; i++){
        b[posicions[auxT[i]]] = auxT[i];
    }
}

static void emplenarTaula(int a[], unsigned n, unsigned valorsDiferents){
//Pre: a té mida n;
//Post: a[0..n-1] elements generats aleatoriament entre 0 i valorsDiferents;
    srand(time(NULL));
    for(unsigned i = 0; i<n; i++){
        a[i] = rand() % valorsDiferents;
    }
}
