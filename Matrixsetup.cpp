/*
 * *************************************************************************
 * File:    Matrixsetup.cpp
 * Purpose: Set up A, for Ax=b
 * Author:  Houdong Hu
 * *************************************************************************
 */

#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "vincehouhou.h"
#include "types.h"
//#include "Timer.cpp"
#ifdef _OPENMP
#include <omp.h>
#endif
using namespace std;

struct CRS *Matrixsetup(double *V, double **No, int **El, int **E_N, int **N_E, int n0, int n1, double h)
{
    int i, k, n = (n0-1)*(n0-1)*(n0-1)*6, nn = n0*n0, nnnn = n0*n0*n0; 
    double *Ve = new double [nnnn], t1, t2;
    #pragma omp parallel if (n>100) shared(nnnn) private(k)
    {
    #pragma omp for
    for (i=0; i<nnnn; i++)
        Ve[i] = 0;
    }
    
    struct CRS *MX;
    t1 = getTime();
    MX = SparseMXsetup(No, El, E_N, N_E, n0, n1, h);
    t2 = getTime();
    int a = (int)(log(n0-1)/log(2));
    #pragma omp parallel if (a>1) shared(n) private(k)
    {
    #pragma omp for
    for (k=0; k<n; k++){ 
        Stiffmatrix(MX, Ve, No, El, n1, k, h);
    }
    }
    t1 = t2;
    t2 = getTime();
    struct CRS *MMX = new struct CRS;
    MMX = SparseMXreduction(MX, Ve, V, n0, nn);
    t1 = t2;
    t2 = getTime();
    return(MMX);
}
