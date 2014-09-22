/*
 * ************************************************************************
 * File:    TransposeSPMX.cpp
 * Purpose: Transpose of a CRS sparse matrix
 * Author:  Houdong Hu
 * ************************************************************************
 */

#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "vincehouhou.h"
#include "types.h"
#include <omp.h>
using namespace std;

struct CRS *TransposeSPMX(struct CRS *M, int n)
{
    int i, j;//, test[n], count[n];
    int *test = new int [n];
    int *count = new int [n];
    //#pragma omp parallel if (n>100) shared (n) private (i)
    //{
    //#pragma omp for
    for (i=0; i<n; i++){
        test[i] = 0;
        count[i] = 0;
    }
    //} 
   // #pragma omp parallel if (n>100) shared (n) private (i)
   // {
    //#pragma omp for
    for (i=0; i<n; i++){
        TransposeSPMXNd1(M, test, i);
    }
   // }
    int *M1 = new int [n+1];
    M1[0] = 1;
    for (i=1; i<=n; i++){
        M1[i] = M1[i-1]+test[i-1];
    }
    int *M2 = new int [M1[n]];
    double *M3 = new double [M1[n]];
    M2[0] = M1[n]-1;
    M3[0] = M1[n]-1;
   // #pragma omp parallel if (n>100) shared (n) private (i)
  //  {
  //  #pragma omp for
    for (i=0; i<n; i++){
        TransposeSPMXNd2(M, M1, M2, M3, i, count);
    }
  //  }
    struct CRS *MT = new struct CRS;
    MT->row = M1;
    MT->column = M2;
    MT->value = M3;
    return (MT);
}
