/*
 * ************************************************************************* 
 * File:    Transpose.cpp
 * Purpose: Transpose the sparse matrix in CSR data structure
 * ************************************************************************* */

#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "vincehouhou.h"
#include "types.h"
using namespace std;

int **Transpose(int **E_N, int n0)
{
    /*
     *   E_N are the orginal sparse matrix information
     *   N_E are the sparse matrix information after transposing
     *   test has the information about the number of non_zero elements for each row of the transposed matrix
     *   count is used to count how many non_zero elements have been found for each row of the transposed matrix
     */
    int n = (n0-1)*(n0-1)*(n0-1)*6, nn = n0*n0*n0, k, l, m;
    int *test = new int[nn];
    int *count = new int[nn];
    int **N_E = new int*[2];
    N_E[0] = new int[nn+1];
    N_E[1] = new int[4*n];
    for (k=0; k<nn; k++){
        test[k] = 0;
        count[k] = 0;
    }
    for (k=0; k<4*n; k++){
        test[E_N[1][k]]++;
    }
    /*
     go over to find text
     */
    N_E[0][0] = 0;
    for (k=1; k<nn+1; k++){
        N_E[0][k] = N_E[0][k-1] + test[k-1];
    }   
    /*
     get N_E[0][k] (the number of elements corresponding to each node)  based on test
     */
    for (k=0; k<n; k++)
        for (l=E_N[0][k]; l<E_N[0][k+1]; l++){
            m = N_E[0][E_N[1][l]] + count[E_N[1][l]];
            count[E_N[1][l]]++;
            N_E[1][m] = k;
    }
    /*
     get N_E[1][k] (the corresponding elements' serial number of each node) based on N_E[0][k], E_N[0][k], E_N[1][k], count
     */
    return(N_E);
}
