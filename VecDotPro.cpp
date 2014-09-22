/*
 * ************************************************************************
 * File:    VecDotPro.cpp
 * Purpose: Dot product of two vectors
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

double VecDotPro(double *a, double *b, int n)
{
    int i;
    double c = 0;
    #pragma omp parallel if (n>100) shared (n) private (i)
    {
    #pragma omp for reduction(+:c) 
    for (i=0; i<n; i++){
        c += a[i] * b[i];
    }
    }
    return c;
}

