/*
 * ************************************************************************* *
 * File:    GaussEli.cpp
 * Purpose: Conduct Gauss elimination
 * Author:  Houdong Hu
 * ************************************************************************* */

#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "vincehouhou.h"
#include "types.h"
#include <omp.h>
using namespace std;

double *GaussEli(struct CRS *M, double *r, int n)
{
    int i, j;
    struct CRS *MT;
    MT = TransposeSPMX(M, n);
    #pragma omp parallel if (n>100) shared (n) private (i)
    {
    #pragma omp for
    for (i=0; i<n; i++){
        GaussEliNd1(MT, r, i);    
    }
    }
    #pragma omp parallel if (n>100) shared (n) private (i)
    {
    #pragma omp for
    for (i=0; i<n; i++){
        GaussEliNd2(MT, r, i);
    }
    }
    return (r);
}
