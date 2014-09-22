/*
 * ************************************************************************
 * File:    VecNumPro.cpp
 * Purpose: Product of a vector and a number
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

double *VecNumPro(double *p, double belta, int n)
{
    double *q = new double [n];
    int i;
    #pragma omp parallel if (n>100) shared (n) private (i)
    {
    #pragma omp for
    for (i=0; i<n; i++)
        q[i] = p[i] * belta;
    }
    return (q);
}
