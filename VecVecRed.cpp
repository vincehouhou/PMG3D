/*
 * ************************************************************************
 * File:    VecVecRed.cpp
 * Purpose: Substraction of two vectors
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

double *VecVecRed(double *a, double *b, int n)
{
    int i;
    double *c = new double [n];
    #pragma omp parallel if (n>100) shared (n) private (i)
    {
    #pragma omp for
    for (i=0; i<n; i++){
        c[i] = a[i] - b[i];
    }
    }
    return c;
}
