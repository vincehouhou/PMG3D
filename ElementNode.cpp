/*
 * ************************************************************************* 
 * File:    ElementNode.cpp
 * Purpose: Setup the sparse matrix of elements_nodes relationship
 * Author:  Houdong Hu
 * ************************************************************************* */


#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "vincehouhou.h"
#include "types.h"
using namespace std;

int **ElementNode(int **El, int n0)
{
    /*
     *   we use the CSR data structure to store the sparse matrix
     *   E_N store elements-nodes' information
     *   E_N[0][k]: the number of nodes corresponding to each element
     *   E_N[1][k]: the corresponding nodes' serial number of each element
     */
    int n = (n0-1)*(n0-1)*(n0-1)*6, k;
    int **E_N = new int*[2];
    E_N[0] = new int[n+1];
    E_N[1] = new int[4*n];
    for (k=0; k<n; k++){
        E_N[0][k] = 4*k;
        E_N[1][4*k] = El[k][0];
        E_N[1][4*k+1] = El[k][1];
        E_N[1][4*k+2] = El[k][2];
        E_N[1][4*k+3] = El[k][3];
    }
    E_N[0][n] = 4*n;
    return(E_N);
}

