/*
 * ************************************************************************
 * File:    main.cpp
 * Purpose: Product of a CRS sparse matrix and a vector
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

double *SPMaVecPro(struct CRS *MX, double *p, int n)
{
    int i, j;
    double *q = new double [n];
    #pragma omp parallel if (n>100) shared (n) private (i)
    {
    #pragma omp for
    for (i=0; i<n; i++){
        SPMaVecProNd(MX, q, p, n, i);
    }
    }
    return (q);
}
